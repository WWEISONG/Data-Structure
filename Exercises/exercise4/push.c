#include <stdio.h>
#include <stdlib.h>

// linked list version
void push(int data, Quack Q)
{
	Quack newnode;

	if ( Q == NULL ){
		fprintf(stderr, "push failure: not initialized\n");
	}else{
		newnode = malloc(sizeof(struct node));
		if ( newnode == NULL ){
			fprintf(stderr, "push failure: not initialized\n");
			exit(1);
		}
		newnode->data = data;

		newnode->next = Q->next;                    // link to next
		Q->next = newnode;                        	// link to the head
	}

	return;
}