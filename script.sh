#!/bin/bash

flex calc-lexico.l 
bison -d calc-sintaxis.y
gcc -o treeManagement.o -c treeManagement.c
#gcc -c -g treeManagement.c
#ar -rc libtreeManagement.a treeManagement.o
#gcc lex.yy.c calc-sintaxis.tab.c -L. -ltreeManagement
gcc lex.yy.c calc-sintaxis.tab.c treeManagement.o
