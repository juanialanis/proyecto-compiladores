#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "treeManagement.h"
#define COUNT 15

char* TLabelString[] = { "VDECL", "NONE", "NONEBLOCK", "BLOCKDECL", "IFTHEN", "IFTELSE", "MCALL" ,"MDECL", "MDECLTYPE", "EXT", "STMT","STMTASSIGN", "STMTWHILE", "SUMA", "MULTIPLICACION", "RESTA", "SEMICOLON", "DIVISION", "LAND", "LOR", "MAYOR","MENOR", "COMMA", "NEGATIVEEXP", "NOTEXP" ,"LMOD","LEQUAL","PROG", "RET"};

char* TTypeString[] = {"None", "Int", "Bool", "Void" };

//table of symbols
stStack* stackOfLevels;


ids* newIdList(char* id, ids *next){
    ids *newIds = (ids*) malloc(sizeof(ids));
    newIds->idName = id;
    newIds->next = next;    
    return newIds;
}

//method that create a new tree
tree* newTree(node* newatr, tree *newleft, tree *newright){
    tree *newTree = (tree*) malloc(sizeof(tree));
    newTree->atr = newatr;
    newTree->left = newleft;    
    newTree->right = newright;
    return newTree;
}


node* newNode(int value,int line, enum TType type, enum TLabel label, char* text, ids* idList){
    node* newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->line = line;
    newNode->type = type;
    newNode->label = label;
    newNode->text = text;
    newNode->idList = idList;
    return newNode;
}

//as the concatenation gave us a lot of problems, we finally decided to use this option that we found in
//https://es.stackoverflow.com/questions/146607/c%C3%B3mo-concatenar-cadenas-de-car%C3%A1cteres-sin-usar-la-funci%C3%B3n-strcat
// and later has modified by our needs
char* cat(char *s1, char *s2) {
  if (!s1 || !s2)
    return s1? s1: s2;

  int len = strlen(s1), len2 = strlen(s2);
  char* result = malloc(len+len2);
  int x;
  for(int i = 0; i < len; i++){
      result[i] = s1[i];
      x = i + 1;
  }
  for(int j = 0; j < len2; j++){
      result[(x+j)] = s2[j];
  }
  return result; 
}

//method that take an int value and parse it to char*
char* getValue(int i) {
    char* result = malloc(1);
    result[0] = '0'+i;
    return result;
}

//method that take an node* of an tree and parse it to a char* with all the fields of the tree
char* treetoString(node* atr){
    char* value = cat("Value: ", getValue(atr->value));
    char* type = TTypeString[atr->type];
    char* text = ",Type: ";
    char* result = cat(text,type);
    result = cat(value,result);
    text = ",Label: ";
    result = cat(result,text);
    char* label = TLabelString[atr->label];
    result = cat (result, label);
    char* line = cat(",Line: ", getValue(atr->line));
    result = cat(result,line);
    result = cat(result, ",Text: ");
    result = cat(result,atr->text != NULL ? atr->text : "");
    result = cat(result, " IDS:  ");
    ids* listIds = atr->idList;
    while(listIds != NULL) {
        result = cat(result, listIds->idName);
        result = cat(result, ", ");
        listIds = listIds->next;
    }
    printf("%s\n", result);
    return result;
}


/*
//method that generates a sample of the tree
void printTree(tree* tree){
    if(tree==NULL)
        return;
    space += COUNT;

    printInOrderTree(tree->right, space);
    for (int i = COUNT; i < space; i++)
        printf(" ");
    treetoString(tree->atr);
    printInOrderTree(tree->left, space);
}
*/
void printTree(tree* tree, int space) {
    if(tree==NULL)
        return;
    space += COUNT;

    printTree(tree->right, space);
    for (int i = COUNT; i < space; i++)
        printf(" ");
    treetoString(tree->atr);
    printTree(tree->left, space);
} 

//method that creates a new table of symbols
symbolTable* newTableOfSymbols(node* s){
    symbolTable* newTable = malloc(sizeof(symbolTable));
    newTable->cSymbol = s;
    newTable->next = NULL;
    return newTable;
}

