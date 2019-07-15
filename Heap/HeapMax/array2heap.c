#include <stdio.h>
#include <stdlib.h>
#include "heapMax.h"

// EE8268063
int main(void)
{
	int h[] = {-999, 1, 2, 3, 4, 5, 6, 7};
	int *new_h;
	new_h = convertToHeap(h, 7);

	for ( int i = 0; i <= 7; i++ )
	{
		printf("%d ", new_h[i]);
	}

	putchar('\n');
}