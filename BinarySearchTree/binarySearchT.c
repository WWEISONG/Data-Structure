#include <stdlib.h>
#include <stdio.h>
#include "binarySearchT.h"

struct node{
	int data;// data area
	Tree left;// left subtree
	Tree right;// right subtree
};

Tree createTree(int data)
{
	Tree tNode = malloc(sizeof(struct node));
	if (tNode == NULL){
		fprintf(stderr, "createTree error: no memory\n");
		exit(EXIT_FAILURE);
	}
	tNode->data = data;
	tNode->left = NULL;
	tNode->right = NULL;
	return tNode;
}

void freeTree(Tree t)
{
	if (t == NULL){
		return;
	}else{
		freeTree(t->left);
		freeTree(t->right);
		free(t);// should be careful about postfix traversal
	}
}

Tree insertTree(Tree t, int data)
{
	if (t == NULL){
		t = createTree(data);
	}else{
		if (data < t->data){
			t->left = insertTree(t->left, data);
		}else{
			t->right = insertTree(t->right, data);
		}
	}
	return t;
}

void printTree(Tree t, int depth)
{
	if (t != NULL){
		depth++;
		printTree(t->left, depth);
		// infix traversal handling
		int i;
		for (int i = 1; i < depth; i++)
		{
			putchar('\t');
		}
		printf("%d\n", t->data);
		// end traversal infix
		printTree(t->right, depth);
	}
}

int count(Tree t)
{
	int num = 0;
	if (t != NULL){
		num = 1 + count(t->left) + count(t->right);
	}
	return num;
}

int height(Tree t)
{
	int heightTree = -1;
	if (t != NULL){
		heightTree = 1 + max(height(t->left), height(t->right));
	}
	return heightTree;
}

int balance(Tree t)
{
	int diff = 0;
	if (t != NULL){
		diff = count(t->left) - count(t->right);
		if (diff < 0){
			diff = - diff;
		}
	}
	return diff;
}

Tree insertTreeInteration(Tree t, int data)
{
	if (t == NULL){// this is important if t == NULL
		t = createTree(data);
		return t;
	}
	Tree insertPlace = t;
	while(insertPlace != NULL)
	{
		if (data < insertPlace->data){
			insertPlace = insertPlace->left;
		}else{
			insertPlace = insertPlace->right;
		}
	}
	// remember to create complete data node
	insertPlace = createTree(data);
}

Tree deleteTree(Tree t, int data)
{
	if (t != NULL){
		// firstly we need to search this data to delete
		if (data < t->data){
			t->left = deleteTree(t->left, data);
		}else if (data > t->data){
			t->right = deleteTree(t->right, data);
		}else{
			Tree replaceNode;
			if (t->left == NULL && t->right == NULL){
				replaceNode = NULL;
			}else if (t->left == NULL && t->right != NULL){
				replaceNode = t->right;
			}else if (t->left != NULL && t->right == NULL){
				replaceNode = t->left;
			}else{
				replaceNode = findDLMD(t->left, t->right);
			}
			free(t);// free the old mallocs and data
			t = replaceNode;// assign the new pointer value
		}
	}
	return t;
}

Tree findDLMD(Tree tLeft, Tree tRight)
{
	Tree replaceNode, preNode = NULL;
	replaceNode = tRight;// DLMD is the left-most descendent of right child
	while (replaceNode->left != NULL)
	{
		preNode = replaceNode;
		replaceNode = replaceNode->left;
	}
	if (preNode != NULL){// this means the replace node is not the left node
		preNode->left = replaceNode->right;
		replaceNode->right = tRight;// connect tRight to the replace node
	}// be careful about this both left and right need to be connected;
	replaceNode->left = tLeft;// connect tLeft to the replace node
	return replaceNode;
}

Tree revTree(Tree originTree)
{
	Tree copyTree = NULL;
	if (originTree != NULL){
		copyTree = malloc(struct node);
		if (copyTree == NULL){
			fprintf(stderr, "revTree error: no memory\n");
			exit(EXIT_FAILURE);
		}
		// one current node
		// two sub-trees
		copyTree->data = originTree->data;
		copyTree->left = revTree(originTree->right);
		copyTree->right = revTree(originTree->left);
	}
	return copyTree;
}

int isBalanced(Tree t)
{
	int diff = -1;
	if (t == NULL){
		return 1;
	}
	diff = height(t->left) - height(t->right);
	if (diff > 1 || diff < -1){
		return 0;
	}
	if (isBalanced(t->left) && isBalanced(t->right)){
		return 1;
	}else{
		return 0;
	}
}