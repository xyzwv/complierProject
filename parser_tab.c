
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

int returntp = 0; // 0:void, 1:int
int type = 0; // 0:scalar, 1:array, 2:function
int paramidx = 0; // index of parameter array

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



#define	YYFINAL		185
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
     0,     2,     4,     7,     9,    11,    13,    16,    18,    21,
    24,    27,    31,    33,    35,    38,    40,    42,    44,    46,
    48,    50,    54,    58,    60,    61,    63,    67,    70,    75,
    80,    82,    83,    85,    88,    92,    96,    99,   101,   105,
   107,   111,   113,   118,   123,   125,   126,   128,   129,   131,
   134,   136,   138,   140,   142,   144,   147,   150,   152,   153,
   159,   167,   173,   177,   181,   183,   185,   189,   193,   197,
   201,   205,   209,   213,   217,   221,   225,   229,   233,   235,
   239,   243,   245,   249,   253,   255,   259,   263,   267,   271,
   273,   277,   281,   285,   289,   291,   295,   299,   303,   307,
   309,   313,   317,   321,   325,   329,   333,   335,   338,   341,
   344,   347,   349,   354,   359,   362,   365,   367,   368,   370,
   372,   376,   378,   380,   384,   386,   388
};

static const short yyrhs[] = {    47,
     0,    48,     0,    47,    48,     0,    44,     0,    49,     0,
    64,     0,     3,     1,     0,    39,     0,    50,    61,     0,
    50,    35,     0,    50,     1,     0,    51,    56,    57,     0,
    52,     0,    53,     0,    52,    53,     0,    54,     0,    55,
     0,     5,     0,     8,     0,    10,     0,    91,     0,    36,
    58,    37,     0,    36,    58,     1,     0,    59,     0,     0,
    60,     0,    59,    34,    60,     0,    51,    67,     0,    38,
    62,    69,    39,     0,    38,    62,    69,     1,     0,    63,
     0,     0,    64,     0,    63,    64,     0,    51,    65,    35,
     0,    51,    65,     1,     0,    51,     1,     0,    66,     0,
    65,    34,    66,     0,    67,     0,    67,    17,     4,     0,
    91,     0,    91,    40,    68,    41,     0,    91,    40,    68,
     1,     0,     4,     0,     0,    70,     0,     0,    71,     0,
    70,    71,     0,    61,     0,    72,     0,    74,     0,    75,
     0,    76,     0,    73,    35,     0,    77,     1,     0,    77,
     0,     0,     7,    36,    77,    37,    71,     0,     7,    36,
    77,    37,    71,     6,    71,     0,    11,    36,    77,    37,
    71,     0,     9,    73,    35,     0,     9,    73,     1,     0,
    78,     0,    79,     0,    85,    17,    78,     0,    85,    17,
     1,     0,    85,    18,    78,     0,    85,    18,     1,     0,
    85,    19,    78,     0,    85,    19,     1,     0,    85,    20,
    78,     0,    85,    20,     1,     0,    85,    21,    78,     0,
    85,    21,     1,     0,    85,    22,    78,     0,    85,    22,
     1,     0,    80,     0,    79,    24,    80,     0,    79,    24,
     1,     0,    81,     0,    80,    25,    81,     0,    80,    25,
     1,     0,    82,     0,    81,    26,    82,     0,    81,    26,
     1,     0,    81,    27,    82,     0,    81,    27,     1,     0,
    83,     0,    82,    28,    83,     0,    82,    29,    83,     0,
    82,    30,    83,     0,    82,    31,    83,     0,    84,     0,
    83,    12,    84,     0,    83,    12,     1,     0,    83,    13,
    84,     0,    83,    13,     1,     0,    85,     0,    84,    14,
    85,     0,    84,    14,     1,     0,    84,    15,    85,     0,
    84,    15,     1,     0,    84,    16,    85,     0,    84,    16,
     1,     0,    86,     0,    13,    85,     0,    23,    85,     0,
    32,    85,     0,    33,    85,     0,    90,     0,    86,    40,
    77,    41,     0,    86,    36,    87,    37,     0,    86,    32,
     0,    86,    33,     0,    88,     0,     0,    89,     0,    78,
     0,    89,    34,    78,     0,    91,     0,     4,     0,    36,
    77,    37,     0,     3,     0,    42,     0,    43,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    37,    39,    40,    41,    47,    48,    49,    54,    60,    61,
    62,    68,    70,    72,    73,    75,    76,    78,    80,    81,
    83,    91,    92,    98,    99,   101,   102,   107,   114,   115,
   121,   122,   124,   125,   127,   128,   133,   139,   140,   142,
   143,   145,   146,   147,   153,   154,   156,   157,   159,   160,
   162,   163,   164,   165,   166,   168,   169,   175,   176,   178,
   179,   181,   183,   184,   190,   192,   193,   194,   199,   200,
   205,   206,   211,   212,   217,   218,   223,   224,   230,   231,
   232,   238,   239,   240,   246,   247,   248,   253,   254,   260,
   261,   262,   263,   264,   266,   267,   268,   273,   274,   280,
   281,   282,   287,   288,   293,   294,   300,   301,   302,   303,
   304,   306,   307,   308,   309,   310,   312,   313,   315,   317,
   318,   320,   321,   322,   324,   325,   330
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
    46,    47,    47,    47,    48,    48,    48,    48,    49,    49,
    49,    50,    51,    52,    52,    53,    53,    54,    55,    55,
    56,    57,    57,    58,    58,    59,    59,    60,    61,    61,
    62,    62,    63,    63,    64,    64,    64,    65,    65,    66,
    66,    67,    67,    67,    68,    68,    69,    69,    70,    70,
    71,    71,    71,    71,    71,    72,    72,    73,    73,    74,
    74,    75,    76,    76,    77,    78,    78,    78,    78,    78,
    78,    78,    78,    78,    78,    78,    78,    78,    79,    79,
    79,    80,    80,    80,    81,    81,    81,    81,    81,    82,
    82,    82,    82,    82,    83,    83,    83,    83,    83,    84,
    84,    84,    84,    84,    84,    84,    85,    85,    85,    85,
    85,    86,    86,    86,    86,    86,    87,    87,    88,    89,
    89,    90,    90,    90,    91,    91,    91
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     1,     2,     1,     2,     2,
     2,     3,     1,     1,     2,     1,     1,     1,     1,     1,
     1,     3,     3,     1,     0,     1,     3,     2,     4,     4,
     1,     0,     1,     2,     3,     3,     2,     1,     3,     1,
     3,     1,     4,     4,     1,     0,     1,     0,     1,     2,
     1,     1,     1,     1,     1,     2,     2,     1,     0,     5,
     7,     5,     3,     3,     1,     1,     3,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
     3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
     3,     3,     3,     3,     1,     3,     3,     3,     3,     1,
     3,     3,     3,     3,     3,     3,     1,     2,     2,     2,
     2,     1,     4,     4,     2,     2,     1,     0,     1,     1,
     3,     1,     1,     3,     1,     1,     1
};

