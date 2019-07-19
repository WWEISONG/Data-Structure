#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "LinkedList.h"

struct node			// use struct to describe the list
{
	int data;		// data area
	struct node *next;  	// linked next node
};

// use to create a new linked list and return
LinkedList createLinkedList()
{
	LinkedList l = NULL;
	l = malloc(sizeof(struct node));	// malloc memory for new linked list
	if (l == NULL){				// malloc memory fail
		fprintf(stderr, "createLinkedList error: no memory\n");
		exit(1);
	}
	l->data = INT_MAX;			// initialize the head data:flag data
	l->next = NULL;				// next is null
	return l;
}

// put a new data into the linked list last position
void putTail(int data, LinkedList l)
{
	if(l == NULL){
		fprintf(stderr, "linked list is NULL\n");
	}else{					// malloc memory for new node
		LinkedList newNode = malloc(sizeof(struct node));
		if (newNode == NULL){
			fprintf(stderr, "putTail error: no memory\n");
		}else{
			newNode->data = data;	// initialize our new node
			newNode->next = NULL;	// initialize new node next element
			LinkedList temp = l;
			while (temp->next != NULL)
			{			// use a while loop to find the last position
				temp = temp->next;
			}
			temp->next = newNode;	// link new node at the last position
		}
	}
	return;
}

// put a new data into the linked list first position
void putHead(int data, LinkedList l)
{
	if(l == NULL){
		fprintf(stderr, "putHead error: linked list is NULL\n");
	}else{
		LinkedList newNode = malloc(sizeof(struct node));
		if(newNode == NULL){
			fprintf(stderr, "putHead error: no memory\n");
		}else{
			newNode->data = data;
			LinkedList temp = l->next;  	// store the rest of linked list
			l->next = newNode;		// put the new node at the head
			newNode->next = temp;		// linked the rest of linked list
		}
	}
	return;	
}

// get the last data element of the linked list and return
int getTail(LinkedList l)
{
	int retval = 0;
	if (l == NULL){						// the link list is NULL
		fprintf(stderr, "getTail error: linked list is NULL\n");
		exit(0);
	}
	if (!isEmptyLinkedList(l)){
		LinkedList temp = l->next, previousNode = l;
		while (temp->next != NULL)
		{						// find the tail node
			previousNode = temp;			// record the previous node
			temp = temp->next;
		}
		retval = temp->data;
		previousNode->next = NULL;			// set previous node as the tail
		free(temp);					// free this tail node
		temp = NULL;
	}else{							// linked list is empty
		fprintf(stderr, "linked list is empty\n");
	}

	return retval;
}

// get the first data element of the linked list and return
int getHead(LinkedList l)
{
	int retval = 0;
	if(l == NULL){
		fprintf(stderr, "getHead error: linked list is NULL\n");
		exit(0);
	}
	if (!isEmptyLinkedList(l)){
		LinkedList firstNode = l->next;		// get the first node
		l->next = firstNode->next;		// link the rest of link list
		retval = firstNode->data;
		free(firstNode);
		firstNode = NULL;
	}else{
		fprintf(stderr, "linked list is empty\n");
	}

	return retval;
}

int isEmptyLinkedList(LinkedList l)
{
	int empty = 0;
	if (l == NULL){
		fprintf(stderr, "isEmptyLinkedList error: linked list is NULL\n");
	}else{
		empty = l->next == NULL;
	}

	return empty;
}

void showList(LinkedList l)
{
	if (l == NULL){
		fprintf(stderr, "isEmptyLinkedList error: linked list is NULL\n");
	}else{
		printf("List: ");
		if (isEmptyLinkedList(l)){
			printf("<< >>\n");
		}else{
			printf("<<");
			LinkedList temp = l->next;
			while (temp->next != NULL)
			{
				printf("%d, ", temp->data);
				temp = temp->next;
			}
			printf("%d>>\n", temp->data);
		}
	}

	return;	
}