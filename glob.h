/*
 * glob.h – global variable for the project
 * progrmmer – 김예지(2176082), 송채원(2076216), 신정화(2271035), 윤하영(2071033)
 * date - 2024-04-29
 */

#ifndef GLOB_H
#define GLOB_H

#define STsize 1000 // size of string table 
#define HTsize 100 // size of hash table

extern int paramidx;
extern int returntp; // 0:void 1:int
extern int type; // 0:scalar 1:array 2:function

extern int line_num; // line number
extern int cErrors; // number of errors

extern int stidx; // index of identifier in String Table

extern unsigned long yyleng; // matched string
extern char* yytext; // length of matched string

enum errorTypes { wrong_dcl, wrong_funcdef, nosemi, nobrace, nosquare, noparen,
				  noerror, illsp, illid, overst, toolong };
typedef enum errorTypes ERRORtypes;

typedef struct HTentry {
    int index; // index of identifier in ST
    struct HTentry* next; // pointer to next identifier
    int linenum;
    int tp;
    int rtp;
    int paramnum;
    int param[4];
} HTentry;

HTentry* HT[HTsize]; // Array of list head of hashtable 
char ST[STsize]; // Array of string table

extern void symbolTable();
extern void printHT();

HTentry* curid; // current identifier pointer
HTentry* preid; // previous identifier pointer

#endif /* GLOB_H */