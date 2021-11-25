#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "treeManagement.h"
#define COUNT 15

char* TLabelString[] = { "PARAM","VAR", "VDECL", "NONE", "NONEBLOCK", "BLOCKDECL", "IFTHEN", "IFTELSE", "MCALL" ,"MDECL", "MDECLTYPE", "EXT", "STMT","STMTASSIGN", "STMTWHILE", "SUMA", "MULTIPLICACION", "RESTA", "SEMICOLON", "DIVISION", "LAND", "LOR", "MAYOR","MENOR", "COMMA", "NEGATIVEEXP", "NOTEXP" ,"LMOD","LEQUAL","PROG", "RET", "CONST", "IC_BEGIN_FUNCTION", "IC_END_FUNCTION", "IC_LOAD", "LABEL", "JUMPFALSE", "JUMP", "LOAD_PARAMS"};

char* TTypeString[]  = {"None", "Int", "Bool", "Void" };

int offset = 8; 

int label = 2;


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


node* newNode(int value,int line, enum TType type, enum TLabel label, char* text, ids* idList, params* paramList, int offset){
    node* newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->line = line;
    newNode->type = type;
    newNode->label = label;
    newNode->text = text;
    newNode->idList = idList;
    newNode->paramList = paramList;
    newNode->offset = offset;
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
    
    printf("Value: %d, Type: %s, Label: %s, Line: %d, Text: ",atr->value, TTypeString[atr->type], TLabelString[atr->label], atr->line);
    if (atr->text != NULL)
        printf("%s", atr->text);
    
    printf(", IDS:");
    ids* listIds = atr->idList;
    while(listIds != NULL) {
        printf(" %s,", listIds->idName);
        listIds = listIds->next;
    }
    printf(", Offset: %d \n", atr->offset);
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
    sizing(threeDirList);
    if(threeDirList==NULL)
        return;
    listThreeDir* threeDirListAux = threeDirList;
    while (threeDirListAux != NULL)
    {
        printf("\n%s:\n",TLabelString[threeDirListAux->node->name]);
        treetoString(threeDirListAux->node->op1);
        treetoString(threeDirListAux->node->op2);
        treetoString(threeDirListAux->node->resu);
        printf("\n");
        threeDirListAux = threeDirListAux->next;
    }
    createAssembly();
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
    node* idNode = newNode(0, 0, 0, 0, "", NULL,NULL, 0);

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
            idNode = newNode(tree->left->atr->value, tree->left->atr->line, tree->left->atr->type, tree->left->atr->label, ids->idName, NULL,NULL, 0);
            //offset += 8;
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
        offset = 8;
        node* idNode = newNode(0, 0, 0, 0, "", NULL,NULL, 0);
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
        node* idNode = newNode(0, 0, 0, 0, "", NULL,NULL, 0);
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
        tree->left->atr->offset = offset;
        while (ids != NULL) {
            idNode = newNode(tree->left->atr->value, tree->left->atr->line, tree->left->atr->type, tree->left->atr->label, ids->idName, NULL,NULL, offset);
            offset += 8;
            symbolTable* st = newTableOfSymbols(idNode);
            tree->left->st = st;
            addLast(st, tope);
            ids = ids->next;
        }
    }
    else if(tree->atr->label == PARAM) {
        node* idNode;
        tree->atr->offset = offset;
        idNode = newNode(tree->atr->value, tree->atr->line, tree->atr->type, tree->atr->label, tree->atr->text, NULL,NULL, offset);
        offset += 8;
        symbolTable* st = newTableOfSymbols(idNode);
        tree->st = st;
        addLast(st, tope);
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
        instru = newInstruction(IC_BEGIN_FUNCTION, NULL, NULL, tree->left->left->atr);
        node = newThreeDirElement(instru);
        insertLast(node);
        checkOperator(tree);
        instru = newInstruction(IC_END_FUNCTION, NULL, NULL, tree->left->left->atr);
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
        checkOperator(tree->left->left);

        int localLabel = label;
        label+=2;
        op1 = (tree->left->left->st != NULL) ? tree->left->left->st->cSymbol : tree->left->left->atr;
        result = newNode(0,0,None,NONE,"",NULL,NULL,localLabel);
        instru = newInstruction(JUMPFALSE, op1, NULL, result);
        node = newThreeDirElement(instru);
        insertLast(node);

        checkOperator(tree->left->right);     

        result = newNode(0,0,None,NONE,"",NULL,NULL,localLabel+1);
        instru = newInstruction(JUMP, NULL, NULL, result);
        node = newThreeDirElement(instru);
        insertLast(node); 

        result = newNode(0,0,None,NONE,"",NULL,NULL,localLabel);
        instru = newInstruction(LABEL, NULL, NULL, result);
        node = newThreeDirElement(instru);
        insertLast(node);
        
        checkOperator(tree->right);

        result = newNode(0,0,None,NONE,"",NULL,NULL,localLabel+1);
        instru = newInstruction(LABEL, NULL, NULL, result);
        node = newThreeDirElement(instru);
        insertLast(node);
        
    }
    else if (tree->atr->label == PARAM)
    {
        result = (tree->st != NULL) ? tree->st->cSymbol : tree->atr;
        instru = newInstruction(PARAM, NULL, NULL, result);
        node = newThreeDirElement(instru);
        insertLast(node);
    } 
    else if (tree->atr->label == IFTHEN)
    {
        
        checkOperator(tree->left);

        int localLabel = label;
        label++;
        op1 = (tree->left->st != NULL) ? tree->left->st->cSymbol : tree->left->atr;
        result = newNode(0,0,None,NONE,"",NULL,NULL,localLabel);
        instru = newInstruction(JUMPFALSE, op1, NULL, result);
        node = newThreeDirElement(instru);
        insertLast(node);

        checkOperator(tree->left->right);

        checkOperator(tree->right);
        
        result = newNode(0,0,None,NONE,"",NULL,NULL,localLabel);
        instru = newInstruction(LABEL, NULL, NULL, result);
        node = newThreeDirElement(instru);
        insertLast(node);
    }
    else if (tree->atr->label == MCALL)
    {
        printf("aca lo rompo\n");
        loading(tree->right);
        printf("no rompio\n");
        result = (tree->right->st != NULL) ? tree->right->st->cSymbol : tree->right->atr;
        instru = newInstruction(tree->atr->label, NULL, NULL, result);
        node = newThreeDirElement(instru);
        insertLast(node);
    } 
    else if (tree->atr->label == RET)
    {
        checkOperator(tree->left);
        checkOperator(tree->right);
        result = (tree->right->st != NULL) ? tree->right->st->cSymbol : tree->right->atr;
        instru = newInstruction(tree->atr->label, NULL, NULL, result);
        node = newThreeDirElement(instru);
        insertLast(node);
    }
    else if (tree->atr->label == STMTWHILE)
    {

        int localLabel = label;
        label+=2;

        result = newNode(0,0,None,NONE,"",NULL,NULL,localLabel);
        instru = newInstruction(LABEL, NULL, NULL, result);
        node = newThreeDirElement(instru);
        insertLast(node);
        
        checkOperator(tree->left);

        op1 = (tree->left->st != NULL) ? tree->left->st->cSymbol : tree->left->atr;
        
        result = newNode(0,0,None,NONE,"",NULL,NULL,localLabel+1);
        instru = newInstruction(JUMPFALSE, op1, NULL, result);
        node = newThreeDirElement(instru);
        insertLast(node);

        checkOperator(tree->right);

        result = newNode(0,0,None,NONE,"",NULL,NULL,localLabel);
        instru = newInstruction(JUMP, NULL, NULL, result);
        node = newThreeDirElement(instru);
        insertLast(node);

        result = newNode(0,0,None,NONE,"",NULL,NULL,localLabel+1);
        instru = newInstruction(LABEL, NULL, NULL, result);
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
            checkOperator(tree->right);
        } 
        else if ( tree->atr->label == STMTASSIGN ) 
        {
            op1 = (tree->right->st != NULL) ? tree->right->st->cSymbol : tree->right->atr;
            result = (tree->left->st != NULL) ? tree->left->st->cSymbol : tree->left->atr;
            instru = newInstruction(tree->atr->label, op1,op2, result);
            listThreeDir* node = newThreeDirElement(instru);
            checkOperator(tree->right);
            insertLast(node);
        } 
        else if (tree->atr->label == VDECL)
        {
            instru = newInstruction(IC_LOAD, NULL, NULL, tree->left->atr);
            node = newThreeDirElement(instru);
            insertLast(node);
            checkOperator(tree->right);
        }
        else if (tree->atr->label == NOTEXP || tree->atr->label == NEGATIVEEXP)
        {
            op1 = (tree->right->st != NULL) ? tree->right->st->cSymbol : tree->right->atr;
            result = (tree->st != NULL) ? tree->st->cSymbol : tree->atr;
            instru = newInstruction(tree->atr->label, op1, NULL, result);
            node = newThreeDirElement(instru);
            insertLast(node);
            checkOperator(tree->right);
        } else {
            checkOperator(tree->right);
        }
    }
    
}

