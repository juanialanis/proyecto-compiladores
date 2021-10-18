%{

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "treeManagement.h"

extern int yylineno;

//table of symbols
stStack* stackOfLevels = NULL;

int yylex();
int yyerror(char *);

%}
 
%union { int i; char *s; struct treeN *tn; struct idList* idL;}
 
%token<i> INT 
%token<s> ID BTRUE BFALSE EQUAL LOWER HIGHER TMINUS TNOT TPLUS TMOD TDIV TMULT TOR TAND PROGRAM EXTERN WHILE BOOL INTEGER IF ELSE THEN VOID RETURN

%type<tn> prog variables methods v_declaration m_declaration method_type typeides m_declaration_final block statements statement method_call expression if_stmt return_stmt 
%type<tn> expr_bin literal expressions
%type<idL> ides
%type<i> type


%left TAND TOR
%nonassoc LOWER HIGHER EQUAL
%left TPLUS TMINUS
%left TMULT TDIV TMOD
%left UNARY
%%

prog: PROGRAM '{' variables methods '}'  { 
                                                node* root = newNode(0, yylineno, None, PROG, NULL, NULL);
                                                $$ = newTree(root, $3, $4); 
                                                //printTree($$,0);
                                                createLevelOfSymbolTable($$);
                                        };
       | PROGRAM '{' methods '}'          { 
                                                node* root = newNode(0, yylineno, None, PROG, NULL, NULL);
                                                $$ = newTree(root, $3, NULL); 
                                                createLevelOfSymbolTable($$);
                                        };      
       | PROGRAM '{' variables '}'      { 
                                                node* root = newNode(0, yylineno, None, PROG, NULL, NULL);
                                                $$ = newTree(root, NULL, $3); 
                                                printf("estoy aca 3 ");
                                                createLevelOfSymbolTable($$);
                                        };
       | PROGRAM '{' '}'                { 
                                                node* root = newNode(0, yylineno, None, PROG, NULL, NULL);
                                                $$ = newTree(root, NULL, NULL); 
                                                printf("estoy aca 4");
                                                createLevelOfSymbolTable($$);
                                        };
;  

variables: variables v_declaration      {
                                                node* root = newNode(0, yylineno, None, SEMICOLON, NULL, NULL);
                                                $$ = newTree(root, $1, $2); 
                                        }
         | v_declaration                {
                                                $$ = $1;
                                        }
;

v_declaration: type ides ';'   {
                                        node* root = newNode(0, yylineno, None, VDECL, NULL, NULL);
                                        node* sonL = newNode(0, yylineno, $1, NONE, NULL, $2);
                                        tree* newTL = newTree(sonL, NULL, NULL);
                                        $$ = newTree(root, newTL, NULL);
                                }
;

ides: ID ',' ides   {
                        $$ = newIdList($1,$3);
                    }          
    | ID            {
                        $$ = newIdList($1,NULL);
                    }
;

methods: methods m_declaration  {
                                        node* root = newNode(0, yylineno, None, SEMICOLON, NULL, NULL);
                                        $$ = newTree(root, $1, $2); 
                                }
        | m_declaration         {
                                        $$ = $1;  
                                }
;

m_declaration: method_type '(' typeides ')' m_declaration_final {
                                                                        node* root = newNode(0, yylineno, None, MDECL, NULL, NULL);
                                                                        node* left = newNode(0, yylineno, None, MDECLTYPE, NULL, NULL);
                                                                        tree* leftTree = newTree(left, $1, $3);
                                                                        $$ = newTree(root, leftTree, $5);
                                                                }
           | method_type '(' ')' m_declaration_final            {
                                                                        node* root = newNode(0, yylineno, None, MDECL, NULL, NULL);
                                                                        node* left = newNode(0, yylineno, None, MDECLTYPE, NULL, NULL);
                                                                        tree* leftTree = newTree(left, $1, NULL);
                                                                        $$ = newTree(root, leftTree, $4);
                                                                }
;

method_type: type ID    {
                                node* root = newNode(0, yylineno, $1, NONE, $2,NULL);
                                $$ = newTree(root, NULL, NULL);
                        }
            | VOID ID   {
                                node* root = newNode(0, yylineno, Void, NONE, $2,NULL);
                                treetoString(root);
                                $$ = newTree(root, NULL, NULL);
                        }
