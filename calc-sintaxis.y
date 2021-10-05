%{

#include <stdlib.h>
#include <stdio.h>

int yylex();
int yyerror(char *);

%}
 
%union { int i; char *s;}
 
%token<i> INT 
%token<s> ID TMENOS BTRUE BFALSE EQUAL LOWER HIGHER TMINUS TNOT TPLUS TMOD TDIV TMULT TOR TAND PROGRAM EXTERN WHILE BOOL INTEGER IF ELSE THEN VOID RETURN

%left AND OR
%nonassoc LOWER HIGHER EQUAL
%left TPLUS TMINUS
%left TMULT TDIV TMOD
%left UNARY
%%
program: PROGRAM '{' variables methods '}'  
       | PROGRAM '{' methods '}' 
       | PROGRAM '{' variables '}' 
       | PROGRAM '{' '}' 
;  

variables: variables v_declaration  
         | v_declaration
;

v_declaration: type ides ';' ;

ides: ID ',' ides           
    | ID 
;

methods: methods m_declaration
        | m_declaration
;

m_declaration: method_type '(' typeides ')' m_declaration_final 
           | method_type '(' ')' m_declaration_final 
;

method_type: type ID 
            | VOID ID 
;

m_declaration_final: block
                 | EXTERN ';'
;

typeides: type ID ',' typeides { } 
        | type ID
;

block: '{' variables statements '}' { } 
     | '{' statements '}' 
     | '{' variables '}' 
     | '{' '}' 
;

statements: statement statements { }
          | statement
;

type: INTEGER
    | BOOL 
;

statement: ID '=' expression ';' 
         | method_call ';' 
         | if_stmt
         | WHILE expression block 
         | return_stmt
         | block 
         | ';' 
;

return_stmt: RETURN expression
           | RETURN ';'
;

if_stmt: IF '(' expression ')' THEN block
       | IF '(' expression ')' THEN block ELSE block
;

method_call: ID '(' expressions ')'
           | ID '(' ')' 
;

expressions: expressions ',' expression
     | expression 
;

expression:ID
        | method_call
        | literal
        | expr_bin
        | TMINUS expression %prec UNARY
        | TNOT expression %prec UNARY
        | '(' expression ')'
;

expr_bin: expression TPLUS expression
        | expression TMINUS expression
        | expression  TMULT expression
        | expression  TDIV expression
        | expression  TMOD expression
        | expression LOWER expression
        | expression  HIGHER expression
        | expression  EQUAL expression
        | expression  AND expression
        | expression OR expression
        ;

literal: INT 
       | BTRUE
       | BFALSE
;
%%
