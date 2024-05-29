%{
/*
 * parser.y - yacc source for the MiniC
 * 
 * Programmer - 김예지(2176082), 송채원(2076216), 신정화(2271035), 윤하영(2071033)
 *
 * date - 2024/5/31
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
#include "glob.h"

int returntp = 0; // 0:void, 1:int
int type = 0; // 0:scalar, 1:array, 2:function
int paramidx = 0; // index of parameter array

extern printError(ERRORtypes err);
extern yylex();
extern yyerror(char* s);
%}

%token TIDENT TNUMBER TCONST TELSE TIF TINT TRETURN TVOID TWHILE
%token TADD TSUB TMUL TDIV TMOD 
%token TASSIGN TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN
%token TNOT TOR TAND TEQUAL TNOTEQU TGREAT TLESS TGREATE TLESSE
%token TINC TDEC TCOMMA TSEMICOLON
%token TLPAREN TRPAREN TLBRACE TRBRACE TLSQUARE TRSQUARE
%token TTOOLONG TILLIDENT TILLCH
%nonassoc TLOWERTHANELSE
%nonassoc TELSE

%%
mini_c 				: translation_unit
					;
translation_unit 	: external_dcl
					| translation_unit external_dcl
					| TILLCH
					{
						yyerrok;
						printError(illch);	/* error - Lillegal character */
					}
					;
external_dcl 		: function_def
		  			| declaration
					| TIDENT error
					{
						yyerrok;
						printError(wrong_st);	/* error - Wrong Statement */
					}
					| TRBRACE
					{
						yyerrok;
						printError(nobrace);	/* error - Missing brace */
					}
					;
function_def 		: function_header compound_st
					| function_header TSEMICOLON
					| function_header error
					{
						yyerrok;
						printError(wrong_funcdef);	/* error - Wrong function definition */
					}
					;
function_header 	: dcl_spec function_name formal_param
					;
dcl_spec 			: dcl_specifiers
					;
dcl_specifiers 		: dcl_specifier
		 			| dcl_specifiers dcl_specifier
					;
dcl_specifier 		: type_qualifier
					| type_specifier
					;
type_qualifier 		: TCONST
					;
type_specifier 		: TINT	{returntp = 1;}		/* type: integer */
		 			| TVOID	{returntp = 0;}		/* type: void */
					;
function_name 		: identifier
					{
						curid->tp = 2;
						curid->rtp = returntp;
						preid = curid;
						paramidx = 0;
					}
					;
formal_param 		: TLPAREN opt_formal_param TRPAREN
					| TLPAREN opt_formal_param error
					{
						yyerrok;
						printError(noparen);	/* error - Missing paren */
					}
					;
opt_formal_param 	: formal_param_list
					|
					;
formal_param_list 	: param_dcl
		    		| formal_param_list TCOMMA param_dcl
					;
param_dcl 			: dcl_spec declarator
					{
						curid->tp = type;
						preid->param[paramidx++] = curid->index;
						preid->paramnum++;
					}
					;
compound_st 		: TLBRACE opt_dcl_list opt_stat_list TRBRACE
					| TLBRACE opt_dcl_list opt_stat_list error
					{
						yyerrok;
						printError(nobrace);	/* error - Missing brace */
					}
					;
opt_dcl_list 		: declaration_list
					|
					;
declaration_list 	: declaration
					| declaration_list declaration
					;
declaration 		: dcl_spec init_dcl_list TSEMICOLON
					| dcl_spec init_dcl_list error
					{
						yyerrok;
						printError(nosemi);	/* error - Missing semicolon */
					}
					| dcl_spec error
					{
						yyerrok;
						printError(wrong_dcl);	/* error - wrong declaration */
					}
					;
init_dcl_list 		: init_declarator
					| init_dcl_list TCOMMA init_declarator
					;
init_declarator 	: declarator
		 			| declarator TASSIGN TNUMBER
					;
declarator 			: identifier {curid->tp = 0;}
	     			| identifier TLSQUARE opt_number TRSQUARE {curid->tp = 1;}
					| identifier TLSQUARE opt_number error
					{
						yyerrok;
						printError(nosquare);	/* error - Missing square */
					}
					;
opt_number 			: TNUMBER
	     			|
					;
opt_stat_list 		: statement_list
		 			|
					;
statement_list 		: statement
		 			| statement_list statement
					;
statement 			: compound_st
	   				| expression_st
	   				| if_st
	   				| while_st
	   				| return_st
	   				;
