#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "treeManagement.h"
#define COUNT 15

char* TLabelString[] = { "PARAM","VAR", "VDECL", "NONE", "NONEBLOCK", "BLOCKDECL", "IFTHEN", "IFTELSE", "MCALL" ,"MDECL", "MDECLTYPE", "EXT", "STMT","STMTASSIGN", "STMTWHILE", "SUMA", "MULTIPLICACION", "RESTA", "SEMICOLON", "DIVISION", "LAND", "LOR", "MAYOR","MENOR", "COMMA", "NEGATIVEEXP", "NOTEXP" ,"LMOD","LEQUAL","PROG", "RET", "CONST", "IC_BEGIN_FUNCTION", "IC_END_FUNCTION", "IC_LOAD", "LABEL", "JUMPFALSE", "JUMP"};

char* TTypeString[]  = {"None", "Int", "Bool", "Void" };

// table of symbols
stStack* stackOfLevels;


params* newParam(enum TType type){
    params* newParam = (params*) malloc(sizeof(params));
    newParam->type = type;
    newParam->next = NULL;
    return newParam;
}

ids* newIdList(char* id, ids *next){
    ids *newIds = (ids*) malloc(sizeof(ids));
    newIds->idName = id;
    newIds->next = next;    
    return newIds;
}

// method that create a new tree
tree* newTree(node* newatr, tree *newleft, tree *newright){
    tree *newTree = (tree*) malloc(sizeof(tree));
    newTree->atr = newatr;
    newTree->left = newleft;    
    newTree->right = newright;
    return newTree;
}


node* newNode(int value,int line, enum TType type, enum TLabel label, char* text, ids* idList, params* paramList){
    node* newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->line = line;
    newNode->type = type;
    newNode->label = label;
    newNode->text = text;
    newNode->idList = idList;
    newNode->paramList = paramList;
    return newNode;
}

threeDir* newInstruction(enum TLabel instruction, node* operator1, node* operator2, node* result) {
    threeDir* newInstruction = (threeDir*) malloc(sizeof(threeDir));
    newInstruction->name = instruction;
    newInstruction->op1 = operator1;
    newInstruction->op2 = operator2;
    newInstruction->resu = result;
    return newInstruction;
}

listThreeDir* newThreeDirElement(threeDir* element) {
    listThreeDir* newThreeDirElement = (listThreeDir*) malloc(sizeof(listThreeDir));
    newThreeDirElement->node = element;
    newThreeDirElement->next = NULL;
    return newThreeDirElement;
}

void insertLast(listThreeDir* new) {
    listThreeDir* pointer = threeDirList;
    if (pointer == NULL)
    {
        threeDirList = new;
        return;
    }
    while (pointer->next != NULL) {
        pointer = pointer->next;
    }
    pointer->next = new;
    return;
}

//  as the concatenation gave us a lot of problems, we finally decided to use this option that we found in
//  https://es.stackoverflow.com/questions/146607/c%C3%B3mo-concatenar-cadenas-de-car%C3%A1cteres-sin-usar-la-funci%C3%B3n-strcat
//  and later has modified by our needs
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

// method that take an int value and parse it to char*
char* getValue(int i) {
    char* result = malloc(1);
    result[0] = '0'+i;
    return result;
}

// method that take an node* of an tree and parse it to a char* with all the fields of the tree
void treetoString(node* atr){ 
    if (atr == NULL)
    {   
        printf("\n");
        return;
    }
    
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
}

void printTree(tree* tree, int space) {
    if(tree==NULL)
        return;
    space += COUNT;

    printTree(tree->right, space);
    for (int i = COUNT; i < space; i++)
        printf(" ");
    if (tree->st != NULL && tree->st->cSymbol != NULL){
        treetoString(tree->st->cSymbol);
    } else {
        treetoString(tree->atr);
    }
    printTree(tree->left, space);
} 

void printInstructions() {
    if(threeDirList==NULL)
        return;
    while (threeDirList != NULL)
    {
        printf("\n%s:\n",TLabelString[threeDirList->node->name]);
        treetoString(threeDirList->node->op1);
        treetoString(threeDirList->node->op2);
        treetoString(threeDirList->node->resu);
        printf("\n");
        threeDirList = threeDirList->next;
    }
} 

// method that creates a new table of symbols
symbolTable* newTableOfSymbols(node* s){
    symbolTable* newTable = malloc(sizeof(symbolTable));
    newTable->cSymbol = s;
    newTable->next = NULL;
    return newTable;
}

