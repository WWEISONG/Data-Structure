#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "linkedList.h"

struct node
{
	int data;                 // data area
	struct node *next;		  // link next
};

linkedList createlinkedList()
{
	linkedList L;
	L = malloc(sizeof(struct node));     // allocate memory for L

	if ( L == NULL ){                    // failure allocating memory 
		fprintf(stderr, "createlinkedList error: no memory\n");
		exit(1);
	}else{
		L->data = 1001;                 // head data
		L->next = NULL;                 
	}

	return L;
}
void addNewnode(int data, linkedList L)
{
	linkedList list, newnode;
	if ( L == NULL ){
		fprintf(stderr, "addNewnode error: not initialize\n");
	}else{
		list = L;
		newnode = malloc(sizeof(struct node));              // allocate memory for new node

		if ( newnode == NULL ){								// allocate failure for new node
 			fprintf(stderr, "addNewnode error: no memory\n");
 			return;
		}
		while ( list->next != NULL )
		{
			list = list->next;
		}

		newnode->data = data;                               // assign value for new node
		newnode->next = NULL;		
		list->next = newnode;								// link new node
	}

	return;	
}

void showlinkedList(linkedList L)
{
	linkedList list;
	if ( L == NULL ){
		fprintf(stderr, "showlinkedList error: not initialize\n");
	}else{
		list = L;
		list = list->next;
		while ( list->next != NULL )
		{
			printf("%d->", list->data);
			list = list->next;
		}

		printf("%d\n", list->data);
	}

	return;
}

int deleteNode(linkedList L)
{
	linkedList list, lastnode, prenode;
	int retval = 0;
	if ( L == NULL ){
		fprintf(stderr, "deleteNode error: not initialize\n");
	}else{
		list = L;
		prenode = NULL;
		while ( list->next != NULL )
		{
			prenode = list;                 // record the previous node
			list = list->next;
		}
		if ( prenode == NULL ){             // there is a head node only
			retval = list->data;
			free(list);
		}else{                              // last node is not head node
			lastnode = list;
			retval = lastnode->data;
			prenode->next = NULL;
			free(lastnode);
		}
	}	

	return retval;
}

int sumNode(linkedList L)
{
	int sum = 0;
	linkedList list;
	list = list->next;                   // should judge if empty or not
	while ( list->next != NULL )         // stop at last one
	{
		sum += list->data;
		list = list->next;
	}

	sum += list->data;                   // sum last one data

	return sum;
}

int Even(linkedList L)
{
	linkedList list, deletenode, prenode;
	int retval = 0;
	if ( L == NULL ){
		fprintf(stderr, "even error: not initialize\n");
	}else{
		list = L;
		prenode = L;
		while ( list->next != NULL )
		{
			if ( list->data % 2 == 0 ){                      // if delete, the prenode should be stay
				deletenode = list;
				prenode->next = deletenode->next;            // prenode link node after delete node
				retval = deletenode->data;
				free(deletenode);

				list = prenode->next;                       // current list is next of prenode
			}else{                                          // if no delete, the prenode goes down
				prenode = list;
				list = list->next;                          // link goes down
			}
		}

		if ( list->data % 2 == 0 ){
			deletenode = list;
			prenode->next = deletenode->next;            // prenode link node after delete node
			retval = deletenode->data;
			free(deletenode);

			list = prenode->next;			
		}
	}	
	return retval;
}

void addorder(int data, linkedList L)
{
	linkedList list, newnode, prenode;
	int flag = 0;
	if ( L == NULL ){
		fprintf(stderr, "addorder error: not initialize\n");
	}else{
		newnode = malloc(sizeof(struct node));
		if ( newnode == NULL ){
			fprintf(stderr, "addorder error: no memory\n");
			return;
		}
		newnode->data = data;                    // assign new data to new node
		if ( L->next != NULL ){
			list = L->next;
		}
		prenode = L;                            // initialize previous node
		while ( list->next != NULL )
		{
			if ( newnode->data < list->data ){    // find the position to insert
				prenode->next = newnode;          // link previous node
				newnode->next = list;            // link next node
				flag = 1;
				break;							 // if we insert successfully the we tear down the loop
			}else{
				prenode = list;                   // go down continueously
				list = list->next;
			}
		}
		if ( !flag ){
			if ( newnode->data > list->data ){
				list->next = newnode;
				newnode->next = NULL;
			}else{
				prenode->next = newnode;           // link previous node
				newnode->next = list;              // link next node
			}			
		}
	}

	return;
}

int equalDelete(int data, linkedList L)
{
	linkedList list, prenode, deletenode;
	int retval = 0;
	if ( L == NULL ){
		fprintf(stderr, "equalDelete error: no initialize\n");
		return EXIT_FAILURE;
	}else{
		list = L->next;         	// bypass head we are the first node if not empty
		prenode = L;
		while ( list != NULL )   	// find the node need to delete until the last one
		{							// do not need to handle the last node specially
			if ( list->data != data ){
				prenode = list;
				list = list->next;
			}else{
				deletenode = list;
				prenode->next = deletenode->next;
				retval = deletenode->data;
				free(deletenode);
			}
		}
	}

	return retval;
}