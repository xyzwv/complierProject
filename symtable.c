/*
 * symtable.c - �� token�� ���� ���
 * programmer - �迹��(2176082), ��ä��(2076216), ����ȭ(2271035), ���Ͽ�(2071033)
 * date - 2024-04-29
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "glob.h"
#include "tn.h"

#define STsize 1000 // size of string table 
#define HTsize 100 // size of hash table

#define FALSE 0
#define TRUE 1

#define MAX_ID_LEN 12 // maximum length for an identifier

typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int index; // index of identifier in ST
    HTpointer next; // pointer to next identifier 
} HTentry;

HTpointer HT[HTsize]; // Array of list head of hashtable 
char ST[STsize]; // Array of string table

int nextid = 0; // the current identifier
int nextfree = 0; // the next available index of ST

int hashcode; // hash code of identifier
int sameid;  // first index of identifier

int found; // for the previous ocurrence of a idntifier

int stidx = 0; // index of identifier in String Table

int isOverst = 0; // for overflow error

// Read ID - Read identifier from fileInput file and append it into the string table ST.
//           An identifier is a string of letters and digits, starting with a letter.
//           If first letter is digit, print out error message.
void ReadID() {
    // Check if the identifier fits within the string table
    if (nextfree + yyleng < STsize) {
        // Update indices
        nextid = nextfree;
        // Copy the identifier to the string table
        for (int i = 0; i < yyleng; i++) {
            ST[nextfree++] = yytext[i];
        }
    }
    else {
        isOverst = 1;
    }
}

// Compute HS - Compute the hash code of identifier by summing the ordinal values
//              of its characters and the taking the sum modulo the size of HT.
void ComputeHS(int nid, int nfree) {
    int code, i;
    code = 0; // identifier�� �ƽ�Ű�ڵ��� ��
    for (i = nid; i < nfree - 1; i++) {
        code += (int)ST[i];
    }
    hashcode = code % HTsize; // (�ƽ�Ű�ڵ� ��) mod (hash table ũ��) -> hashcode
}

// Lookup HS - For each identifier, look it up in the hash table for previous occurrence of
//             the identifier. If find a match, set the found flag as true. Otherwise false.
//             If find a match, save the starting index of ST in same id.
void LookupHS(int nid, int hscode) {
    HTpointer here;
    int i, j;
    found = FALSE; // �̹� HT�� �����ϴ� identifier�� ��� TRUE, �ƴϸ� FALSE

    // ���ο� identifier�� hash table�� ����� index(��ġ)�� ������� ������
    if (HT[hscode] != NULL) {
        here = HT[hscode];
        // while loop�� ���鼭 �̹� �����ϴ� identifier���� üũ
        while (here != NULL && found == FALSE) {
            found = TRUE;
            i = here->index; // HT[hscode]���� index �κп� ���� ��
            j = nid; // identifier�� ���� �κ��� index
            sameid = i;
            // identifier�� �������� üũ
            while (ST[i] != '\0' && ST[j] != '\0' && found == TRUE) { // identifier�� �ѱ��ھ� ������ ��
                if (ST[i] != ST[j])
                    found = FALSE;
                else {
                    i++;
                    j++;
                }
            }
            here = here->next; // ���Ḯ��Ʈ���� ���� ĭ���� �̵��ϸ� üũ
        }
    }
}

// Add HT - Add a new identifier to the hash table.
//          If list head HT[hashcode] is null, simply add a list element with
//          starting index of the identifier in ST.
//          If list head HT[hashcode] is not null, add a new identifier to the head of the chain.
void AddHT(int hscode) {
    HTpointer ptr;

    ptr = (HTpointer)malloc(sizeof(ptr));
    ptr->index = nextid;
    ptr->next = HT[hscode];
    HT[hscode] = ptr;
}

// symbolTable - Read the identifier from the file and directly append it into ST.
//               Compute its hash code and look up the identifier in hash table HT[hashcode].
//               Update stidx(index in String Table).
void symbolTable() {
    int i;
    ReadID(); // identifier ����
    ST[nextfree++] = '\0';

    ComputeHS(nextid, nextfree); // identifier�� hashcode ��� -> hscode
    LookupHS(nextid, hashcode); // hash table�� �̹� �����ϴ� idetifier���� üũ -> found, sameid

    if (!found) { // ó�� �Էµ� identifier��� (hash table�� �̹� �����ϴ� idetifier�� �ƴ϶��)
        stidx = nextid;
        AddHT(hashcode);
    }
    else { // hash table�� �̹� �����ϴ� idetifier���
        stidx = sameid;
        nextfree = nextid;
    }
}