#include <stdio.h>
#include <stdlib.h>

typedef struct node *Tree

struct node{
	int data;// data area could be other data structure
	Tree left;// left subtree
	Tree right;// right subtree
	int count;// count the number of tree
	int nNodes;// total number of nodes on the tree
};

Tree createTreeNode(int data)
{
	Tree newTreeNode = malloc(sizeof(struct node));// malloc new memory for new node
	if (newTreeNode == NULL){
		fprintf(stderr, "out of memory\n");
		exit(EXIT_FAILURE);
	}
	newTreeNode->data = data;// assign new data to this node
	newTreeNode->left = NULL;// left subtree is null
	newTreeNode->right = NULL;// right subtree is also null
	newTreeNode->count = 1;// new node should only count itself
	return newTreeNode;
}

int sizeTree(Tree rootT)
{
	int retval = 0;
	if (rootT != NULL){
		retval = rootT->count;// clearly the size should be the root count
	}
	return retval;
}

/*
	Insertion:
	The new node is added as a leaf so it will always be initialized with a count
	of 1, and each node on search path will now have an extra node in their sub-tree
*/

Tree insertTree(Tree rootT, int v)
{	// insert a node to the leaf
	if (rootT == NULL){
		rootT = createTreeNode(v);
	}else{
		if (v < rootT->data){
			rootT->left = insertTree(rootT->left, v);
		}else{
			rootT->right = insertTree(rootT->right, v);
		}
		rootT->count++;// update the counter at each ancestor
	}
	return rootT;
}

/*
	the function of counter:
	implement a select operation which means we can index the tree
	for example we input the index of the tree node and return the
	data area of the corresponding node
*/

int selectTree(Tree rootT, int i)
{
	int retval = 0;
	if (rootT != NULL){
		int numOnLeft = 0;// this is if there is no left branch
		if (rootT->left != NULL){
			numOnLeft = rootT->left->count;// this is there is a left branch
		}
		if (numOnLeft > i){
			retval = selectTree(rootT->left, i);
		}else if (numOnLeft < i){// there is no target on left, so we only handle the right
			retval = selectTree(rootT->right, i - (numOnLeft + 1));
		}else{
			retval = rootT->data;
		}
	}else{
		printf("Index does not exist\n");
		retval = 0;
	}
	return retval;
}

Tree rotateLeft(Tree rootT)
{
	// rotate left:includes count field
	Tree retval = NULL;
	if (rootT != NULL){// left rotate hence right root-child will become new root
		Tree newRoot = rootT->right;
		if (newRoot == NULL){
			retval = rootT;
		}else{
			rootT->right = newRoot->left;
			newRoot->left = rootT;
			newRoot->count = rootT->count;// update the new root's count
			rootT->count = 1 + sizeTree(rootT->left) + sizeTree(rootT->right);
			retval = newRoot;	// return the newroot
		}
	}
	return retval;
}

Tree rotateRight(Tree rootT)
{
	// routate right:includes count field
	Tree retval = NULL;
	if (rootT != NULL){
		Tree newRoot = rootT->left;
		if (newRoot == NULL){
			return rootT;
		}else{
			rootT->left = newRoot->right;
			newRoot->right = rootT;
			newRoot->count = rootT->count;
			rootT->count = 1 + sizeTree(rootT->left) + sizeTree(rootT->right)
			retval = newRoot;
		}
	}
	return retval;
}

Tree partitionTree(Tree rootT, int i)
{
	Tree retval = NULL;
	if (rootT != NULL){
		int numOnLeft = 0;
		if (rootT->left != NULL){
			numOnLeft = rootT->left->count;
		}
		if (numOnLeft > i){
			rootT->left = partitionTree(rootT->left, i);
			rootT = routateRight(rootT);
		}
		retval = rootT;
	}else{
		printf("Index does not exist\n");
		retval = NULL;
	}
	return retval;
}

Tree balance(Tree rootT)
{
	Tree retval = NULL;
	if (rootT != NULL){
		if (rootT->count <= 1){
			retval = rootT;
		}else{
			rootT = partitionTree(rootT, t->count / 2);
			rootT->left = balance(rootT->left);
			rootT->right = balance(rootT->right);
			retval = rootT;
		}
	}
	return retval;
}

/*
	important part: balanced trees(not strict) / splay tree
	Although we cannot guarante once operation as good say once  operation can be still O(n),
	for m times operations we can guarantee O(mlog(n))

	average case search performance O(log(N)), worst case search performance O(log(N))
	Previously, BST had average case search performance O(log(N)), worst case search performance
	O(N), which is terrible, best case is always O(1)(search key is at the root node)

	Perfectly balanced BST have:
	depth of log(N), for every node |size(LeftSubtree) - size(RightSubtree)| < 2 : 0 -1 1

	Totally speaking, there are 3 cases
	case 1: ZIG means the new inserted node as the root node child(left or right)
	case 2: ZIGZAG means the new inserted node has parent and grandparent and opposition direction
	case 3: ZIGZIG means the new inserted node has parent and grandparent and same direction
	and as for rotation we focus on the grandparent and parent
*/

Tree splayInsertion(Tree rootT, Item it)
{
	if (it == NULL){
		return t;
	}
	if (rootT == NULL){
		return createTreeNode(it->data);
	}
	// go th left: 3 cases
	if (it->data < rootT->data){
		if (rootT->left == NULL){
			// ZIG
			rootT->left = createTreeNode(it->data);// make a new link for this element
			rootT->count++;
			return rotateRight(rootT);
		}
		if (it->data < rootT->left->data){
			// ZIGZIG
			rootT->left->left = splayInsertion(rootT->left->left, it);
			rootT->left->count++;
			rootT->count++;
			rootT = rotateRight(rootT);// rotate grandparent
		}else{
			// ZIGZAG
			rootT->left->right = splayInsertion(rootT->left->right, it);
			rootT->left->count++;
			rootT->count++;
			rootT = rotateLeft(rootT->left);// ZAG:rotate parent
		}
		return rotateRight(rootT);// ZIG: rotate grandparent
	}else{// go to right:3 cases
		if (rootT->right == NULL){
			// ZIG
			rootT->right = createNode(it);
			rootT->count++;
			return rotateLeft(rootT);
		}
		if (it->data < rootT->right->data){
			// ZIGZAG
			rootT->right->left = splayInsertion(rootT->right->left, it);
			rootT->right->count++;
			rootT->count++;
			rootT->right = rotateRight(rootT->right);
		}else{
			// ZIGZIG
			rootT->right->right = splayInsertion(rootT->right->right, it);
			rootT->right->count++;
			rootT->count++;
			rootT = rotateLeft(rootT);
		}
		return rotateLeft(rootT);
	}
}