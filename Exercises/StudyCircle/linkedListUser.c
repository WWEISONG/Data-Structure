#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main()
{
	linkedList list;
	list = createlinkedList();

	for ( int i = 0; i < 10; i++ )
	{
		addNewnode(i, list);
	}
	showlinkedList(list);
	addNewnode(12, list);
	addNewnode(13, list);
	Even(list);
	showlinkedList(list);
	addorder(15, list);
	showlinkedList(list);
	equalDelete(7, list);
	showlinkedList(list);
	free(list);
	return EXIT_SUCCESS;
}