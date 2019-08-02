#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "quack.h"
#define HEAD_DATA INT_MAX      // dummy data  
// use linked list to implement our quack
struct node 
{
	int data;             // store data area
	struct node *next;	  // link next node
};

Quack createQuack(void)
{
	Quack head;
	head = malloc(sizeof(struct node));     // allocate memory for head node
	if ( head == NULL ){					 // exception no memory
		fprintf(stderr, "No memory\n");
		exit(EXIT_FAILURE);
	}else{
		head->data = HEAD_DATA;              // should be never used
		head->next = NULL;					 // the function of head is to link first real node
		return head;
	}
}

void push(int data, Quack head)
{
	if ( head == NULL ){
		fprintf(stderr, "Quack still not initialized\n");
		return;
	}
	Quack newnode;									// push means you need to create a new node
	newnode = malloc(sizeof(struct node));  // allocate memory for this new node
	if ( newnode == NULL ){
		fprintf(stderr, "push: no memory\n");
		exit(EXIT_FAILURE);
	}

	// insert the newnode at the head
	newnode->data = data;       // assign data area
	newnode->next = head->next;  // link behind node
	head->next = newnode;       // linked by head

	return;
}

void qush(int data, Quack Q)
{
	Quack newnode;
	Quack endnode;
	if ( Q == NULL ){
		fprintf(stderr, "qush: Quack not initialized\n");
	}else{
		newnode = malloc(sizeof(struct node));         // allocate memory for this new node
		if ( newnode == NULL ){
			fprintf(stderr, "qush : no memory\n");
			exit(EXIT_FAILURE);
		}

		newnode->data = data;                  // firstlt handle new node and it's value
		newnode->next = NULL;

		endnode = Q;                           // should not damage orginal Q
		while ( endnode->next != NULL )                   // find the last node
		{
			endnode = endnode->next;
		}
		endnode->next = newnode;                         // link last with newnode
	}

	return;
}

int pop(Quack Q)
{
	int retval = 0;
	if ( Q == NULL ){
		fprintf(stderr, "pop: Quack no initialized\n");
	}else{
		if ( isEmptyQuack(Q) ){
			fprintf(stderr, "pop: Quack underflow\n");
		}else{
			Quack topnode = Q->next;    // top dummy node is always there
			retval = topnode->data; // return the data
			Q->next = topnode->next;    // link 
			free(topnode);              // clean up
		}
	}

	return retval;
}

void makeEmpty(Quack Q)
{
	if ( Q == NULL ){
		fprintf(stderr, "makeEmpty: no initialized\n");
	}else{
		while ( !isEmptyQuack(Q) ){     // use a loop to pop until empty
			pop(Q);
		}
	}

	return;
}

int  isEmptyQuack(Quack Q)
{
	int empty = 0;
	if ( Q == NULL ){
		fprintf(stderr, "isEmpty: no initialized\n");
	}else{
		empty = Q->next == NULL;                  // very good use
	}

	return empty;
}

void showQuack(Quack Q)
{
	if ( Q == NULL ){
		fprintf(stderr, "showQuack: not initialized\n");
	}else{
		if ( Q->data != HEAD_DATA ){                         // head may corrupted
			fprintf(stderr, "showQuack: linked list head corrupted\n");
		}else{
			printf("Quack: ");
			if ( Q->next == NULL ){                // list may be empty
				printf("<< >>\n");
			}else{
				printf("<<");                    
				Q = Q->next;						// first
				while ( Q->next != NULL )
				{
					printf("%d, ", Q->data);
					Q = Q->next;
				}									
				printf("%d>>\n", Q->data);			// last
			}	
		}
	}

	return;	
}
