
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

int returntp = 0; // 0:void 1:int
int type = 0; // 0:scalar 1:array 2:function
int paramidx = 0;

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



#define	YYFINAL		162
#define	YYFLAG		-32768
#define	YYNTBASE	46

#define YYTRANSLATE(x) ((unsigned)(x) <= 300 ? yytranslate[x] : 92)

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
     0,     2,     4,     7,     9,    11,    14,    18,    20,    22,
    25,    27,    29,    31,    33,    35,    37,    41,    45,    47,
    48,    50,    54,    57,    62,    67,    69,    70,    72,    75,
    79,    83,    86,    88,    92,    94,    98,   100,   105,   110,
   112,   113,   115,   116,   118,   121,   123,   125,   127,   129,
   131,   134,   136,   137,   143,   151,   157,   161,   165,   167,
   169,   173,   177,   181,   185,   189,   193,   195,   199,   201,
   205,   207,   211,   215,   217,   221,   225,   229,   233,   235,
   239,   243,   245,   249,   253,   257,   259,   262,   265,   268,
   271,   273,   278,   283,   286,   289,   291,   292,   294,   296,
   300,   302,   304,   308,   310,   312
};

static const short yyrhs[] = {    47,
     0,    48,     0,    47,    48,     0,    49,     0,    64,     0,
    50,    61,     0,    51,    56,    57,     0,    52,     0,    53,
     0,    52,    53,     0,    54,     0,    55,     0,     5,     0,
     8,     0,    10,     0,    91,     0,    36,    58,    37,     0,
    36,    58,     1,     0,    59,     0,     0,    60,     0,    59,
    34,    60,     0,    51,    67,     0,    38,    62,    69,    39,
     0,    38,    62,    69,     1,     0,    63,     0,     0,    64,
     0,    63,    64,     0,    51,    65,    35,     0,    51,    65,
     1,     0,    51,     1,     0,    66,     0,    65,    34,    66,
     0,    67,     0,    67,    17,     4,     0,    91,     0,    91,
    40,    68,    41,     0,    91,    40,    68,     1,     0,     4,
     0,     0,    70,     0,     0,    71,     0,    70,    71,     0,
    61,     0,    72,     0,    74,     0,    75,     0,    76,     0,
    73,    35,     0,    77,     0,     0,     7,    36,    77,    37,
    71,     0,     7,    36,    77,    37,    71,     6,    71,     0,
    11,    36,    77,    37,    71,     0,     9,    73,    35,     0,
     9,    73,     1,     0,    78,     0,    79,     0,    85,    17,
    78,     0,    85,    18,    78,     0,    85,    19,    78,     0,
    85,    20,    78,     0,    85,    21,    78,     0,    85,    22,
    78,     0,    80,     0,    79,    24,    80,     0,    81,     0,
    80,    25,    81,     0,    82,     0,    81,    26,    82,     0,
    81,    27,    82,     0,    83,     0,    82,    28,    83,     0,
    82,    29,    83,     0,    82,    30,    83,     0,    82,    31,
    83,     0,    84,     0,    83,    12,    84,     0,    83,    13,
    84,     0,    85,     0,    84,    14,    85,     0,    84,    15,
    85,     0,    84,    16,    85,     0,    86,     0,    13,    85,
     0,    23,    85,     0,    32,    85,     0,    33,    85,     0,
    90,     0,    86,    40,    77,    41,     0,    86,    36,    87,
    37,     0,    86,    32,     0,    86,    33,     0,    88,     0,
     0,    89,     0,    78,     0,    89,    34,    78,     0,    91,
     0,     4,     0,    36,    77,    37,     0,     3,     0,    42,
     0,    43,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    41,    43,    44,    46,    47,    49,    51,    53,    55,    56,
    58,    59,    61,    63,    64,    66,    75,    76,    82,    83,
    85,    86,    91,    98,    99,   105,   106,   108,   109,   111,
   112,   117,   123,   124,   126,   127,   129,   130,   131,   137,
   138,   140,   141,   143,   144,   146,   147,   148,   149,   150,
   152,   154,   155,   157,   158,   160,   162,   163,   169,   171,
   172,   173,   174,   175,   176,   177,   179,   180,   182,   183,
   185,   186,   187,   189,   190,   191,   192,   193,   195,   196,
   197,   199,   200,   201,   202,   204,   205,   206,   207,   208,
   210,   211,   212,   213,   214,   216,   217,   219,   221,   222,
   224,   225,   226,   228,   229,   234
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
"actual_param_list","primary_exp","identifier",""
};
#endif