expression_st 		: opt_expression TSEMICOLON
					| expression error
					{
						yyerrok;
						printError(nosemi);	/* error - Missing semicolon */
					}
					;
opt_expression		: expression
		 			|
					;
if_st 				: TIF TLPAREN expression TRPAREN statement %prec TLOWERTHANELSE
					| TIF TLPAREN expression TRPAREN statement TELSE statement
					;
while_st 			: TWHILE TLPAREN expression TRPAREN statement
					;
return_st 			: TRETURN opt_expression TSEMICOLON
					| TRETURN opt_expression error
					{
						yyerrok;
						printError(nosemi);	/* error - Missing semicolon */
					}
					;
expression 			: assignment_exp
					;
assignment_exp 		: logical_or_exp
					| unary_exp TASSIGN assignment_exp
					| unary_exp TASSIGN error
					{
						yyerrok;
						printError(wrong_asgn);	/* error - Wrong assignment */
					}
					| unary_exp TADDASSIGN assignment_exp
					| unary_exp TADDASSIGN error
					{
						yyerrok;
						printError(wrong_asgn);	/* error - Wrong assignment */
					}
					| unary_exp TSUBASSIGN assignment_exp
					| unary_exp TSUBASSIGN error
					{
						yyerrok;
						printError(wrong_asgn);	/* error - Wrong assignment */
					}
					| unary_exp TMULASSIGN assignment_exp
					| unary_exp TMULASSIGN error
					{
						yyerrok;
						printError(wrong_asgn);	/* error - Wrong assignment */
					}
					| unary_exp TDIVASSIGN assignment_exp
					| unary_exp TDIVASSIGN error
					{
						yyerrok;
						printError(wrong_asgn);	/* error - Wrong assignment */
					}
					| unary_exp TMODASSIGN assignment_exp
					| unary_exp TMODASSIGN error
					{
						yyerrok;
						printError(wrong_asgn);	/* error - Wrong assignment */
					}
					;
logical_or_exp 		: logical_and_exp
					| logical_or_exp TOR logical_and_exp
					| logical_or_exp TOR error
					{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					}
					;
logical_and_exp 	: equality_exp
		 			| logical_and_exp TAND equality_exp
					| logical_and_exp TAND error
					{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					}
					;
equality_exp 		: relational_exp
					| equality_exp TEQUAL relational_exp
					| equality_exp TEQUAL error
					{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					}
					| equality_exp TNOTEQU relational_exp
					| equality_exp TNOTEQU error
					{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					}
					;
relational_exp	 	: additive_exp
					| relational_exp TGREAT additive_exp
					| relational_exp TLESS additive_exp
					| relational_exp TGREATE additive_exp
					| relational_exp TLESSE additive_exp
					;
additive_exp 		: multiplicative_exp
					| additive_exp TADD multiplicative_exp
					| additive_exp TADD error
					{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					}
					| additive_exp TSUB multiplicative_exp
					| additive_exp TSUB error
					{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					}
					;
multiplicative_exp 	: unary_exp
		    		| multiplicative_exp TMUL unary_exp
					| multiplicative_exp TMUL error
					{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					}
					| multiplicative_exp TDIV unary_exp
					| multiplicative_exp TDIV error
					{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					}
					| multiplicative_exp TMOD unary_exp
					| multiplicative_exp TMOD error
					{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					}
					;
unary_exp 			: postfix_exp
	   				| TSUB unary_exp
	   				| TNOT unary_exp
	   				| TINC unary_exp
	   				| TDEC unary_exp
					;
postfix_exp 		: primary_exp
	      			| postfix_exp TLSQUARE expression TRSQUARE
	      			| postfix_exp TLPAREN opt_actual_param TRPAREN
	      			| postfix_exp TINC
	      			| postfix_exp TDEC
					;
opt_actual_param 	: actual_param
		  			|
					;
actual_param 		: actual_param_list
					;
actual_param_list 	: assignment_exp
					| actual_param_list TCOMMA assignment_exp
					;
primary_exp 		: identifier
	     			| TNUMBER
	     			| TLPAREN expression TRPAREN
					;
identifier			: TIDENT
					| TTOOLONG
					{
						yyerrok;
						printError(toolong);	/* error - too long identifier */
					}
					| TILLIDENT
					{
						yyerrok;
						printError(illid);		/* error - illegal identifier */
					}
					;
%%

