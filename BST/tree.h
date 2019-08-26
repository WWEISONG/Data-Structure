// tree.h as an interface for the BST (Binary Search Tree-->order)
#ifndef TREE_H_
#define TREE_H_

typedef struct node *Tree;

Tree createTreeNode(int);
Tree insertTreeNode(Tree, int);
void printTree(Tree, int);
void freeTree(Tree);
int count(Tree t);
int maxNumber(int a, int b);
int computeHeight(Tree t);
int searchTree(Tree t, int v);
int sumTree(Tree t);
Tree findDLMD(Tree tLeft, Tree tRight);
#endif