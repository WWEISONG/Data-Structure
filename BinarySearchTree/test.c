#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(int argc, char *argv[])
{
	Tree littleTree = NULL;
	if (argc > 1){
		for (int i = 1; i < argc; i++)
		{
			int num;
			if (sscanf(argv[i], "%d", &num) != 1){
				fprintf(stderr, "Invalid argument found\n");
				exit(EXIT_FAILURE);
			}else{
				littleTree = insertTreeNode(littleTree, num);
			}
		}
		printTree(littleTree, 0);
	}
	freeTree(littleTree);
	return EXIT_SUCCESS;
}