static const short yydefact[] = {     0,
     0,    18,    19,    20,     8,     4,     1,     2,     5,     0,
     0,    13,    14,    16,    17,     6,     7,     3,    11,    10,
    32,     9,    37,   125,   126,   127,     0,     0,    38,    40,
    42,    15,     0,    48,    31,    33,    25,    12,    36,     0,
    35,     0,    46,    42,   123,     0,    59,     0,     0,     0,
     0,     0,     0,    51,     0,    47,    49,    52,     0,    53,
    54,    55,     0,    65,    66,    79,    82,    85,    90,    95,
   100,   107,   112,   122,    34,     0,     0,    24,    26,    39,
    41,    45,     0,     0,     0,    58,     0,   108,   109,   110,
   111,     0,    30,    29,    50,    56,    57,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,   115,   116,   118,     0,
    28,    23,    22,     0,    44,    43,     0,    64,    63,     0,
   124,    81,    80,   100,    84,    83,    87,    86,    89,    88,
    91,    92,    93,    94,    97,    96,    99,    98,   102,   101,
   104,   103,   106,   105,    68,    67,    70,    69,    72,    71,
    74,    73,    76,    75,    78,    77,   120,     0,   117,   119,
     0,    27,    59,    59,   114,     0,   113,    60,    62,   121,
    59,    61,     0,     0,     0
};

static const short yydefgoto[] = {   183,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    27,
    38,    77,    78,    79,    54,    34,    35,    16,    28,    29,
    30,    83,    55,    56,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
   168,   169,   170,    73,    74
};

