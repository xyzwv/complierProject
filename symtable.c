/*
 * symtable.c - 각 token에 대한 출력
 * programmer - 김예지(2176082), 송채원(2076216), 신정화(2271035), 윤하영(2071033)
 * date - 2024-04-29
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "glob.h"
#include "tn.h"

#define FALSE 0
#define TRUE 1

#define MAX_ID_LEN 12 // maximum length for an identifier

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
    code = 0; // identifier의 아스키코드의 합
    for (i = nid; i < nfree - 1; i++) {
        code += (int)ST[i];
    }
    hashcode = code % HTsize; // (아스키코드 합) mod (hash table 크기) -> hashcode
}

// Lookup HS - For each identifier, look it up in the hash table for previous occurrence of
//             the identifier. If find a match, set the found flag as true. Otherwise false.
//             If find a match, save the starting index of ST in same id.
void LookupHS(int nid, int hscode) {
    HTentry* here;
    int i, j;
    found = FALSE; // 이미 HT에 존재하는 identifier인 경우 TRUE, 아니면 FALSE

    // 새로운 identifier가 hash table에 저장될 index(위치)가 비어있지 않으면
    if (HT[hscode] != NULL) {
        here = HT[hscode];
        // while loop를 돌면서 이미 존재하는 identifier인지 체크
        while (here != NULL && found == FALSE) {
            found = TRUE;
            i = here->index; // HT[hscode]에서 index 부분에 적힌 값
            j = nid; // identifier의 시작 부분의 index
            sameid = i;
            // identifier와 동일한지 체크
            while (ST[i] != '\0' && ST[j] != '\0' && found == TRUE) { // identifier와 한글자씩 같은지 비교
                if (ST[i] != ST[j])
                    found = FALSE;
                else {
                    i++;
                    j++;
                }
            }
            here = here->next; // 연결리스트에서 다음 칸으로 이동하며 체크
        }
    }
}

// Add HT - Add a new identifier to the hash table.
//          If list head HT[hashcode] is null, simply add a list element with
//          starting index of the identifier in ST.
//          If list head HT[hashcode] is not null, add a new identifier to the head of the chain.
void AddHT(int hscode) {
    HTentry* ptr;

    ptr = (HTentry*)malloc(sizeof(HTentry));
    ptr->index = nextid;
    ptr->linenum = line_num;
    ptr->tp = type;
    ptr->rtp = returntp;
    ptr->paramnum = 0;
    ptr->next = HT[hscode];
    HT[hscode] = ptr;
    curid = ptr;
}

// Print Hashtable - Print the hash table. Write out the hashcode and the list of identifiers
//                 associated with each hashcode, but only for non-empty list.
//                 Print out the number of characters used up in ST.
void printHT() {
    int i, j;
    HTentry* here;

    printf("\n\n\n [[ HASH TABLE ]] \n\n");

    for (i = 0; i < HTsize; i++) {
        if (HT[i] != NULL) {
            printf("  Hash Code %3d : ", i);
            // 연결리스트에서 다음 칸으로 넘어가면서 출력
            for (here = HT[i]; here != NULL; here = here->next) {
                j = here->index;
                while (ST[j] != '\0' && j < STsize) {
                    printf("%c", ST[j++]);
                }
                if (here->tp == 0) {
                    printf(" - integer scalar variable ");
                    printf(" (line %d)", here->linenum);
                }
                else if (here->tp == 1) {
                    printf(" - integer array variable ");
                    printf(" (line %d)", here->linenum);
                }
                else if (here->tp == 2) {
                    printf(" - float scalar variable ");
                    printf(" (line %d)", here->linenum);
                }
                else if (here->tp == 3) {
                    printf(" - float array variable ");
                    printf(" (line %d)", here->linenum);
                }
                else if (here->tp == 4) {
                    printf(" - function ");
                    printf(" (line %d)\n", here->linenum);
                    printf("\t\t  return type : ");
                    if (here->rtp == 0) printf("void / ");
                    else if (here->rtp == 1) printf("int / ");
                    else if (here->rtp == 2) printf("float / ");
                    printf("parameters : ");
                    for (int x = 0; x < here->paramnum; x++) {
                        int tmp = here->param[x];
                        while (ST[tmp] != '\0' && tmp < STsize) {
                            printf("%c", ST[tmp++]);
                        }
                        printf(" ");
                    }
                }
                printf("\n\t\t  ");
            }
            printf("\n");
        }
    }

    printf("\n < %d characters are used in the string table >\n\n\n\n", nextfree);
}

// symbolTable - Read the identifier from the file and directly append it into ST.
//               Compute its hash code and look up the identifier in hash table HT[hashcode].
//               Update stidx(index in String Table).
void symbolTable() {
    int i;
    ReadID(); // identifier 읽음
    ST[nextfree++] = '\0';

    ComputeHS(nextid, nextfree); // identifier의 hashcode 계산 -> hscode
    LookupHS(nextid, hashcode); // hash table에 이미 존재하는 idetifier인지 체크 -> found, sameid

    if (!found) { // 처음 입력된 identifier라면 (hash table에 이미 존재하는 idetifier가 아니라면)
        stidx = nextid;
        AddHT(hashcode);
    }
    else { // hash table에 이미 존재하는 idetifier라면
        stidx = sameid;
        nextfree = nextid;
    }
}