symbolTable* addLast(symbolTable* new, symbolTable* head) {
    if (searchSimbol(new->cSymbol->text, head)== 1)
    {
        printf("Error at line %d . The variable %s is already declared \n", new->cSymbol->line, new->cSymbol->text);
        exit(-1);
    }
    symbolTable* st = head;
    if (st == NULL)
    {
        head = new;
        return head;
    }
    while (st->next != NULL) {
        st = st->next;
    }
    st->next = new;
    return head;
}

int searchSimbol(char* id, symbolTable* st) {
    while (st != NULL && st->cSymbol != NULL) {
        if (!strcmp(st->cSymbol->text,id))
            return 1;
        st = st->next;
    }
    return 0;
}

stStack* newStack(symbolTable* s) {
    stStack* newStack = malloc(sizeof(stStack));
    newStack->tope = s;
    newStack->next = NULL;
    return newStack;
}

stStack* addLevel(symbolTable* s) {
    stStack* newStack = malloc(sizeof(stStack));
    newStack->tope = s;
    newStack->next = NULL;
    return newStack;
}


void createLevelOfSymbolTable(tree* tree) {
    node* idNode = newNode(0, 0, 0, 0, "", NULL,NULL);
    symbolTable* st = newTableOfSymbols(idNode);
    createLevelZero(tree,st);
    stackOfLevels = newStack(st);
    
    createLevels(tree);
}

