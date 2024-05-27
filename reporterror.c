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
//#include "glob.h"
//extern line(int);
//extern yylex();

/*
* yyerror() - error 함수
*/
void yyerror(char* s)
{
    printf("%s\n", s);
}

void printError(ERRORtypes err)
{
  switch(err)
  {
    case 0: //wrong_st
      line(cLine);
      printf("< Error > => Wrong Statement!\n");
      cErrors++;
      break;

    case 1: //wrong_funcdef
      line(cLine);
      printf("< Error > => Wrong function definition\n");
      break;

    case 2: //nosemi
      line(cLine);
      printf("< Error > => Missing semicolon\n");
      cErrors++;
      break;

    case 3: //nobrace
      line(cLine);
      printf("< Error > => Missing brace\n");
      cErrors++;
      break;

    case 4: //nobracket
      line(cLine);
      printf("< Error > => Missing bracket\n");
      cErrors++;
      break;
  }
}