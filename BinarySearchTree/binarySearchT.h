// Binary Search Tree

typedef struct node *Tree;

Tree createTree(int);
void freeTree(Tree);
Tree insertTree(Tree, int);
void printTree(Tree, int);
int count(Tree);
int height(Tree);
int balance(Tree);
Tree insertTreeInteration(Tree, int);
Tree deleteTree(Tree, int);
Tree findDLMD(Tree, Tree);
Tree revTree(Tree);

int isBalanced(Tree t);