;

m_declaration_final: block      { 
                                        $$ = $1;
                                }
                 | EXTERN ';'   {
                                        node* root = newNode(0, yylineno, None, EXT, NULL, NULL);
                                        $$ = newTree(root,NULL,NULL);
                                }
;

typeides: type ID ',' typeides {    
                                    node* left = newNode(0, yylineno, $1, NONE, $2, NULL);
                                    tree* leftTree = newTree(left, NULL, NULL);
                                    node* root = newNode(0, yylineno, None, COMMA, NULL, NULL);
                                    $$ = newTree(root, leftTree, $4);  
                               } 
        | type ID      {
                                node* root = newNode(0, yylineno, $1, NONE, $2, NULL);
                                $$ = newTree(root,NULL,NULL);
                       }
;

block: '{' variables statements '}'     {
                                                node* root = newNode(0, yylineno, None, BLOCKDECL, NULL, NULL);
                                                $$= newTree(root,$2,$3);
                                        }       
        | '{' statements '}'            {
                                                node* root = newNode(0, yylineno, None, BLOCKDECL, NULL, NULL);
                                                $$= newTree(root,NULL,$2);
                                        } 
        | '{' variables '}'             {
                                                node* root = newNode(0, yylineno, None, BLOCKDECL, NULL, NULL);
                                                $$= newTree(root,$2,NULL);
                                        } 
        | '{' '}'       {
                                node* root = newNode(0, yylineno, None, NONEBLOCK, NULL, NULL);
                                $$ = newTree(root,NULL,NULL);   
                        }
;

statements: statement statements        { 
                                                node* root = newNode(0, yylineno, None, STMT, NULL, NULL);
                                                $$ = newTree(root, $1, $2);
                                        }
          | statement   { 
                                $$ = $1;
                        }
;

type: INTEGER   {
                        $$ = Int;
                }
    | BOOL      {
                        $$ = Bool;
                }
;

statement: ID '=' expression ';'        {
                                                node* root = newNode(0, yylineno, None, STMTASSIGN, NULL, NULL);
                                                node* leftRoot = newNode(0, yylineno, None, NONE, $1, NULL);
                                                tree* leftTree = newTree(leftRoot, NULL, NULL);
                                                $$ = newTree(root, leftTree, $3);   
                                        }
         | method_call ';'              {
                                                $$ = $1;
                                        }
         | if_stmt                      {   
                                                $$ = $1;
                                        }
         | WHILE expression block       {
                                                node* root = newNode(0, yylineno, None, STMTWHILE, NULL, NULL);
                                                $$ = newTree(root,$2, $3); 
                                        }
         | return_stmt                  {
                                                $$ = $1;
                                        }
         | block                        {
                                                $$ = $1;
                                        }
         | ';'                          {
                                                node* root = newNode(0, yylineno, None, SEMICOLON, NULL, NULL);
                                                $$ = newTree(root, NULL, NULL); 
                                        }
;

return_stmt: RETURN expression ';' {
                                        node* root = newNode(0, yylineno, None, RET, NULL, NULL);
                                        $$ = newTree(root, NULL, $2);    
                                }
           | RETURN ';'         {
                                        node* root = newNode(0, yylineno, None, RET, NULL, NULL);
                                        $$ = newTree(root, NULL, NULL);    
                                }
;

if_stmt: IF '(' expression ')' THEN block               {
                                                                node* root = newNode(0, yylineno, None, IFTHEN, NULL, NULL);
                                                                $$ = newTree(root,$3,$6);
                                                        }
       | IF '(' expression ')' THEN block ELSE block    {
                                                                node* root = newNode(0, yylineno, None, IFTELSE, NULL, NULL);
                                                                node* leftRoot = newNode(0, yylineno, None, IFTHEN, NULL, NULL);
                                                                tree* leftTree = newTree(leftRoot, $3, $6);
                                                                $$ = newTree(root,leftTree,$8);
                                                        }
;