static const short yypact[] = {     4,
    33,-32768,-32768,-32768,-32768,-32768,    68,-32768,-32768,     9,
     3,    69,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    69,-32768,-32768,-32768,-32768,-32768,   -31,    32,-32768,    -6,
    18,-32768,     3,   435,    69,-32768,    69,-32768,-32768,    10,
-32768,    45,    47,    17,-32768,    36,   476,    65,   476,   476,
   476,   476,   476,-32768,    23,   435,-32768,-32768,    73,-32768,
-32768,-32768,    26,-32768,    81,    87,    89,   106,   108,    66,
   432,    70,-32768,-32768,-32768,    10,    28,    88,-32768,-32768,
-32768,-32768,    15,   476,    63,-32768,   476,-32768,-32768,-32768,
-32768,    90,-32768,-32768,-32768,-32768,-32768,    27,    96,   110,
   144,   476,   476,   476,   476,   158,   192,   206,   240,   254,
   288,   302,   336,   350,   384,   398,-32768,-32768,   476,   476,
-32768,-32768,-32768,    69,-32768,-32768,   107,-32768,-32768,   112,
-32768,-32768,    87,-32768,-32768,    89,-32768,   106,-32768,   106,
   108,   108,   108,   108,-32768,    66,-32768,    66,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   113,-32768,    92,
    83,-32768,   452,   452,-32768,   476,-32768,   145,-32768,-32768,
   452,-32768,   154,   155,-32768
};

static const short yypgoto[] = {-32768,
-32768,   149,-32768,-32768,   -20,-32768,   146,-32768,-32768,-32768,
-32768,-32768,-32768,    44,   150,-32768,-32768,    20,-32768,   129,
    94,-32768,-32768,-32768,   -56,-32768,   125,-32768,-32768,-32768,
   -45,   -93,-32768,    75,    76,    30,    61,    34,   -14,-32768,
-32768,-32768,-32768,-32768,    -8
};


#define	YYLAST		519


static const short yytable[] = {    95,
    33,    86,    31,    23,    37,    24,     1,    92,     2,    19,
    42,     3,    24,     4,    33,   125,    76,   156,   158,   160,
   162,   164,   166,    93,    44,   167,    97,   132,   122,    24,
    45,    44,    39,    17,    88,    89,    90,    91,   127,    49,
    36,   130,     5,    20,    25,    26,    21,     6,    81,    50,
    82,    25,    26,   -21,    75,   126,    43,    43,    51,    52,
   -58,    94,    53,   128,   123,    40,    41,    44,    25,    26,
     1,    84,     2,     2,   171,     3,     3,     4,     4,   108,
   109,   110,   180,   134,   134,   134,   134,   134,   134,   134,
   134,   134,   134,   150,   152,   154,   135,   129,    24,    45,
    87,   117,   118,    76,    98,   119,     5,    96,    49,   120,
   137,    99,    24,    45,   100,   101,   178,   179,    50,   106,
   107,   124,    49,   177,   182,   176,   131,    51,    52,   138,
   140,    53,    50,   102,   103,   104,   105,    25,    26,   146,
   148,    51,    52,   173,   139,    53,    24,    45,   174,   175,
   181,    25,    26,   184,   185,    18,    49,    32,   145,    22,
    24,    45,   141,   142,   143,   144,    50,   172,    80,   121,
    49,    85,   133,     0,   136,    51,    52,     0,     0,    53,
    50,     0,     0,     0,     0,    25,    26,     0,     0,    51,
    52,     0,   147,    53,    24,    45,     0,     0,     0,    25,
    26,     0,     0,     0,    49,     0,   149,     0,    24,    45,
     0,     0,     0,     0,    50,     0,     0,     0,    49,     0,
     0,     0,     0,    51,    52,     0,     0,    53,    50,     0,
     0,     0,     0,    25,    26,     0,     0,    51,    52,     0,
   151,    53,    24,    45,     0,     0,     0,    25,    26,     0,
     0,     0,    49,     0,   153,     0,    24,    45,     0,     0,
     0,     0,    50,     0,     0,     0,    49,     0,     0,     0,
     0,    51,    52,     0,     0,    53,    50,     0,     0,     0,
     0,    25,    26,     0,     0,    51,    52,     0,   155,    53,
    24,    45,     0,     0,     0,    25,    26,     0,     0,     0,
    49,     0,   157,     0,    24,    45,     0,     0,     0,     0,
    50,     0,     0,     0,    49,     0,     0,     0,     0,    51,
    52,     0,     0,    53,    50,     0,     0,     0,     0,    25,
    26,     0,     0,    51,    52,     0,   159,    53,    24,    45,
     0,     0,     0,    25,    26,     0,     0,     0,    49,     0,
   161,     0,    24,    45,     0,     0,     0,     0,    50,     0,
     0,     0,    49,     0,     0,     0,     0,    51,    52,     0,
     0,    53,    50,     0,     0,     0,     0,    25,    26,     0,
     0,    51,    52,     0,   163,    53,    24,    45,     0,     0,
     0,    25,    26,     0,     0,     0,    49,     0,   165,     0,
    24,    45,     0,     0,     0,     0,    50,     0,     0,     0,
    49,     0,     0,     0,     0,    51,    52,     0,     0,    53,
    50,     0,     0,     0,     0,    25,    26,     0,     0,    51,
    52,     0,     0,    53,     0,     0,     0,    24,    45,    25,
    26,    46,     0,    47,     0,    48,     0,    49,   111,   112,
   113,   114,   115,   116,    24,    45,     0,    50,    46,     0,
    47,     0,    48,     0,    49,     0,    51,    52,     0,   -59,
    53,     0,    21,     0,    50,     0,    25,    26,    24,    45,
     0,     0,     0,    51,    52,     0,     0,    53,    49,    21,
     0,     0,     0,    25,    26,     0,     0,     0,    50,     0,
     0,     0,     0,     0,     0,     0,     0,    51,    52,     0,
     0,    53,     0,     0,     0,     0,     0,    25,    26
};

