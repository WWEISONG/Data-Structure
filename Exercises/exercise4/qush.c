#include <stdio.h>
#include <stdlib.h>

// linked list version
void qush(int data, Quack Q)
{	
	Quack newnode;
	Quack endnode;

	if ( Q == NULL ){
		fprintf(stderr, "qush failure: no initialized\n");
	}else{
		newnode = malloc(sizeof(struct node));          // allocate memory for newnode
		if ( newnode == NULL ){
			fprintf(stderr, "qush failure: no memory\n"); // failure 
			exit(1);
		}

		newnode->data = data;
		newnode->next = NULL;
		endnode = Q;							 // do not damage the original queue

		while ( endnode->next != NULL )          // find the last node
		{
			endnode = endnode->next;
		}

		endnode->next = newnode;             // add new node to the tail of queue
	}

	return;
}