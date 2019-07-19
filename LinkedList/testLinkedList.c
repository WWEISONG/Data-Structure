#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(void)
{
	LinkedList l = NULL;
	l = createLinkedList();
	putTail(1, l);
	showList(l);
	putHead(2, l);
	showList(l);
	putHead(3, l);
	showList(l);
	putTail(4, l);
	showList(l);
	int r1 = getHead(l);
	printf("%d\n", r1);
	showList(l);
	int r2 = getTail(l);
	printf("%d\n", r2);
	showList(l);
}