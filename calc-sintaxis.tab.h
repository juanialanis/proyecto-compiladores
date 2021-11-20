/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     ID = 259,
     BTRUE = 260,
     BFALSE = 261,
     EQUAL = 262,
     LOWER = 263,
     HIGHER = 264,
     TMINUS = 265,
     TNOT = 266,
     TPLUS = 267,
     TMOD = 268,
     TDIV = 269,
     TMULT = 270,
     TOR = 271,
     TAND = 272,
     PROGRAM = 273,
     EXTERN = 274,
     WHILE = 275,
     BOOL = 276,
     INTEGER = 277,
     IF = 278,
     ELSE = 279,
     THEN = 280,
     VOID = 281,
     RETURN = 282,
     UNARY = 283
   };
#endif
/* Tokens.  */
#define INT 258
#define ID 259
#define BTRUE 260
#define BFALSE 261
#define EQUAL 262
#define LOWER 263
#define HIGHER 264
#define TMINUS 265
#define TNOT 266
#define TPLUS 267
#define TMOD 268
#define TDIV 269
#define TMULT 270
#define TOR 271
#define TAND 272
#define PROGRAM 273
#define EXTERN 274
#define WHILE 275
#define BOOL 276
#define INTEGER 277
#define IF 278
#define ELSE 279
#define THEN 280
#define VOID 281
#define RETURN 282
#define UNARY 283




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 20 "calc-sintaxis.y"
{ int i; char *s; struct treeN *tn; struct idList* idL;}
/* Line 1529 of yacc.c.  */
#line 107 "calc-sintaxis.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