void createAssembly() {
    if(threeDirList==NULL)
        return;
    FILE * fp;

    fp = fopen ("assembly.s", "w+");
    fprintf(fp, "  .file   %cnombreArchivo.c%c\n  .text\n", '"', '"');
    
    while (threeDirList != NULL)
    {
        int functionOffset;
        if (threeDirList->node->name == IC_BEGIN_FUNCTION){
            functionOffset = threeDirList->node->resu->offset;
            fprintf(fp, "  .globl	%s\n  .type   %s, @function\n%s:\n  pushq  %crbp\n  movq  %crsp,  %crbp\n  subq $%d,  %crsp\n", threeDirList->node->resu->text,  threeDirList->node->resu->text, threeDirList->node->resu->text, '%','%','%', functionOffset, '%');
        }
        else if (threeDirList->node->name == IC_END_FUNCTION){
            fprintf(fp, "  leave\n  ret\n");
            fprintf(fp, "  .size %s, .-%s\n",  threeDirList->node->resu->text,  threeDirList->node->resu->text);
        }
        else if (threeDirList->node->name == STMTASSIGN)
        {   
            if (threeDirList->node->op1->label == CONST){
                fprintf(fp, "  movl  $%d, -%d(%crbp)\n",  threeDirList->node->op1->value, threeDirList->node->resu->offset,'%');
            } else if (threeDirList->node->op1->label == NONE && threeDirList->node->op1->idList == NULL) {
                fprintf(fp, "  movl  %ceax, -%d(%crbp)\n",  '%', threeDirList->node->resu->offset,'%');
            }else {
                fprintf(fp, "  movl  -%d(%crbp), %ceax\n",  threeDirList->node->op1->offset,'%','%');
                fprintf(fp, "  movl  %ceax, -%d(%crbp)\n", '%', threeDirList->node->resu->offset,'%');
            }
        }
        else if (threeDirList->node->name == SUMA)
        {
            functionOffset += 8;
            threeDirList->node->resu->offset = functionOffset;
            if (threeDirList->node->op1->label == CONST && threeDirList->node->op2->offset != 0) 
            {
                fprintf(fp, "  movl  -%d(%crbp),  %ceax\n", threeDirList->node->op2->offset, '%', '%');
                fprintf(fp, "  addl  $%d,  %ceax\n", threeDirList->node->op1->value, '%');
                fprintf(fp, "  movl  %ceax,  -%d(%crbp)\n", '%', threeDirList->node->resu->offset, '%');
            } else if (threeDirList->node->op1->offset != 0 && threeDirList->node->op2->label == CONST){
                fprintf(fp, "  movl  -%d(%crbp),  %ceax\n", threeDirList->node->op1->offset, '%', '%');
                fprintf(fp, "  addl  $%d,  %ceax\n", threeDirList->node->op2->value, '%');
                fprintf(fp, "  movl  %ceax,  -%d(%crbp)\n", '%', threeDirList->node->resu->offset, '%');
            } else if (threeDirList->node->op1->offset != 0 && threeDirList->node->op2->offset != 0){
                fprintf(fp, "  movl  -%d(%crbp),  %ceax\n", threeDirList->node->op1->offset, '%', '%');
                fprintf(fp, "  addl  -%d(%crbp),  %ceax\n", threeDirList->node->op2->offset, '%', '%');
                fprintf(fp, "  movl  %ceax,  -%d(%crbp)\n", '%', threeDirList->node->resu->offset, '%');
            } else if (threeDirList->node->op1->offset == 0 && threeDirList->node->op2->offset == 0){
                fprintf(fp, "  movl  $%d,  -%d(%crbp)\n", threeDirList->node->op1->value, threeDirList->node->resu->offset, '%');
                fprintf(fp, "  addl  $%d,  -%d(%crbp)\n", threeDirList->node->op2->value, threeDirList->node->resu->offset, '%');
            }
        }
        else if (threeDirList->node->name == RESTA)
        {
            functionOffset += 8;
            threeDirList->node->resu->offset = functionOffset;
            if (threeDirList->node->op1->label == CONST && threeDirList->node->op2->offset != 0)
            {
                fprintf(fp, "  movl  -%d(%crbp),  -%d(%crbp)\n", threeDirList->node->op2->offset, '%', threeDirList->node->resu->offset, '%');
                fprintf(fp, "  subl  $%d,  -%d(%crbp)\n", threeDirList->node->op1->value, threeDirList->node->resu->offset, '%');
            } else if (threeDirList->node->op1->offset != 0 && threeDirList->node->op2->label == CONST){
                fprintf(fp, "  movl  -%d(%crbp),  -%d(%crbp)\n", threeDirList->node->op1->offset, '%', threeDirList->node->resu->offset, '%');
                fprintf(fp, "  subl  $%d,  -%d(%crbp)\n", threeDirList->node->op2->value, threeDirList->node->resu->offset, '%');
            } else if (threeDirList->node->op1->offset != 0 && threeDirList->node->op2->offset != 0){
                fprintf(fp, "  movl  -%d(%crbp),  -%d(%crbp)\n", threeDirList->node->op1->offset, '%', threeDirList->node->resu->offset, '%');
                fprintf(fp, "  subl  -%d(%crbp),  -%d(%crbp)\n", threeDirList->node->op2->offset, '%', threeDirList->node->resu->offset, '%');
            } else if (threeDirList->node->op1->offset == 0 && threeDirList->node->op2->offset == 0){
                fprintf(fp, "  movl  $%d,  -%d(%crbp)\n", threeDirList->node->op1->value, threeDirList->node->resu->offset, '%');
                fprintf(fp, "  subl  $%d,  -%d(%crbp)\n", threeDirList->node->op2->value, threeDirList->node->resu->offset, '%');
            }
        }
        else if (threeDirList->node->name == MULTIPLICACION)
        {
            functionOffset += 8;
            threeDirList->node->resu->offset = functionOffset;
            if (threeDirList->node->op1->label == CONST && threeDirList->node->op2->offset != 0)
            {
                fprintf(fp, "  movl  -%d(%crbp),  -%d(%crbp)\n", threeDirList->node->op2->offset, '%', threeDirList->node->resu->offset, '%');
                fprintf(fp, "  imull  $%d,  -%d(%crbp)\n", threeDirList->node->op1->value, threeDirList->node->resu->offset, '%');
            } else if (threeDirList->node->op1->offset != 0 && threeDirList->node->op2->label == CONST){
                fprintf(fp, "  movl  -%d(%crbp),  -%d(%crbp)\n", threeDirList->node->op1->offset, '%', threeDirList->node->resu->offset, '%');
                fprintf(fp, "  imull  $%d,  -%d(%crbp)\n", threeDirList->node->op2->value, threeDirList->node->resu->offset, '%');
            } else if (threeDirList->node->op1->offset != 0 && threeDirList->node->op2->offset != 0){
                fprintf(fp, "  movl  -%d(%crbp),  -%d(%crbp)\n", threeDirList->node->op1->offset, '%', threeDirList->node->resu->offset, '%');
                fprintf(fp, "  imull  -%d(%crbp),  -%d(%crbp)\n", threeDirList->node->op2->offset, '%', threeDirList->node->resu->offset, '%');
            } else if (threeDirList->node->op1->offset == 0 && threeDirList->node->op2->offset == 0){
                fprintf(fp, "  movl  $%d,  -%d(%crbp)\n", threeDirList->node->op1->value, threeDirList->node->resu->offset, '%');
                fprintf(fp, "  imull  $%d,  -%d(%crbp)\n", threeDirList->node->op2->value, threeDirList->node->resu->offset, '%');
            }
        }
        else if (threeDirList->node->name == NEGATIVEEXP)
        {
            functionOffset += 8;
            threeDirList->node->resu->offset = functionOffset;
            fprintf(fp, "  movl -%d(%crbp), %ceax\n", threeDirList->node->op1->offset, '%', '%');
            fprintf(fp, "  imull  $-1,  %ceax\n", '%');
            fprintf(fp, "  movl %ceax,  -%d(%crbp)\n", '%', threeDirList->node->resu->offset, '%');
        }
        else if (threeDirList->node->name == NOTEXP)
        {
            functionOffset += 8;
            threeDirList->node->resu->offset = functionOffset;
            fprintf(fp, "  movl -%d(%crbp), %ceax\n", threeDirList->node->op1->offset, '%', '%');
            fprintf(fp, "  cmp  $0,  %ceax\n", '%');
            fprintf(fp, "  je  .L%d\n", label);
            fprintf(fp, "  movl $0,  %ceax\n", '%');
            fprintf(fp, "  jmp  .L%d\n", label+1);
            fprintf(fp, "  .L%d\n", label);
            fprintf(fp, "  movl $1,  -%ceax\n", '%');
            fprintf(fp, "  movl %ceax,  -%d(%crbp)\n", '%', threeDirList->node->resu->offset, '%');
            fprintf(fp, "  .L%d\n", label+1);
            label += 2;
        }
        else if (threeDirList->node->name == DIVISION)
        {
            functionOffset += 8;
            threeDirList->node->resu->offset = functionOffset;
            if (threeDirList->node->op1->label == CONST && threeDirList->node->op2->offset != 0) 
            {
                fprintf(fp, "  movl  $0,  edx\n");
                fprintf(fp, "  movl  -%d(%crbp),  %ceax\n", threeDirList->node->op2->offset, '%', '%');
                fprintf(fp, "  movl  $%d,  -%d(%crbp)\n", threeDirList->node->op1->value, threeDirList->node->resu->offset, '%');
                fprintf(fp, "  div  -%d(%crbp)\n", threeDirList->node->resu->offset, '%');
                fprintf(fp, "  movl  %ceax,  -%d(%crbp)\n", '%', threeDirList->node->resu->offset, '%');
            } else if (threeDirList->node->op1->offset != 0 && threeDirList->node->op2->label == CONST){
                fprintf(fp, "  movl  $0,  edx\n");
                fprintf(fp, "  movl  -%d(%crbp),  %ceax\n", threeDirList->node->op1->offset, '%', '%');
                fprintf(fp, "  movl  $%d,  -%d(%crbp)\n", threeDirList->node->op2->value, threeDirList->node->resu->offset, '%');
                fprintf(fp, "  div  -%d(%crbp)\n", threeDirList->node->resu->offset, '%');
                fprintf(fp, "  movl  %ceax,  -%d(%crbp)\n", '%', threeDirList->node->resu->offset, '%');
            } else if (threeDirList->node->op1->offset != 0 && threeDirList->node->op2->offset != 0){
                fprintf(fp, "  movl  $0,  edx\n");
                fprintf(fp, "  movl  -%d(%crbp),   %ceax\n", threeDirList->node->op1->offset, '%', '%');
                fprintf(fp, "  movl  -%d(%crbp),  -%d(%crbp)\n", threeDirList->node->op2->offset, '%', threeDirList->node->resu->offset, '%');
                fprintf(fp, "  div  -%d(%crbp)\n", threeDirList->node->resu->offset, '%');
                fprintf(fp, "  movl  %ceax,  -%d(%crbp)\n", '%', threeDirList->node->resu->offset, '%');
            } else if (threeDirList->node->op1->offset == 0 && threeDirList->node->op2->offset == 0){
                fprintf(fp, "  movl  $0,  edx\n");
                fprintf(fp, "  movl  $%d,   %ceax\n", threeDirList->node->op1->value, '%');
                fprintf(fp, "  movl  $%d,  -%d(%crbp)\n", threeDirList->node->op2->value, threeDirList->node->resu->offset, '%');
                fprintf(fp, "  div  -%d(%crbp)\n", threeDirList->node->resu->offset, '%');
                fprintf(fp, "  movl  %ceax,  -%d(%crbp)\n", '%', threeDirList->node->resu->offset, '%');
            }
        }
        else if (threeDirList->node->name == LMOD)
        {
            functionOffset += 8;
            threeDirList->node->resu->offset = functionOffset;
            if (threeDirList->node->op1->label == CONST && threeDirList->node->op2->offset != 0) 
            {
                fprintf(fp, "  movl  $0,  edx\n");
                fprintf(fp, "  movl  -%d(%crbp),  %ceax\n", threeDirList->node->op2->offset, '%', '%');
                fprintf(fp, "  movl  $%d,  -%d(%crbp)\n", threeDirList->node->op1->value, threeDirList->node->resu->offset, '%');
                fprintf(fp, "  div  -%d(%crbp)\n", threeDirList->node->resu->offset, '%');
                fprintf(fp, "  movl  %cedx,  -%d(%crbp)\n", '%', threeDirList->node->resu->offset, '%');
            } else if (threeDirList->node->op1->offset != 0 && threeDirList->node->op2->label == CONST){
                fprintf(fp, "  movl  $0,  edx\n");
                fprintf(fp, "  movl  -%d(%crbp),  %ceax\n", threeDirList->node->op1->offset, '%', '%');
                fprintf(fp, "  movl  $%d,  -%d(%crbp)\n", threeDirList->node->op2->value, threeDirList->node->resu->offset, '%');
                fprintf(fp, "  div  -%d(%crbp)\n", threeDirList->node->resu->offset, '%');
                fprintf(fp, "  movl  %cedx,  -%d(%crbp)\n", '%', threeDirList->node->resu->offset, '%');
            } else if (threeDirList->node->op1->offset != 0 && threeDirList->node->op2->offset != 0){
                fprintf(fp, "  movl  $0,  edx\n");
                fprintf(fp, "  movl  -%d(%crbp),   %ceax\n", threeDirList->node->op1->offset, '%', '%');
                fprintf(fp, "  movl  -%d(%crbp),  -%d(%crbp)\n", threeDirList->node->op2->offset, '%', threeDirList->node->resu->offset, '%');
                fprintf(fp, "  div  -%d(%crbp)\n", threeDirList->node->resu->offset, '%');
                fprintf(fp, "  movl  %cedx,  -%d(%crbp)\n", '%', threeDirList->node->resu->offset, '%');
            } else if (threeDirList->node->op1->offset == 0 && threeDirList->node->op2->offset == 0){
                fprintf(fp, "  movl  $0,  edx\n");
                fprintf(fp, "  movl  $%d,   %ceax\n", threeDirList->node->op1->value, '%');
                fprintf(fp, "  movl  $%d,  -%d(%crbp)\n", threeDirList->node->op2->value, threeDirList->node->resu->offset, '%');
                fprintf(fp, "  div  -%d(%crbp)\n", threeDirList->node->resu->offset, '%');
                fprintf(fp, "  movl  %cedx,  -%d(%crbp)\n", '%', threeDirList->node->resu->offset, '%');
            }
        }
        else if (threeDirList->node->name == LAND)
        {
            functionOffset += 8;
            threeDirList->node->resu->offset = functionOffset;
            fprintf(fp, "  cmpl  $0,  -%d(%crbp)\n", threeDirList->node->op1->offset, '%');
            fprintf(fp, "  je  .L%d\n", label);
            fprintf(fp, "  cmpl  $0,  -%d(%crbp)\n", threeDirList->node->op2->offset, '%');
            fprintf(fp, "  je  .L%d\n", label);
            fprintf(fp, "  movl  $1,  -%d(%crbp)\n", threeDirList->node->resu->offset, '%');
            fprintf(fp, "  jmp  .L%d\n", label+1);
            fprintf(fp, ".L%d:\n", label);
            fprintf(fp, "  movl  $0,  -%d(%crbp)\n", threeDirList->node->resu->offset, '%');
            fprintf(fp, ".L%d:\n", label+1);
            label+=2;
        }           
        else if (threeDirList->node->name == LOR)
        {
            functionOffset += 8;
            threeDirList->node->resu->offset = functionOffset;
            fprintf(fp, "  cmpl  $0,  -%d(%crbp)\n", threeDirList->node->op1->offset, '%');
            fprintf(fp, "  jne  .L%d\n", label);
            fprintf(fp, "  cmpl  $0,  -%d(%crbp)\n", threeDirList->node->op2->offset, '%');
            fprintf(fp, "  je  .L%d\n", label+1);
            fprintf(fp, ".L%d:\n", label);
            fprintf(fp, "  movl  $1,  -%d(%crbp)\n", threeDirList->node->resu->offset, '%');
            fprintf(fp, "  jmp  .L%d\n", label+2);
            fprintf(fp, ".L%d:\n", label+1);
            fprintf(fp, "  movl  $0,  -%d(%crbp)\n", threeDirList->node->resu->offset, '%');
            fprintf(fp, ".L%d:\n", label+2);
            label+=3;
        }
        else if (threeDirList->node->name == MENOR)
        {
            functionOffset += 8;
            threeDirList->node->resu->offset = functionOffset;
            if (threeDirList->node->op1->offset != 0 && threeDirList->node->op2->offset != 0){
                fprintf(fp, "  movl  -%d(%crbp),  %ceax\n", threeDirList->node->op1->offset, '%', '%');
                fprintf(fp, "  cmpl  -%d(%crbp),  %ceax\n", threeDirList->node->op2->offset, '%', '%');
                fprintf(fp, "  setl  %cal\n", '%');
            } else if (threeDirList->node->op1->offset != 0){
                fprintf(fp, "  cmpl  $%d,  -%d(%crbp)\n", threeDirList->node->op2->value, threeDirList->node->op1->offset, '%');
                fprintf(fp, "  setle  %cal\n", '%');
            } else if (threeDirList->node->op2->offset != 0){
                fprintf(fp, "  cmpl  $%d,  -%d(%crbp)\n", threeDirList->node->op1->value, threeDirList->node->op2->offset, '%');
                fprintf(fp, "  setg  %cal\n", '%');
            }
            fprintf(fp, "  movzbl  %cal,  %ceax\n", '%', '%');
            fprintf(fp, "  movl  %ceax,  -%d(%crbp)\n", '%', threeDirList->node->resu->offset, '%');
        }
        else if (threeDirList->node->name == MAYOR)
        {
            functionOffset += 8;
            threeDirList->node->resu->offset = functionOffset;
            if (threeDirList->node->op1->offset != 0 && threeDirList->node->op2->offset != 0){
                fprintf(fp, "  movl  -%d(%crbp),  %ceax\n", threeDirList->node->op1->offset, '%', '%');
                fprintf(fp, "  cmpl  -%d(%crbp),  %ceax\n", threeDirList->node->op2->offset, '%', '%');
                fprintf(fp, "  setg  %cal\n", '%');
            } else if (threeDirList->node->op1->offset != 0){
                fprintf(fp, "  cmpl  $%d,  -%d(%crbp)\n", threeDirList->node->op2->value, threeDirList->node->op1->offset, '%');
                fprintf(fp, "  setg  %cal\n", '%');
            } else if (threeDirList->node->op2->offset != 0){
                fprintf(fp, "  cmpl  $%d,  -%d(%crbp)\n", threeDirList->node->op1->value, threeDirList->node->op2->offset, '%');
                fprintf(fp, "  setle  %cal\n", '%');
            }
            fprintf(fp, "  movzbl  %cal,  %ceax\n", '%', '%');
            fprintf(fp, "  movl  %ceax,  -%d(%crbp)\n", '%', threeDirList->node->resu->offset, '%');
            label+=3;
        }
        else if (threeDirList->node->name == LEQUAL)
        {
            functionOffset += 8;
            threeDirList->node->resu->offset = functionOffset;
            if (threeDirList->node->op1->offset != 0 && threeDirList->node->op2->offset != 0){
                fprintf(fp, "  movl  -%d(%crbp),  %ceax\n", threeDirList->node->op1->offset, '%', '%');
                fprintf(fp, "  cmpl  -%d(%crbp),  %ceax\n", threeDirList->node->op2->offset, '%', '%');
            } else if (threeDirList->node->op1->offset != 0){
                fprintf(fp, "  cmpl  $%d,  -%d(%crbp)\n", threeDirList->node->op2->value, threeDirList->node->op1->offset, '%');
            } else if (threeDirList->node->op2->offset != 0){
                fprintf(fp, "  cmpl  $%d,  -%d(%crbp)\n", threeDirList->node->op1->value, threeDirList->node->op2->offset, '%');
            }
            fprintf(fp, "  sete  %cal\n", '%');
            fprintf(fp, "  movzbl  %cal,  %ceax\n", '%', '%');
            fprintf(fp, "  movl  %ceax,  -%d(%crbp)\n", '%', threeDirList->node->resu->offset, '%');
            label+=3;
        }
        else if (threeDirList->node->name == JUMPFALSE)
        {
            fprintf(fp, "  cmpl  $0,  -%d(%crbp)\n", threeDirList->node->op1->offset, '%');
            fprintf(fp, "  je  .L%d\n", threeDirList->node->resu->offset);
        } 
        else if (threeDirList->node->name == JUMP)
        {
            fprintf(fp, "  jmp  .L%d\n", threeDirList->node->resu->offset);
        } 
        else if (threeDirList->node->name == LABEL)
        {
            fprintf(fp, ".L%d\n", threeDirList->node->resu->offset);
        }
        //FEDE
        else if (threeDirList->node->name == RET)
        {
            fprintf(fp, "  movl  -%d(%crbp),  %ceax\n", threeDirList->node->resu->offset, '%', '%');
        }
        threeDirList = threeDirList->next;
    }

    fclose(fp);
} 

void sizing(listThreeDir* list) {
    if (list == NULL) return; 
    listThreeDir* pointer = list;
    threeDir* node = NULL; 
    while(pointer != NULL){
        if (pointer->node->name == IC_BEGIN_FUNCTION){
            node = pointer->node;
            offset = 0;
        }
        else if (pointer->node->name == IC_LOAD){
            offset += 8;
        }
        else if (pointer->node->name == PARAM){
            offset += 8;
        }
        else if (pointer->node->name == IC_END_FUNCTION){
            node->resu->offset = offset;
            node = NULL;
        }
        pointer = pointer->next;
    }
}

void loading(tree* tree) {
    if (tree == NULL) return; 
    if (tree->atr->label != COMMA)
    {
        threeDir* instru = NULL;
        node* op1 = NULL;
        node* op2 = NULL;
        node* result = NULL;
        listThreeDir* node = NULL;
        loading(tree->left);
        result = (tree->st != NULL) ? tree->st->cSymbol : tree->atr;
        instru = newInstruction(LOAD_PARAM, NULL, NULL, result);
        node = newThreeDirElement(instru);
        insertLast(node);
        loading(tree->right);
    }
    else
    {
        loading(tree->left);
        loading(tree->right);
    }
}