method_call: ID '(' expressions ')'     {
                                                node* root = newNode(0, yylineno, None, MCALL, NULL, NULL);
                                                node* leftRoot = newNode(0, yylineno, None, NONE, $1, NULL);
                                                tree* leftTree = newTree(leftRoot, NULL, NULL);
                                                $$ = newTree(root,leftTree,$3);
                                        }
           | ID '(' ')'                 {
                                                node* root = newNode(0, yylineno, None, MCALL, NULL, NULL);
                                                node* leftRoot = newNode(0, yylineno, None, NONE, $1, NULL);
                                                tree* leftTree = newTree(leftRoot, NULL, NULL);
                                                $$ = newTree(root,leftTree, NULL);
                                        }
;

expressions: expressions ',' expression         {
                                                        node* root = newNode(0, yylineno, None, COMMA, NULL, NULL);
                                                        $$ = newTree(root,$1,$3);
                                                }
     | expression                               {
                                                        $$ = $1;
                                                }
;

expression:ID   { 
                        node* root = newNode(0, yylineno, None, NONE, $1, NULL);
                        $$ = newTree(root,NULL,NULL);      
                }
        | method_call                           {
                                                        $$ = $1;
                                                }
        | literal                               {   
                                                        $$ = $1;
                                                }
        | expr_bin                              {
                                                        $$ = $1;
                                                }
        | TMINUS expression %prec UNARY         {
                                                        node* root = newNode(0, yylineno, None, NEGATIVEEXP, NULL,NULL);
                                                        $$ = newTree(root, NULL, $2);
                                                }
        | TNOT expression %prec UNARY           {
                                                        node* root = newNode(0, yylineno, None, NOTEXP, NULL,NULL);
                                                        $$ = newTree(root, NULL, $2);
                                                }
        | '(' expression ')'                    { 
                                                        $$ = $2;
                                                }
;

expr_bin: expression TPLUS expression   { 
                                                node* root = newNode(0, yylineno, None, SUMA, NULL, NULL);
                                                $$ = newTree(root,$1,$3);      
                                        }
        | expression TMINUS expression  { 
                                                node* root = newNode(0, yylineno, None, RESTA, NULL, NULL);
                                                $$ = newTree(root,$1,$3);      
                                        }
        | expression  TMULT expression  { 
                                                node* root = newNode(0, yylineno, None, MULTIPLICACION, NULL, NULL);
                                                $$ = newTree(root,$1,$3);      
                                        }
        | expression  TDIV expression   { 
                                                node* root = newNode(0, yylineno, None, DIVISION, NULL, NULL);
                                                $$ = newTree(root,$1,$3);      
                                        }
        | expression  TMOD expression   { 
                                                node* root = newNode(0, yylineno, None, LMOD, NULL, NULL);
                                                $$ = newTree(root,$1,$3);      
                                        }
        | expression LOWER expression   { 
                                                node* root = newNode(0, yylineno, None, MENOR, NULL, NULL);
                                                $$ = newTree(root,$1,$3);      
                                        }
        | expression  HIGHER expression { 
                                                node* root = newNode(0, yylineno, None, MAYOR, NULL, NULL);
                                                $$ = newTree(root,$1,$3);      
                                        }
        | expression  EQUAL expression  { 
                                                node* root = newNode(0, yylineno, None, LEQUAL, NULL, NULL);
                                                $$ = newTree(root,$1,$3);      
                                        }
        | expression  TAND expression    { 
                                                node* root = newNode(0, yylineno, None, LAND, NULL, NULL);
                                                $$ = newTree(root,$1,$3);      
                                        }
        | expression TOR expression      { 
                                                node* root = newNode(0, yylineno, None, LOR, NULL, NULL);
                                                $$ = newTree(root,$1,$3);      
                                        }
        ;

literal: INT    {
                        node* root = newNode($1, 0, Int, NONE, NULL, NULL); 
                        $$ = newTree(root, NULL, NULL);
                }
       | BTRUE  {
                        node* root = newNode(1, 0, Bool, NONE, NULL, NULL); 
                        $$ = newTree(root, NULL, NULL);
                }
       | BFALSE {
                        node* root = newNode(0, 0, Bool, NONE, NULL, NULL); 
                        $$ = newTree(root, NULL, NULL);
                }
;
%%
