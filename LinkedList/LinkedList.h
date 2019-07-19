/*
	Linked list ADT interface
	create by WEI SONG
*/

typedef struct node *LinkedList;

LinkedList createLinkedList(void); 	// creates and returns an empty linked list
void putHead(int data, LinkedList); 	// inserts data at the head of the linked list
void putTail(int data, LinkedList);	// inserts data at the tail of the linked list
int getHead(LinkedList);            	// removes and returns the head of the linked list
int getTail(LinkedList);            	// removes and returns the tail of the linked list
int isEmptyLinkedList(LinkedList);  	// 0/1 if the linked list is empty or not
void showList(LinkedList);          	// prints the linked list(not the head node)