void addLast(symbolTable* new, symbolTable* head) {
    if (searchSimbol(new->cSymbol->text, head)== 1)
    {
        printf("The variable %s is already declared at line %d \n", new->cSymbol->text, new->cSymbol->line);
        exit(-1);
    }

    symbolTable* st = head;
    if (st == NULL)
    {
        head = new;
        printf("    csybol:  ");
        treetoString(new->cSymbol);
        printf("    head:  ");
        treetoString(head->cSymbol);
        return;
    }
    while (st->next != NULL) {
        st = st->next;
    }
    st->next = new;
    return;
}

int searchSimbol(char* id, symbolTable* st) {

    while (st != NULL) {
        printf("text: %s id: %s",st->cSymbol->text, id);
        if (!strcmp(st->cSymbol->text,id))
            return 1;
        st = st->next;
    }
    return 0;
}

stStack* newStack(symbolTable* s){
    stStack* newStack = malloc(sizeof(stStack));
    newStack->tope = s;
    newStack->next = NULL;
    return newStack;
}

stStack* addLevel(symbolTable* s){
    stStack* newStack = malloc(sizeof(stStack));
    newStack->tope = s;
    newStack->next = NULL;
    return newStack;
}


void createLevelOfSymbolTable(tree* tree) {
    symbolTable* st = NULL;
    createLevelZero(tree,st);
    stackOfLevels = newStack(st);
    
    createLevels(tree);
}

void createLevelZero(tree* tree, symbolTable* tope) {
    if(tree==NULL)
        return;
    if(tree->atr->label == MDECL)
    {
        if (tree->left->atr->label == MDECLTYPE)
        {
            symbolTable* st = newTableOfSymbols(tree->left->left->atr);
            printf("st:  ");
            treetoString(st->cSymbol);
            addLast(st, tope);
            printf("despues del add:  ");
            treetoString(tope->cSymbol);
        }
        else {
            treetoString(tree->left->atr);
            symbolTable* st = newTableOfSymbols(tree->left->atr);
            addLast(st, tope);
        }
    }
    else if(tree->atr->label == VDECL) {
        node* idNode;
        ids* ids = tree->left->atr->idList;
        while (ids != NULL) {
            idNode = newNode(tree->left->atr->value, tree->left->atr->line, tree->left->atr->type, tree->left->atr->label, ids->idName, NULL);
            treetoString(idNode);
            symbolTable* st = newTableOfSymbols(idNode);
            addLast(st, tope);
            ids = ids->next;
        }
    }
    else if(tree->atr->label == BLOCKDECL)
    {
        return;
    }
    createLevelZero(tree->left, tope);
    createLevelZero(tree->right, tope);
}

void createLevels(tree* tree) {
    if(tree==NULL)
        return;
    if (tree->atr->label == MDECL && tree->left->atr->label == MDECLTYPE && tree->right->atr->label == BLOCKDECL)
    {
        symbolTable* st2 = NULL;
        stStack* newStackLevel = newStack(st2);
        newStackLevel->next = stackOfLevels;
        stackOfLevels = newStackLevel;
        createSubTableSymbol(tree->left->right, st2);
        createLevels(tree->right);
        //free(stackOfLevels);
        stackOfLevels = newStackLevel->next;

    }
    else if (tree->atr->label == BLOCKDECL)
    {
        //creo tabla de simboloss
        symbolTable* st2 = NULL;
        stStack* newStackLevel = newStack(st2);
        newStackLevel->next = stackOfLevels;
        stackOfLevels = newStackLevel;
        createSubTableSymbol(tree->left, st2);
        createLevels(tree->right);
        //free(stackOfLevels);
        stackOfLevels = newStackLevel->next;
    }
    else {
        createLevels(tree->left);
        createLevels(tree->right);

    }

}


void createSubTableSymbol(tree* tree, symbolTable* tope) {
    if(tree==NULL)
        return;
    if(tree->atr->label == VDECL) {
        node* idNode;
        ids* ids = tree->left->atr->idList;
        while (ids != NULL) {
            idNode = newNode(tree->left->atr->value, tree->left->atr->line, tree->left->atr->type, tree->left->atr->label, ids->idName, NULL);
            printf("    ");
            treetoString(idNode);
            symbolTable* st = newTableOfSymbols(idNode);
            addLast(st, tope);
            ids = ids->next;
        }
    }
    else if (tree->atr->text != NULL) {
        printf("  ");
        treetoString(tree->atr);
        symbolTable* st = newTableOfSymbols(tree->atr);
        addLast(st, tope);
    }
    createSubTableSymbol(tree->left, tope);
    createSubTableSymbol(tree->right, tope);
}