static const short yyr1[] = {     0,
    46,    47,    47,    48,    48,    49,    50,    51,    52,    52,
    53,    53,    54,    55,    55,    56,    57,    57,    58,    58,
    59,    59,    60,    61,    61,    62,    62,    63,    63,    64,
    64,    64,    65,    65,    66,    66,    67,    67,    67,    68,
    68,    69,    69,    70,    70,    71,    71,    71,    71,    71,
    72,    73,    73,    74,    74,    75,    76,    76,    77,    78,
    78,    78,    78,    78,    78,    78,    79,    79,    80,    80,
    81,    81,    81,    82,    82,    82,    82,    82,    83,    83,
    83,    84,    84,    84,    84,    85,    85,    85,    85,    85,
    86,    86,    86,    86,    86,    87,    87,    88,    89,    89,
    90,    90,    90,    91,    91,    91
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     3,     1,     1,     2,
     1,     1,     1,     1,     1,     1,     3,     3,     1,     0,
     1,     3,     2,     4,     4,     1,     0,     1,     2,     3,
     3,     2,     1,     3,     1,     3,     1,     4,     4,     1,
     0,     1,     0,     1,     2,     1,     1,     1,     1,     1,
     2,     1,     0,     5,     7,     5,     3,     3,     1,     1,
     3,     3,     3,     3,     3,     3,     1,     3,     1,     3,
     1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
     3,     1,     3,     3,     3,     1,     2,     2,     2,     2,
     1,     4,     4,     2,     2,     1,     0,     1,     1,     3,
     1,     1,     3,     1,     1,     1
};

static const short yydefact[] = {     0,
    13,    14,    15,     1,     2,     4,     0,     0,     8,     9,
    11,    12,     5,     3,    27,     6,    32,   104,   105,   106,
     0,     0,    33,    35,    37,    10,     0,    43,    26,    28,
    20,     7,    31,     0,    30,     0,    41,    37,   102,     0,
    53,     0,     0,     0,     0,     0,     0,    46,     0,    42,
    44,    47,     0,    48,    49,    50,    52,    59,    60,    67,
    69,    71,    74,    79,    82,    86,    91,   101,    29,     0,
     0,    19,    21,    34,    36,    40,     0,     0,     0,     0,
    87,    88,    89,    90,     0,    25,    24,    45,    51,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
    97,     0,    23,    18,    17,     0,    39,    38,     0,    58,
    57,     0,   103,    68,    82,    70,    72,    73,    75,    76,
    77,    78,    80,    81,    83,    84,    85,    61,    62,    63,
    64,    65,    66,    99,     0,    96,    98,     0,    22,    53,
    53,    93,     0,    92,    54,    56,   100,    53,    55,     0,
     0,     0
};

static const short yydefgoto[] = {   160,
     4,     5,     6,     7,     8,     9,    10,    11,    12,    21,
    32,    71,    72,    73,    48,    28,    29,    13,    22,    23,
    24,    77,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
   145,   146,   147,    67,    68
};

static const short yypact[] = {    87,
-32768,-32768,-32768,    87,-32768,-32768,   -25,     7,    87,-32768,
-32768,-32768,-32768,-32768,    87,-32768,-32768,-32768,-32768,-32768,
   -20,    10,-32768,    26,   -22,-32768,     7,    71,    87,-32768,
    87,-32768,-32768,    27,-32768,    60,    62,    39,-32768,    45,
   120,    47,   120,   120,   120,   120,   120,-32768,     8,    71,
-32768,-32768,    58,-32768,-32768,-32768,-32768,-32768,    72,    80,
    14,    97,    24,     5,    69,     6,-32768,-32768,-32768,    27,
    11,    76,-32768,-32768,-32768,-32768,    31,   120,    33,   120,
-32768,-32768,-32768,-32768,    79,-32768,-32768,-32768,-32768,   120,
   120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
   120,   120,   120,   120,   120,   120,   120,   120,-32768,-32768,
   120,   120,-32768,-32768,-32768,    87,-32768,-32768,    81,-32768,
-32768,    83,-32768,    80,-32768,    14,    97,    97,    24,    24,
    24,    24,     5,     5,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,    85,-32768,    95,    89,-32768,   108,
   108,-32768,   120,-32768,   126,-32768,-32768,   108,-32768,   138,
   139,-32768
};

static const short yypgoto[] = {-32768,
-32768,   141,-32768,-32768,   -14,-32768,   133,-32768,-32768,-32768,
-32768,-32768,-32768,    32,   140,-32768,-32768,    56,-32768,   115,
    84,-32768,-32768,-32768,   -50,-32768,   114,-32768,-32768,-32768,
   -45,   -80,-32768,    67,    68,   -16,    40,     0,   -39,-32768,
-32768,-32768,-32768,-32768,    -5
};


