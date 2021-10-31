enum TLabel { PARAM, VAR, VDECL, NONE, NONEBLOCK, BLOCKDECL, IFTHEN, IFTELSE, MCALL ,MDECL, MDECLTYPE, EXT, STMT,STMTASSIGN, STMTWHILE, SUMA, MULTIPLICACION, RESTA, SEMICOLON, DIVISION, LAND, LOR, MAYOR,MENOR, COMMA, NEGATIVEEXP, NOTEXP ,LMOD,LEQUAL,PROG, RET, CONST};

enum TType {None, Int, Bool, Void };

typedef struct idList {
    char *idName;
    struct idList* next;
} ids;

typedef struct paramList{
    enum TType type;
    struct paramList* next;
} params;

//struct that defines a node*
typedef struct infoNode {
    int value;
    int line;
    enum TType type;
    enum TLabel label;
    char* text;
    ids* idList;
    params* paramList;
} node;

//struct that defines a symbols table
typedef struct symbolTable{
    node* cSymbol;
    struct symbolTable* next;
} symbolTable;

//struct that defines a tree
typedef struct treeN {
    node* atr;
    symbolTable* st;
    struct treeN* left;
    struct treeN* right;
} tree;

typedef struct stStack {
    struct symbolTable* tope;
    struct stStack* next;
} stStack;

typedef struct threeDir {
    enum TLabel name;
    node* op1;
    node* op2;
    node* resu;
} threeDir;

typedef struct listThreeDir {
    struct threeDir* node;
    struct listThreeDir* next;
} listThreeDir;

//table of symbols
extern stStack* stackOfLevels;

extern listThreeDir* threeDirList;

ids* newIdList(char* id, ids *next);

 //method that returns the string equivalent to the types
char* getType(enum TType type);


//method that returns the string equivalent to the labels
char* getLabel(enum TLabel label);

//method that create a new tree
tree* newTree(node* newatr, tree *newleft, tree *newright);

node* newNode(int value,int line, enum TType type, enum TLabel label, char* text, ids* idList, params* paramList);

//as the concatenation gave us a lot of problems, we finally decided to use this option that we found in
//https://es.stackoverflow.com/questions/146607/c%C3%B3mo-concatenar-cadenas-de-car%C3%A1cteres-sin-usar-la-funci%C3%B3n-strcat
// and later has modified by our needs
char* cat(char *s1, char *s2);

//method that take an int value and parse it to char*
char* getValue(int i);

//method that take an node* of an tree and parse it to a char* with all the fields of the tree
char* treetoString(node* atr);

//method that generates a sample of the tree
//void printTree(tree* tree);

//method that generates a sample of the tree IN ORDER
void printTree(tree* tree, int space);

//method that creates a new table of symbols
symbolTable* newTableOfSymbols(node* s);

void createLevelZero(tree* tree, symbolTable* tope);

symbolTable* addLast(symbolTable* new, symbolTable* head);

stStack* newStack(symbolTable* s);

void createLevelOfSymbolTable(tree* tree);

void createLevels(tree* tree);

void createSubTableSymbol(tree* tree, symbolTable* tope);

int searchSimbol(char* id, symbolTable* st);

enum TType checkTypes(tree* tree);

void checkValidation(tree* tree);

symbolTable* findVariable(char* id);

void findReturns(tree* tree, enum TType type, int* result);

void findParams(tree* tree, params* paramList);

void addParam(params* paramList, enum TType param);

params* newParam(enum TType type);

void addTypeFirst(params** list, enum TType type);

void generateTypesList(tree* tree, params** list);

threeDir* newInstruction(enum TLabel instruction, node* operator1, node* operator2, node* result);

listThreeDir* newThreeDirElement(threeDir* element);

void createInstructions(tree* tree);

void checkOperator(tree* tree);

void printInstructions();