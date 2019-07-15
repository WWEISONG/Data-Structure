#include <stdio.h>
#include <stdlib.h>
#include "heapMax.h"

int main(void)
{
	int num = 0;
	heapMax h;
	h = initializeHeap();

	scanf("%d", &num);
	insertData(num, h);
	while ( getchar() != '\n' )
	{
		scanf("%d", &num);
		insertData(num, h);
	}
	printf("root data: %d\n", deleteMax(h));
	showHeap(h);

	return EXIT_SUCCESS;
}