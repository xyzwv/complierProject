
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TIDENT	258
#define	TNUMBER	259
#define	TCONST	260
#define	TELSE	261
#define	TIF	262
#define	TINT	263
#define	TRETURN	264
#define	TVOID	265
#define	TWHILE	266
#define	TADD	267
#define	TSUB	268
#define	TMUL	269
#define	TDIV	270
#define	TMOD	271
#define	TASSIGN	272
#define	TADDASSIGN	273
#define	TSUBASSIGN	274
#define	TMULASSIGN	275
#define	TDIVASSIGN	276
#define	TMODASSIGN	277
#define	TNOT	278
#define	TOR	279
#define	TAND	280
#define	TEQUAL	281
#define	TNOTEQU	282
#define	TGREAT	283
#define	TLESS	284
#define	TGREATE	285
#define	TLESSE	286
#define	TINC	287
#define	TDEC	288
#define	TCOMMA	289
#define	TSEMICOLON	290
#define	TLPAREN	291
#define	TRPAREN	292
#define	TLBRACE	293
#define	TRBRACE	294
#define	TLSQUARE	295
#define	TRSQUARE	296
#define	TTOOLONG	297
#define	TILLIDENT	298
#define	TILLCH	299
#define	TLOWERTHANELSE	300

#line 1 "parser.y"

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

int type_int = 0;
int type_void = 0;

void line(int);
extern printError(ERRORtypes err);
extern yylex();
extern yyerror(char* s);

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		157
#define	YYFLAG		-32768
#define	YYNTBASE	46

#define YYTRANSLATE(x) ((unsigned)(x) <= 300 ? yytranslate[x] : 91)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    14,    17,    21,    23,
    25,    28,    30,    32,    34,    36,    38,    40,    44,    48,
    50,    51,    53,    57,    60,    65,    70,    72,    73,    75,
    78,    82,    83,    85,    89,    91,    95,    97,   102,   107,
   109,   110,   112,   113,   115,   118,   120,   122,   124,   126,
   128,   131,   133,   134,   140,   148,   154,   158,   160,   162,
   166,   170,   174,   178,   182,   186,   188,   192,   194,   198,
   200,   204,   208,   210,   214,   218,   222,   226,   228,   232,
   236,   238,   242,   246,   250,   252,   255,   258,   261,   264,
   266,   271,   276,   279,   282,   284,   285,   287,   289,   293,
   295,   297
};

static const short yyrhs[] = {    47,
     0,    48,     0,    47,    48,     0,    49,     0,    64,     0,
    50,    61,     0,    50,     1,     0,    51,    56,    57,     0,
    52,     0,    53,     0,    52,    53,     0,    54,     0,    55,
     0,     5,     0,     8,     0,    10,     0,     3,     0,    36,
    58,    37,     0,    36,    58,     1,     0,    59,     0,     0,
    60,     0,    59,    34,    60,     0,    51,    67,     0,    38,
    62,    69,    39,     0,    38,    62,    69,     1,     0,    63,
     0,     0,    64,     0,    63,    64,     0,    51,    65,    35,
     0,     0,    66,     0,    65,    34,    66,     0,    67,     0,
    67,    17,     4,     0,     3,     0,     3,    40,    68,    41,
     0,     3,    40,    68,     1,     0,     4,     0,     0,    70,
     0,     0,    71,     0,    70,    71,     0,    61,     0,    72,
     0,    74,     0,    75,     0,    76,     0,    73,    35,     0,
    77,     0,     0,     7,    36,    77,    37,    71,     0,     7,
    36,    77,    37,    71,     6,    71,     0,    11,    36,    77,
    37,    71,     0,     9,    73,    35,     0,    78,     0,    79,
     0,    85,    17,    78,     0,    85,    18,    78,     0,    85,
    19,    78,     0,    85,    20,    78,     0,    85,    21,    78,
     0,    85,    22,    78,     0,    80,     0,    79,    24,    80,
     0,    81,     0,    80,    25,    81,     0,    82,     0,    81,
    26,    82,     0,    81,    27,    82,     0,    83,     0,    82,
    28,    83,     0,    82,    29,    83,     0,    82,    30,    83,
     0,    82,    31,    83,     0,    84,     0,    83,    12,    84,
     0,    83,    13,    84,     0,    85,     0,    84,    14,    85,
     0,    84,    15,    85,     0,    84,    16,    85,     0,    86,
     0,    13,    85,     0,    23,    85,     0,    32,    85,     0,
    33,    85,     0,    90,     0,    86,    40,    77,    41,     0,
    86,    36,    87,    37,     0,    86,    32,     0,    86,    33,
     0,    88,     0,     0,    89,     0,    78,     0,    89,    34,
    78,     0,     3,     0,     4,     0,    36,    77,    37,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    37,    39,    40,    42,    43,    45,    46,    52,    54,    56,
    57,    59,    60,    62,    64,    65,    67,    69,    70,    76,
    77,    79,    80,    85,    87,    88,    94,    95,    97,    98,
   100,   101,   107,   108,   110,   111,   113,   114,   115,   121,
   122,   124,   125,   127,   128,   130,   131,   132,   133,   134,
   136,   138,   139,   141,   142,   144,   146,   148,   150,   151,
   152,   153,   154,   155,   156,   158,   159,   161,   162,   164,
   165,   166,   168,   169,   170,   171,   172,   174,   175,   176,
   178,   179,   180,   181,   183,   184,   185,   186,   187,   189,
   190,   191,   192,   193,   195,   196,   198,   200,   201,   203,
   204,   205
};

