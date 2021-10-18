#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "treeManagement.h"


//method that returns the string equivalent to the types
char* getType(enum TType type){
    switch(type){
        case None: return "None";
        case Bool: return "Bool";
        case Int: return "Int";
        case Void: return "Void";
    }
}


//method that returns the string equivalent to the labels
char* getLabel(enum TLabel label){
    switch(label){
        case NONE: return "NONE";
        case MDECL: return "MDECL";
        case VDECL: return "VDECL";
        case STMT: return "STMT";
        case SUMA: return "SUMA";
        case MULTIPLICACION: return "MULTIPLICACION";
        case RESTA: return "RESTA";
        case RET: return "RETURN";
        case PROG: return "PROG";
        case SEMICOLON: return "SEMICOLON";
        default: return "NO LABEL SELECTED";
    }
}

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
    char* type = getType(atr->type);
    char* text = ",Type: ";
    char* result = cat(text,type);
    result = cat(value,result);
    text = ",Label: ";
    result = cat(result,text);
    char* label = getLabel(atr->label);
    result = cat (result, label);
    char* line = cat(",Line: ", getValue(atr->line));
    result = cat(result,line);
    result = cat(result, ",Text: ");
    result = cat(result,atr->text != NULL ? atr->text : "");
    return result;
}

//method that generates a sample of the tree
void printTree(tree* tree){
    printf("{ \n node*: { %s }\n", treetoString(tree->atr));
    printf("\n HI: \n");
    tree->left != NULL ? printTree(tree->left) : printf("NULL \n");
    printf("\n HD: \n");
    tree->right != NULL ? printTree(tree->right) : printf("NULL \n");
    printf("}\n");
}