void createLevelZero(tree* tree, symbolTable* tope) {
    if(tree==NULL)
        return;
    if(tree->atr->label == MDECL)
    {
        symbolTable* st = newTableOfSymbols(tree->left->left->atr);
        tree->left->left->st = st;
        params* emptyList = newParam(None);
        findParams(tree->left, emptyList);
        st->cSymbol->paramList = emptyList;
        tope = addLast(st, tope);
    }
    else if(tree->atr->label == VDECL) {
        node* idNode;
        ids* ids = tree->left->atr->idList;
        while (ids != NULL) {
            idNode = newNode(tree->left->atr->value, tree->left->atr->line, tree->left->atr->type, tree->left->atr->label, ids->idName, NULL,NULL);
            symbolTable* st = newTableOfSymbols(idNode);
            tree->st = st;
            tope = addLast(st, tope);
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

void findParams(tree* tree, params* paramList){
    if( tree == NULL ) return;
    if( tree->atr->label == PARAM){
        addParam(paramList, tree->atr->type);
    }
    findParams(tree->left,paramList);
    findParams(tree->right,paramList);
}

void addParam(params* paramList, enum TType param){
    if(paramList->type == None){
        paramList->type = param;
    }
    else{
        params* aux = paramList;
        while(aux->next != NULL){
            aux = aux->next;
        }
        params* newPar = newParam(param);
        aux->next = newPar;
    }
}

void createLevels(tree* tree) {
    if(tree==NULL)
        return;
    if (tree->atr->label == MDECL && tree->left->atr->label == MDECLTYPE && tree->right->atr->label == BLOCKDECL)
    {
        node* idNode = newNode(0, 0, 0, 0, "", NULL,NULL);
        symbolTable* st2 = newTableOfSymbols(idNode);
        stStack* newStackLevel = newStack(st2);
        newStackLevel->next = stackOfLevels;
        stackOfLevels = newStackLevel;
        if (tree->left->right != NULL){
            createSubTableSymbol(tree->left->right, st2);
            tree->left->right->st = st2;
        }
        createLevels(tree->right);
        stackOfLevels = newStackLevel->next;

    }
    else if (tree->atr->label == BLOCKDECL)
    {
        //creo tabla de simboloss
        node* idNode = newNode(0, 0, 0, 0, "", NULL,NULL);
        symbolTable* st2 = newTableOfSymbols(idNode);
        stStack* newStackLevel = newStack(st2);
        newStackLevel->next = stackOfLevels;
        stackOfLevels = newStackLevel;
        createSubTableSymbol(tree->left, st2);
        createLevels(tree->right);
        stackOfLevels = newStackLevel->next;
    } 
    else if (tree->atr->label == VAR)
    {
        symbolTable* result = findVariable(tree->atr->text);
        if (result != NULL) {
            tree->st = result;
        }
        createLevels(tree->left);
        createLevels(tree->right);
    }
    else if (tree->atr->label == MCALL){
        symbolTable* result = findVariable(tree->left->atr->text);
        if (result != NULL) {
            tree->st = result;
        }
        createLevels(tree->left);
        createLevels(tree->right);
    }
    else {
        createLevels(tree->left);
        createLevels(tree->right);
    }
}
symbolTable* findVariable(char* id){
    stStack* head = stackOfLevels;
    symbolTable* level;
    int nivel = 0;
    while(head != NULL){
        nivel++;
        level = head->tope;
        while(level != NULL && level->cSymbol != NULL){
            if (strcmp(level->cSymbol->text, id) == 0)
                return level;
            level = level->next;
        }
        head = head->next;
    }
    if(head == NULL && level == NULL){
        printf("Variable %s no declarada", id);
        exit(-1);
    }
    return NULL;
}

void createSubTableSymbol(tree* tree, symbolTable* tope) {
    if(tree==NULL)
        return;
    if(tree->atr->label == VDECL) {
        node* idNode;
        ids* ids = tree->left->atr->idList;
        while (ids != NULL) {
            idNode = newNode(tree->left->atr->value, tree->left->atr->line, tree->left->atr->type, tree->left->atr->label, ids->idName, NULL,NULL);
            symbolTable* st = newTableOfSymbols(idNode);
            tree->left->st = st;
            addLast(st, tope);
            ids = ids->next;
        }
    }
    else if (tree->atr->text != NULL) {
        symbolTable* st = newTableOfSymbols(tree->atr);
        tree->st = st;
        addLast(st, tope);
    }
    createSubTableSymbol(tree->left, tope);
    createSubTableSymbol(tree->right, tope);
}

// Type check
enum TType checkTypes(tree* tree){
    if (tree == NULL) return None; 
    if (tree->atr->label == VAR)
        return tree->st->cSymbol->type;
    if (tree->atr->label == CONST)
        return tree->atr->type;
    if (tree->atr->label == SUMA || tree->atr->label == MULTIPLICACION || tree->atr->label == RESTA || tree->atr->label == DIVISION || tree->atr->label == LMOD){
        tree->atr->type = checkTypes(tree->left);
        if (tree->atr->type != Int || tree->atr->type != checkTypes(tree->right)){
            return None; 
        } else {
            return tree->atr->type;
        }
    }
    if (tree->atr->label == LAND || tree->atr->label == LOR){
        tree->atr->type = checkTypes(tree->left);
        if (tree->atr->type != Bool || tree->atr->type != checkTypes(tree->right)){
            return None; 
        } else {
            return tree->atr->type;
        }
    }
    if (tree->atr->label==LEQUAL){
        if (checkTypes(tree->left) == checkTypes(tree->right))
            return Bool;
    }
    if (tree->atr->label == MENOR || tree->atr->label == MAYOR){
        if (checkTypes(tree->left) == checkTypes(tree->right) == Int)
            return Bool;
    }
    if (tree->atr->label == NOTEXP){
        if (checkTypes(tree->right) == Bool)
            return Bool;
    }
    if (tree->atr->label == MCALL){
        return tree->st->cSymbol->type;
    }
    return None;
}

// Type check
void checkValidation(tree* tree){
    if (tree == NULL) return; 
    if (tree->atr->label==IFTHEN){
        if (checkTypes(tree->left) != Bool)
            printf("No boolean expresion into if statement in line: %d \n", tree->left->atr->line);
    }
    if (tree->atr->label == NOTEXP){
        if (checkTypes(tree->right) != Bool)
            printf("Incompatible types\n in line: %d \n", tree->right->atr->line);
    }
    if (tree->atr->label == NEGATIVEEXP){
        if (checkTypes(tree->right) != Int)
            printf("Incompatible types\n in line: %d \n", tree->right->atr->line);
    }
    if (tree->atr->label == STMTASSIGN){
        if (checkTypes(tree->right) != checkTypes(tree->left)){
            printf("Incompatible types for the assignament in line: %d \n", tree->atr->line);
        }
    }
    if (tree->atr->label == MCALL){
        params* actualParams = newParam(None);
        generateTypesList(tree->right, &actualParams);
        params* formalParams = tree->st->cSymbol->paramList;
        while(actualParams != NULL || formalParams != NULL){
            if(actualParams == NULL){
                printf(" HAY MENOS PARAMETRO ACTUALES QUE FORMALES ");
                exit(0);
            }
            if(formalParams == NULL){
                printf(" HAY MAS PARAMETROS ACTUALES QUE FORMALES ");
                exit(0);
            }
            if(actualParams->type != formalParams->type){
                printf(" LA FUNCION  %s ESPERA UN PARAMETRO DE TIPO %s Y TIENE UN %s \n",tree->left->atr->text,TTypeString[formalParams->type],TTypeString[actualParams->type]);
                exit(0);
            }
            actualParams = actualParams->next;
            formalParams = formalParams->next;
        }

    }
    if (tree->atr->label == MDECL ){
        int result = 1;
        findReturns(tree->right,tree->left->left->atr->type,&result);
        if(result != 1 ) printf(" Incompatible types of returns with the type of the function %d \n", tree->atr->line);
    }
    checkValidation(tree->left);
    checkValidation(tree->right);
}

void generateTypesList(tree* tree, params** list){
    if(tree == NULL) return;
    if(tree->atr->label == COMMA){
        addTypeFirst(list, checkTypes(tree->right));
        generateTypesList(tree->left, list);
    }
    else{
        addTypeFirst(list, checkTypes(tree));
    }
}

void addTypeFirst(params** list, enum TType type){
    if((*list)->type == None){
        (*list)->type = type;
    }
    else{
        params* newPar = newParam(type);
        newPar->next = *list;
        *list = newPar;
    }
}

void findReturns(tree* tree, enum TType type, int* result){
    if(tree != NULL && tree->atr->label != MDECL){
        if(tree->atr->label == EXT){
            *result = 1;
            return;
        }
        else if(tree->atr->label == RET){
            if(tree->right == NULL){
                *result = *result * (type == Void);
            }
            else{
                *result = *result * (checkTypes(tree->right) == type);
            }
            
        }
        findReturns(tree->left,type,result);
        findReturns(tree->right,type,result);
    }
}

void createInstructions(tree* tree) {
    insertDecl(tree->left);
    insertStms(tree->right);
}

void insertDecl(tree* tree) {
    if (tree == NULL) return;

    insertDecl(tree->left); 

    threeDir* instru = NULL;
    listThreeDir* node = NULL;
    if (tree->atr->label == VDECL)
    {
        /*
        ids* ids = tree->left->atr->idList;
        while (ids != NULL) {
            idNode = newNode(tree->left->atr->value, tree->left->atr->line, tree->left->atr->type, tree->left->atr->label, ids->idName, NULL,NULL);
            symbolTable* st = newTableOfSymbols(idNode);
            tree->st = st;
            tope = addLast(st, tope);
            ids = ids->next;
        }
        */
        instru = newInstruction(IC_LOAD, NULL, NULL, tree->left->atr);
        node = newThreeDirElement(instru);
        insertLast(node);
    }

    insertDecl(tree->right);

}
void insertStms(tree* tree) {
    if (tree == NULL) return; 

    insertStms(tree->left);

    threeDir* instru = NULL;
    listThreeDir* node = NULL;
    if (tree->atr->label == MDECL && tree->right->atr->label != EXT)
    {
        instru = newInstruction(IC_BEGIN_FUNCTION, NULL, NULL, NULL);
        node = newThreeDirElement(instru);
        insertLast(node);
        checkOperator(tree);
        instru = newInstruction(IC_END_FUNCTION, NULL, NULL, NULL);
        node = newThreeDirElement(instru);
        insertLast(node);
    }    
    insertStms(tree->right);
}


void checkOperator(tree* tree) {
    if (tree == NULL) return; 
    threeDir* instru = NULL;
    node* op1 = NULL;
    node* op2 = NULL;
    node* result = NULL;
    listThreeDir* node = NULL;

    if (tree->atr->label == IFTELSE)
    {
        
        op1 = (tree->left->left->st != NULL) ? tree->left->left->st->cSymbol : tree->left->left->atr;
        instru = newInstruction(tree->left->left->atr->label, NULL, NULL, op1);
        node = newThreeDirElement(instru);
        insertLast(node);

        op1 = (tree->left->left->st != NULL) ? tree->left->left->st->cSymbol : tree->left->left->atr;
        instru = newInstruction(JUMPFALSE, op1, NULL, NULL);
        node = newThreeDirElement(instru);
        insertLast(node);

        checkOperator(tree->left->right);

        instru = newInstruction(LABEL, NULL, NULL, NULL);
        node = newThreeDirElement(instru);
        insertLast(node);
        
        checkOperator(tree->right);
        
    } else if (tree->atr->label == IFTHEN)
    {
        
        checkOperator(tree->left);

        op1 = (tree->left->right->st != NULL) ? tree->left->right->st->cSymbol : tree->left->right->atr;
        instru = newInstruction(JUMPFALSE, op1, NULL, NULL);
        node = newThreeDirElement(instru);
        insertLast(node);

        checkOperator(tree->left->right);

        checkOperator(tree->right);
        
        instru = newInstruction(LABEL, NULL, NULL, NULL);
        node = newThreeDirElement(instru);
        insertLast(node);

    } else if (tree->atr->label == STMTWHILE)
    {
        instru = newInstruction(LABEL, NULL, NULL, NULL);
        node = newThreeDirElement(instru);
        insertLast(node);
        
        checkOperator(tree->left);

        op1 = (tree->left->right->st != NULL) ? tree->left->right->st->cSymbol : tree->left->right->atr;
        instru = newInstruction(JUMPFALSE, op1, NULL, NULL);
        node = newThreeDirElement(instru);
        insertLast(node);

        checkOperator(tree->right);

        instru = newInstruction(JUMP, NULL, NULL, NULL);
        node = newThreeDirElement(instru);
        insertLast(node);

        instru = newInstruction(LABEL, NULL, NULL, NULL);
        node = newThreeDirElement(instru);
        insertLast(node);
        
    } else {

        checkOperator(tree->left);
        if (tree->atr->label == SUMA || tree->atr->label == MULTIPLICACION || tree->atr->label == RESTA || tree->atr->label == DIVISION || tree->atr->label == LMOD || tree->atr->label == LAND || tree->atr->label == LOR || tree->atr->label == LEQUAL || tree->atr->label == MAYOR || tree->atr->label == MENOR) 
        {
            op1 = (tree->left->st != NULL) ? tree->left->st->cSymbol : tree->left->atr;
            op2 = (tree->right->st != NULL) ? tree->right->st->cSymbol : tree->right->atr;
            result = (tree->st != NULL) ? tree->st->cSymbol : tree->atr;
            instru = newInstruction(tree->atr->label, op1,op2, result);
            listThreeDir* node = newThreeDirElement(instru);
            insertLast(node);
        } 
        else if ( tree->atr->label == STMTASSIGN ) 
        {
            op1 = (tree->right->st != NULL) ? tree->right->st->cSymbol : tree->right->atr;
            result = (tree->left->st != NULL) ? tree->left->st->cSymbol : tree->left->atr;
            instru = newInstruction(tree->atr->label, op1,op2, result);
            listThreeDir* node = newThreeDirElement(instru);
            insertLast(node);

        } 
        else if (tree->atr->label == VDECL)
        {
            instru = newInstruction(IC_LOAD, NULL, NULL, tree->left->atr);
            node = newThreeDirElement(instru);
            insertLast(node);
        }
        else if (tree->atr->label == NOTEXP || tree->atr->label == NEGATIVEEXP || tree->atr->label == RET)
        {
            instru = newInstruction(tree->atr->label, NULL, NULL, tree->right->atr);
            node = newThreeDirElement(instru);
            insertLast(node);
        }
        checkOperator(tree->right);
    }
    
}

/*
int isEquals(listThreeDir* node1, listThreeDir* node2){
    int equalsLabels = node1->node->name == node2->node->name;
    int equalsop1 = (node1->node->op1 == NULL && node2->node->op1 == NULL) || !(node1->node->op1 == NULL && node2->node->op1 != NULL) && !(node1->node->op1 != NULL && node2->node->op1 == NULL) && (node1->node->op1->value == node2->node->op1->value && node1->node->op1->line == node2->node->op1->line && node1->node->op1->type == node2->node->op1->type && node1->node->op1->label == node2->node->op1->label && node1->node->op1->text == node2->node->op1->text);
    int equalsop2 = (node1->node->op2 == NULL && node2->node->op2 == NULL) || !(node1->node->op2 != NULL && node2->node->op2 == NULL) && !(node1->node->op2 != NULL && node2->node->op2 == NULL) && (node1->node->op2->value == node2->node->op2->value && node1->node->op2->line == node2->node->op2->line && node1->node->op2->type == node2->node->op2->type && node1->node->op2->label == node2->node->op2->label && node1->node->op2->text == node2->node->op2->text);
    int equalres = (node1->node->resu == NULL && node2->node->resu == NULL) || !(node1->node->resu == NULL && node2->node->resu != NULL) && !(node1->node->resu != NULL && node2->node->resu == NULL) && (node1->node->resu->value == node2->node->resu->value && node1->node->resu->line == node2->node->resu->line && node1->node->resu->type == node2->node->resu->type && node1->node->resu->label == node2->node->resu->label && node1->node->resu->text == node2->node->resu->text);
    return equalsLabels && equalsop1 && equalsop2 && equalres;
}

*/