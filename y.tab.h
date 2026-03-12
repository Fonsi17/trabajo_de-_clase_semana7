/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    VAR = 258,                     /* VAR  */
    PRINT = 259,                   /* PRINT  */
    INT_TYPE = 260,                /* INT_TYPE  */
    CHAR_TYPE = 261,               /* CHAR_TYPE  */
    DOUBLE_TYPE = 262,             /* DOUBLE_TYPE  */
    BOOL_TYPE = 263,               /* BOOL_TYPE  */
    STRING_TYPE = 264,             /* STRING_TYPE  */
    COLON = 265,                   /* COLON  */
    SEMICOLON = 266,               /* SEMICOLON  */
    LBRACKET = 267,                /* LBRACKET  */
    RBRACKET = 268,                /* RBRACKET  */
    ASSIGN = 269,                  /* ASSIGN  */
    LPARENT = 270,                 /* LPARENT  */
    RPARENT = 271,                 /* RPARENT  */
    PLUS = 272,                    /* PLUS  */
    SUB = 273,                     /* SUB  */
    IDENTIFIER = 274,              /* IDENTIFIER  */
    INT_LITERAL = 275,             /* INT_LITERAL  */
    NUMBER = 276,                  /* NUMBER  */
    DOUBLE_LITERAL = 277,          /* DOUBLE_LITERAL  */
    CHAR_LITERAL = 278,            /* CHAR_LITERAL  */
    BOOL_LITERAL = 279,            /* BOOL_LITERAL  */
    STRING_LITERAL = 280,          /* STRING_LITERAL  */
    MULT = 281,                    /* MULT  */
    DIV = 282                      /* DIV  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define VAR 258
#define PRINT 259
#define INT_TYPE 260
#define CHAR_TYPE 261
#define DOUBLE_TYPE 262
#define BOOL_TYPE 263
#define STRING_TYPE 264
#define COLON 265
#define SEMICOLON 266
#define LBRACKET 267
#define RBRACKET 268
#define ASSIGN 269
#define LPARENT 270
#define RPARENT 271
#define PLUS 272
#define SUB 273
#define IDENTIFIER 274
#define INT_LITERAL 275
#define NUMBER 276
#define DOUBLE_LITERAL 277
#define CHAR_LITERAL 278
#define BOOL_LITERAL 279
#define STRING_LITERAL 280
#define MULT 281
#define DIV 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "parser.y"

    int i_val;
    int n_val;
    int b_val;
    double d_val;
    char c_val;
    char* s_val;
    int type_enum;
    struct SymbolEntry *entry;

#line 132 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
