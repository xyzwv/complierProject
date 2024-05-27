/*
* reporterror.c - error에 대한 출력
*
* Progammer - 김예지(2176082), 송채원(2076216), 신정화(2271035), 윤하영(2071033)
*
* date - 05/22/2024
*
*/

#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"

extern int line_num; // line number
extern int cErrors; // number of errors

/*
* yyerror() - error 함수
*/
void yyerror(char* s)
{
}

void printError(ERRORtypes err)
{
  switch(err)
  {
    case 0: //wrong_dcl
        printf("line: %d\n", line_num);
        printf("< Error > => Wrong Declaration!\n");
        cErrors++;
        break;

    case 1: //wrong_funcdef
        printf("line: %d\n", line_num);
        printf("< Error > => Wrong function definition\n");
        break;

    case 2: //nosemi
        printf("line: %d\n", line_num);
        printf("< Error > => Missing semicolon\n");
        cErrors++;
        break;

    case 3: //nobrace
        printf("line: %d\n", line_num);
        printf("< Error > => Missing brace\n");
        cErrors++;
        break;

    case 4: //nosquare
        printf("line: %d\n", line_num);
        printf("< Error > => Missing square\n");
        cErrors++;
        break;

    case 5: //noparen
        printf("line: %d\n", line_num);
        printf("< Error > => Missing paren\n");
        cErrors++;
        break;
  }
}