static const short yycheck[] = {    56,
    21,    47,    11,     1,    36,     3,     3,    53,     5,     1,
    17,     8,     3,    10,    35,     1,    37,   111,   112,   113,
   114,   115,   116,     1,    33,   119,     1,     1,     1,     3,
     4,    40,     1,     1,    49,    50,    51,    52,    84,    13,
    21,    87,    39,    35,    42,    43,    38,    44,     4,    23,
     4,    42,    43,    36,    35,    41,    40,    40,    32,    33,
    35,    39,    36,     1,    37,    34,    35,    76,    42,    43,
     3,    36,     5,     5,   120,     8,     8,    10,    10,    14,
    15,    16,   176,    98,    99,   100,   101,   102,   103,   104,
   105,   106,   107,   108,   109,   110,     1,    35,     3,     4,
    36,    32,    33,   124,    24,    36,    39,    35,    13,    40,
     1,    25,     3,     4,    26,    27,   173,   174,    23,    12,
    13,    34,    13,    41,   181,    34,    37,    32,    33,   100,
   101,    36,    23,    28,    29,    30,    31,    42,    43,   106,
   107,    32,    33,    37,     1,    36,     3,     4,    37,    37,
     6,    42,    43,     0,     0,     7,    13,    12,     1,    10,
     3,     4,   102,   103,   104,   105,    23,   124,    40,    76,
    13,    47,    98,    -1,    99,    32,    33,    -1,    -1,    36,
    23,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    32,
    33,    -1,     1,    36,     3,     4,    -1,    -1,    -1,    42,
    43,    -1,    -1,    -1,    13,    -1,     1,    -1,     3,     4,
    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    13,    -1,
    -1,    -1,    -1,    32,    33,    -1,    -1,    36,    23,    -1,
    -1,    -1,    -1,    42,    43,    -1,    -1,    32,    33,    -1,
     1,    36,     3,     4,    -1,    -1,    -1,    42,    43,    -1,
    -1,    -1,    13,    -1,     1,    -1,     3,     4,    -1,    -1,
    -1,    -1,    23,    -1,    -1,    -1,    13,    -1,    -1,    -1,
    -1,    32,    33,    -1,    -1,    36,    23,    -1,    -1,    -1,
    -1,    42,    43,    -1,    -1,    32,    33,    -1,     1,    36,
     3,     4,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
    13,    -1,     1,    -1,     3,     4,    -1,    -1,    -1,    -1,
    23,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    32,
    33,    -1,    -1,    36,    23,    -1,    -1,    -1,    -1,    42,
    43,    -1,    -1,    32,    33,    -1,     1,    36,     3,     4,
    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    13,    -1,
     1,    -1,     3,     4,    -1,    -1,    -1,    -1,    23,    -1,
    -1,    -1,    13,    -1,    -1,    -1,    -1,    32,    33,    -1,
    -1,    36,    23,    -1,    -1,    -1,    -1,    42,    43,    -1,
    -1,    32,    33,    -1,     1,    36,     3,     4,    -1,    -1,
    -1,    42,    43,    -1,    -1,    -1,    13,    -1,     1,    -1,
     3,     4,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
    13,    -1,    -1,    -1,    -1,    32,    33,    -1,    -1,    36,
    23,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    32,
    33,    -1,    -1,    36,    -1,    -1,    -1,     3,     4,    42,
    43,     7,    -1,     9,    -1,    11,    -1,    13,    17,    18,
    19,    20,    21,    22,     3,     4,    -1,    23,     7,    -1,
     9,    -1,    11,    -1,    13,    -1,    32,    33,    -1,    35,
    36,    -1,    38,    -1,    23,    -1,    42,    43,     3,     4,
    -1,    -1,    -1,    32,    33,    -1,    -1,    36,    13,    38,
    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    23,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    -1,
    -1,    36,    -1,    -1,    -1,    -1,    -1,    42,    43
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

case 4:
#line 42 "parser.y"
{
						yyerrok;
						printError(illch);	/* error - Lillegal character */
					;
    break;}
case 7:
#line 50 "parser.y"
{
						yyerrok;
						printError(wrong_st);	/* error - Wrong Statement */
					;
    break;}
case 8:
#line 55 "parser.y"
{
						yyerrok;
						printError(nobrace);	/* error - Missing brace */
					;
    break;}
case 11:
#line 63 "parser.y"
{
						yyerrok;
						printError(wrong_funcdef);	/* error - Wrong function definition */
					;
    break;}
case 19:
#line 80 "parser.y"
{returntp = 1;;
    break;}
case 20:
#line 81 "parser.y"
{returntp = 0;;
    break;}
case 21:
#line 84 "parser.y"
{
						curid->tp = 2;
						curid->rtp = returntp;
						preid = curid;
						paramidx = 0;
					;
    break;}
case 23:
#line 93 "parser.y"
{
						yyerrok;
						printError(noparen);	/* error - Missing paren */
					;
    break;}
case 28:
#line 108 "parser.y"
{
						curid->tp = type;
						preid->param[paramidx++] = curid->index;
						preid->paramnum++;
					;
    break;}
case 30:
#line 116 "parser.y"
{
						yyerrok;
						printError(nobrace);	/* error - Missing brace */
					;
    break;}
case 36:
#line 129 "parser.y"
{
						yyerrok;
						printError(nosemi);	/* error - Missing semicolon */
					;
    break;}
case 37:
#line 134 "parser.y"
{
						yyerrok;
						printError(wrong_dcl);	/* error - wrong declaration */
					;
    break;}
case 42:
#line 145 "parser.y"
{curid->tp = 0;;
    break;}
case 43:
#line 146 "parser.y"
{curid->tp = 1;;
    break;}
case 44:
#line 148 "parser.y"
{
						yyerrok;
						printError(nosquare);	/* error - Missing square */
					;
    break;}
case 57:
#line 170 "parser.y"
{
						yyerrok;
						printError(nosemi);	/* error - Missing semicolon */
					;
    break;}
case 64:
#line 185 "parser.y"
{
						yyerrok;
						printError(nosemi);	/* error - Missing semicolon */
					;
    break;}
case 68:
#line 195 "parser.y"
{
						yyerrok;
						printError(wrong_asgn);	/* error - Wrong assignment */
					;
    break;}
case 70:
#line 201 "parser.y"
{
						yyerrok;
						printError(wrong_asgn);	/* error - Wrong assignment */
					;
    break;}
case 72:
#line 207 "parser.y"
{
						yyerrok;
						printError(wrong_asgn);	/* error - Wrong assignment */
					;
    break;}
case 74:
#line 213 "parser.y"
{
						yyerrok;
						printError(wrong_asgn);	/* error - Wrong assignment */
					;
    break;}
case 76:
#line 219 "parser.y"
{
						yyerrok;
						printError(wrong_asgn);	/* error - Wrong assignment */
					;
    break;}
case 78:
#line 225 "parser.y"
{
						yyerrok;
						printError(wrong_asgn);	/* error - Wrong assignment */
					;
    break;}
case 81:
#line 233 "parser.y"
{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					;
    break;}
case 84:
#line 241 "parser.y"
{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					;
    break;}
case 87:
#line 249 "parser.y"
{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					;
    break;}
case 89:
#line 255 "parser.y"
{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					;
    break;}
case 97:
#line 269 "parser.y"
{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					;
    break;}
case 99:
#line 275 "parser.y"
{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					;
    break;}
case 102:
#line 283 "parser.y"
{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					;
    break;}
case 104:
#line 289 "parser.y"
{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					;
    break;}
case 106:
#line 295 "parser.y"
{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					;
    break;}
case 126:
#line 326 "parser.y"
{
						yyerrok;
						printError(toolong);	/* error - too long identifier */
					;
    break;}
case 127:
#line 331 "parser.y"
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
#line 336 "parser.y"


