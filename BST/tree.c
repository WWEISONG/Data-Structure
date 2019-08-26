// tree.c: the implementation for BST(Binary Search Tree)
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct node {
	int data;	// data area not always int may be other
	struct node *left;	// left subtree
	struct node *right; // right subtree
};

Tree createTreeNode(int data)
{
	Tree oneNode = NULL;	// create a tree(root)
	oneNode = malloc(sizeof(struct node));	// malloc memory for this tree
	if (oneNode == NULL){
		fprintf(stderr, "createTreeNode: out of memory\n");
		exit(EXIT_FAILURE);
	}
	oneNode->data = data;	// update data to this node
	oneNode->left = NULL;	// update left child is NULL
	oneNode->right = NULL;	// update right child is NULL
	return oneNode;
}

Tree insertTreeNode(Tree t, int v)
{	// recursion version
	if (t == NULL){// the subtree is null
		t = createTreeNode(v);
	}else{// tree is not empty, compare from root node
		if (v < t->data){// if v less than root data then put to left
			t->left = insertTreeNode(t->left, v);
		}else{// if v >= data then put to right
			t->right = insertTreeNode(t->right, v);
		}
	}
	return t;
}

/*
	When we need to operate the whole tree(all nodes on the tree)
	we need to traverse the tree prefix/infix/postfix
*/

void printTree(Tree t, int depth){
	if (t != NULL){// this is tree traversal-->infix order
		depth++;
		printTree(t->left, depth);
		for (int i = 1; i < depth; i++)
		{
			putchar('\t');
		}
		printf("%d\n", t->data);
		printTree(t->right, depth);
	}
	return;
}

void freeTree(Tree t)
{
	if (t != NULL){	// this is also tree traversal-->postfix order
		freeTree(t->left);	// go left until end
		freeTree(t->right);	// then go to right
		free(t);			// then visited
	}
	return;
}

int count(Tree t)
{
	int countree = 0;
	if (t != NULL){// the number should be myself + myleft + myright
		countree = 1 + count(t->left) + count(t->right);
	}
	return countree;
}

int maxNumber(int a, int b)
{
	return (a > b) ? a:b;
}

int computeHeight(Tree t)
{
	int heightTree = -1;
	if (t != NULL){// for all subtree = 1 + max(leftsubtree, rightsubtree)
		heightTree = 1 + maxNumber(computeHeight(t->left), computeHeight(t->right));
	}
	return heightTree;
}

/*
	an important part: deleting a node from BST
	Hard option has 3 cases:
	1. node is a leaf
		there are no chidren, so unlink node from parent
	2. node has 1 child
		simply replace the node by its child
	3. node has 2 children:two choice
		a. the Deepest Left-Most Descendent(DLMD) of the right child of the deleted node
		b. the Deepest Right-Most Descendent(DRMD) of the left child of the deleted node
*/

Tree deleteTreeNode(Tree t, int i)
{
	// firstly we need to find this node in the tree
	if (t != NULL){
		if (i < t->data){
			t->left = deleteTreeNode(t->left, i);
		}else if (i > t->data){
			t->right = deleteTreeNode(t->right, i);
		}else{// find this node, we try to delete
			Tree node;
			if (t->left == NULL && t->right == NULL){// case 1
				node = NULL;
			}else if (t->left == NULL){
				node = t->right;	// now have a right child
			}else if (t->right == NULL){
				node = t->left;		// now have a left child
			}else{//case 3: have both children
				node = findDLMD(t->left, t->right);	// DLMD
				free(t);	// delete t directly
			}
			t = node;	// re-assign t --> connect to the parent
		}
	}
	return t;
}

Tree findDLMD(Tree tLeft, Tree tRight)
{
	Tree replaceNode, parent;// now we have to record the parent because the LM may have right child
	replaceNode = tRight;
	while (replaceNode->left != NULL){
		parent = replaceNode;
		replaceNode = replaceNode->left;
	}
	if (parent != NULL){// this means the tRight is not the repalceNode
		parent->left = replaceNode->right;// give replaceNode only child to parent
		replaceNode->right = tRight;// connect the replace node with right
	}
	replaceNode->left = tLeft;// connect the replace node with left
	return replaceNode;
}

int searchTree(Tree t, int v)
{
	int ret = 0;
	if (t != NULL){
		if (v < t->data){
			ret = searchTree(t->left, v);
		}else if (v > t->data){
			ret = searchTree(t->right, v);
		}else{
			ret = 1;
		}
	}
	return ret;
}

/*
	summary
	totally speaking, there are 3 operations for BST: search/insert/delete
	search:is binary search-->if we find the target return 1 else 0
	insert:from root until leaf
	delete:three cases(be careful about the 2 nodes)-->remain the original structure and replace
	the node to be deleted
	complexity all O(log(N)) / O(N)
*/

int sumTree(Tree t)
{
	int sum = 0;
	if (t != NULL){
		sum = t->data + sumTree(t->left) + sumTree(t->right);
	}
	return sum;
}