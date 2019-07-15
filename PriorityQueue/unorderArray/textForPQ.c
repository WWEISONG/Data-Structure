#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"

int main(void)
{
	int a[] = {41, 2, 58, 156, 360, 81, 260, 74, 167, 13};
	int length = sizeof(a) / sizeof(a[0]);

	PQ q = createPQ(length);
	printf("Array: ");
	for (int i = 0; i < length; i++)
	{
		printf("%d ", a[i]);
		insertPQ(q, a[i]);
	}

	printf("\nSorted: ");
	while (!isEmpty(q))
	{
		printf("%d ", delMaxPQ(q));
	}

	putchar('\n');

	return EXIT_SUCCESS;
}