static const char * const yytname[] = {   "$","error","$undefined.","TIDENT",
"TNUMBER","TCONST","TELSE","TIF","TINT","TRETURN","TVOID","TWHILE","TADD","TSUB",
"TMUL","TDIV","TMOD","TASSIGN","TADDASSIGN","TSUBASSIGN","TMULASSIGN","TDIVASSIGN",
"TMODASSIGN","TNOT","TOR","TAND","TEQUAL","TNOTEQU","TGREAT","TLESS","TGREATE",
"TLESSE","TINC","TDEC","TCOMMA","TSEMICOLON","TLPAREN","TRPAREN","TLBRACE","TRBRACE",
"TLSQUARE","TRSQUARE","TTOOLONG","TILLIDENT","TILLCH","TLOWERTHANELSE","mini_c",
"translation_unit","external_dcl","function_def","function_header","dcl_spec",
"dcl_specifiers","dcl_specifier","type_qualifier","type_specifier","function_name",
"formal_param","opt_formal_param","formal_param_list","param_dcl","compound_st",
"opt_dcl_list","declaration_list","declaration","init_dcl_list","init_declarator",
"declarator","opt_number","opt_stat_list","statement_list","statement","expression_st",
"opt_expression","if_st","while_st","return_st","expression","assignment_exp",
"logical_or_exp","logical_and_exp","equality_exp","relational_exp","additive_exp",
"multiplicative_exp","unary_exp","postfix_exp","opt_actual_param","actual_param",
"actual_param_list","primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    46,    47,    47,    48,    48,    49,    49,    50,    51,    52,
    52,    53,    53,    54,    55,    55,    56,    57,    57,    58,
    58,    59,    59,    60,    61,    61,    62,    62,    63,    63,
    64,    64,    65,    65,    66,    66,    67,    67,    67,    68,
    68,    69,    69,    70,    70,    71,    71,    71,    71,    71,
    72,    73,    73,    74,    74,    75,    76,    77,    78,    78,
    78,    78,    78,    78,    78,    79,    79,    80,    80,    81,
    81,    81,    82,    82,    82,    82,    82,    83,    83,    83,
    84,    84,    84,    84,    85,    85,    85,    85,    85,    86,
    86,    86,    86,    86,    87,    87,    88,    89,    89,    90,
    90,    90
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     2,     3,     1,     1,
     2,     1,     1,     1,     1,     1,     1,     3,     3,     1,
     0,     1,     3,     2,     4,     4,     1,     0,     1,     2,
     3,     0,     1,     3,     1,     3,     1,     4,     4,     1,
     0,     1,     0,     1,     2,     1,     1,     1,     1,     1,
     2,     1,     0,     5,     7,     5,     3,     1,     1,     3,
     3,     3,     3,     3,     3,     1,     3,     1,     3,     1,
     3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
     1,     3,     3,     3,     1,     2,     2,     2,     2,     1,
     4,     4,     2,     2,     1,     0,     1,     1,     3,     1,
     1,     3
};

static const short yydefact[] = {    32,
    14,    15,    16,     1,     2,     4,     0,     0,     9,    10,
    12,    13,     5,     3,     7,    28,     6,    37,     0,     0,
    33,    35,    11,     0,    43,    27,    29,    41,    21,     8,
     0,    31,     0,    37,   100,   101,     0,    53,     0,     0,
     0,     0,     0,     0,    46,     0,    42,    44,    47,     0,
    48,    49,    50,    52,    58,    59,    66,    68,    70,    73,
    78,    81,    85,    90,    30,    40,     0,     0,     0,    20,
    22,    34,    36,     0,     0,     0,    86,    87,    88,    89,
     0,    26,    25,    45,    51,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    93,    94,    96,     0,    39,    38,
    24,    19,    18,     0,     0,    57,     0,   102,    67,    81,
    69,    71,    72,    74,    75,    76,    77,    79,    80,    82,
    83,    84,    60,    61,    62,    63,    64,    65,    98,     0,
    95,    97,     0,    23,    53,    53,    92,     0,    91,    54,
    56,    99,    53,    55,     0,     0,     0
};

static const short yydefgoto[] = {   155,
     4,     5,     6,     7,     8,     9,    10,    11,    12,    19,
    30,    69,    70,    71,    45,    25,    26,    13,    20,    21,
    22,    67,    46,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
   140,   141,   142,    64
};