#define	YYLAST		163


static const short yytable[] = {    88,
    27,    85,    25,    81,    82,    83,    84,    17,    86,    18,
    33,   114,    15,   -16,    27,    31,    70,    37,   100,   101,
   102,    38,   138,   139,   140,   141,   142,   143,    38,    18,
   144,   117,   119,   120,   122,    98,    99,   109,   110,    92,
    93,   111,    36,    34,    35,   112,    87,   115,    19,    20,
   125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
   135,   136,   137,    75,    38,    76,   148,   121,    19,    20,
    30,   118,   157,    18,    39,   127,   128,    40,    37,    41,
    78,    42,    80,    43,    69,   103,   104,   105,   106,   107,
   108,     1,    89,    44,     2,    90,     3,   133,   134,   155,
   156,    70,    45,    46,    91,   -53,    47,   159,    15,   116,
    18,    39,    19,    20,    40,   123,    41,   150,    42,   151,
    43,   152,    18,    39,    94,    95,    96,    97,   153,   154,
    44,   158,    43,   129,   130,   131,   132,   161,   162,    45,
    46,    26,    44,    47,    14,    15,    16,   149,    74,    19,
    20,    45,    46,   113,    79,    47,   124,     0,   126,     0,
     0,    19,    20
};

static const short yycheck[] = {    50,
    15,    47,     8,    43,    44,    45,    46,     1,     1,     3,
     1,     1,    38,    36,    29,    36,    31,    40,    14,    15,
    16,    27,   103,   104,   105,   106,   107,   108,    34,     3,
   111,     1,    78,     1,    80,    12,    13,    32,    33,    26,
    27,    36,    17,    34,    35,    40,    39,    37,    42,    43,
    90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
   100,   101,   102,     4,    70,     4,   112,    35,    42,    43,
    15,    41,   153,     3,     4,    92,    93,     7,    40,     9,
    36,    11,    36,    13,    29,    17,    18,    19,    20,    21,
    22,     5,    35,    23,     8,    24,    10,    98,    99,   150,
   151,   116,    32,    33,    25,    35,    36,   158,    38,    34,
     3,     4,    42,    43,     7,    37,     9,    37,    11,    37,
    13,    37,     3,     4,    28,    29,    30,    31,    34,    41,
    23,     6,    13,    94,    95,    96,    97,     0,     0,    32,
    33,     9,    23,    36,     4,    38,     7,   116,    34,    42,
    43,    32,    33,    70,    41,    36,    90,    -1,    91,    -1,
    -1,    42,    43
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

case 14:
#line 63 "parser.y"
{type_int=1; returntp = 1;;
    break;}
case 15:
#line 64 "parser.y"
{type_void=1; returntp = 0;;
    break;}
case 16:
#line 67 "parser.y"
{
						printf("func...");
						curid->tp = 2;
						curid->rtp = returntp;
						preid = curid;
						paramidx = 0;
					;
    break;}
case 18:
#line 77 "parser.y"
{
						yyerrok;
						printError(noparen);	/* error - Missing paren */
					;
    break;}
case 23:
#line 92 "parser.y"
{
						curid->tp = type;
						preid->param[paramidx++] = curid->index;
						preid->paramnum++;
					;
    break;}
case 25:
#line 100 "parser.y"
{
						yyerrok;
						printError(nobrace);	/* error - Missing brace */
					;
    break;}
case 31:
#line 113 "parser.y"
{
						yyerrok;
						printError(nosemi);	/* error - Missing semicolon */
					;
    break;}
case 32:
#line 118 "parser.y"
{
						yyerrok;
						printError(wrong_dcl);	/* error - wrong declaration */
					;
    break;}
case 37:
#line 129 "parser.y"
{type = 0;;
    break;}
case 38:
#line 130 "parser.y"
{type = 1;;
    break;}
case 39:
#line 132 "parser.y"
{
						yyerrok;
						printError(nosquare);	/* error - Missing square */
					;
    break;}
case 58:
#line 164 "parser.y"
{
						yyerrok;
						printError(nosemi);	/* error - Missing semicolon */
					;
    break;}
case 105:
#line 230 "parser.y"
{
						yyerrok;
						printError(toolong);	/* error - too long identifier */
					;
    break;}
case 106:
#line 235 "parser.y"
{
						yyerrok;
						printError(illid);		/* error - illegal identifier */
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
#line 240 "parser.y"