static const short yypact[] = {    59,
-32768,-32768,-32768,    59,-32768,-32768,    10,    21,    59,-32768,
-32768,-32768,-32768,-32768,-32768,    59,-32768,   -26,    -4,    28,
-32768,    -1,-32768,    65,    69,    59,-32768,    73,    59,-32768,
    65,-32768,    75,    41,-32768,-32768,    49,   106,    50,   106,
   106,   106,   106,   106,-32768,     7,    69,-32768,-32768,    53,
-32768,-32768,-32768,-32768,-32768,    66,    83,     2,    13,    58,
   107,    18,    -6,-32768,-32768,-32768,     6,    65,     8,    77,
-32768,-32768,-32768,   106,    82,   106,-32768,-32768,-32768,-32768,
    87,-32768,-32768,-32768,-32768,   106,   106,   106,   106,   106,
   106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
   106,   106,   106,   106,-32768,-32768,   106,   106,-32768,-32768,
-32768,-32768,-32768,    59,    88,-32768,    89,-32768,    83,-32768,
     2,    13,    13,    58,    58,    58,    58,   107,   107,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    90,
-32768,    86,    91,-32768,    80,    80,-32768,   106,-32768,   122,
-32768,-32768,    80,-32768,   130,   131,-32768
};

static const short yypgoto[] = {-32768,
-32768,   129,-32768,-32768,   -14,-32768,   125,-32768,-32768,-32768,
-32768,-32768,-32768,    22,   128,-32768,-32768,    -3,-32768,   109,
    76,-32768,-32768,-32768,   -47,-32768,    99,-32768,-32768,-32768,
   -43,   -82,-32768,    55,    56,    26,     4,   -20,   -37,-32768,
-32768,-32768,-32768,-32768
};


#define	YYLAST		144


static const short yytable[] = {    84,
    81,    24,    77,    78,    79,    80,   109,    82,   112,   -17,
    15,    24,    27,    28,    68,    33,   133,   134,   135,   136,
   137,   138,    65,    18,   139,   105,   106,    88,    89,   107,
   115,    29,   117,   108,    99,   100,   101,   102,   103,   104,
    90,    91,    92,    93,   113,    83,   110,    16,   120,   120,
   120,   120,   120,   120,   120,   120,   120,   120,   130,   131,
   132,    31,    32,     1,   143,   152,     2,    34,     3,    94,
    95,    35,    36,   128,   129,    37,    66,    38,    73,    39,
    28,    40,    35,    36,    74,    76,    37,    85,    38,    86,
    39,    41,    40,   124,   125,   126,   127,   150,   151,    68,
    42,    43,    41,   -53,    44,   154,    16,    87,    35,    36,
   114,    42,    43,   122,   123,    44,   116,    16,    40,   148,
    96,    97,    98,   118,   145,   146,   147,   153,    41,   156,
   157,   149,    14,    23,    17,   144,    75,    42,    43,    72,
   119,    44,   121,   111
};

static const short yycheck[] = {    47,
    44,    16,    40,    41,    42,    43,     1,     1,     1,    36,
     1,    26,    16,    40,    29,    17,    99,   100,   101,   102,
   103,   104,    26,     3,   107,    32,    33,    26,    27,    36,
    74,    36,    76,    40,    17,    18,    19,    20,    21,    22,
    28,    29,    30,    31,    37,    39,    41,    38,    86,    87,
    88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
    98,    34,    35,     5,   108,   148,     8,     3,    10,    12,
    13,     3,     4,    94,    95,     7,     4,     9,     4,    11,
    40,    13,     3,     4,    36,    36,     7,    35,     9,    24,
    11,    23,    13,    90,    91,    92,    93,   145,   146,   114,
    32,    33,    23,    35,    36,   153,    38,    25,     3,     4,
    34,    32,    33,    88,    89,    36,    35,    38,    13,    34,
    14,    15,    16,    37,    37,    37,    37,     6,    23,     0,
     0,    41,     4,     9,     7,   114,    38,    32,    33,    31,
    86,    36,    87,    68
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 7:
#line 47 "parser.y"
{
						yyerrok;
						printError(wrong_funcdef);	/* error - wrong function definition */
					;
    break;}
case 15:
#line 64 "parser.y"
{type_int=1;;
    break;}
case 16:
#line 65 "parser.y"
{type_void=1;;
    break;}
case 19:
#line 71 "parser.y"
{
						yyerrok;
						printError(noparen);	/* error - Missing paren */
					;
    break;}
case 26:
#line 89 "parser.y"
{
						yyerrok;
						printError(nobrace);	/* error - Missing brace */
					;
    break;}
case 32:
#line 102 "parser.y"
{
						yyerrok;
						printError(wrong_dcl);	/* error - wrong declaration */
					;
    break;}
case 39:
#line 116 "parser.y"
{
						yyerrok;
						printError(nosquare);	/* error - Missing square */
					;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 207 "parser.y"


