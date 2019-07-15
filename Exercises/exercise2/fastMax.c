#include <stdio.h>
#include <stdlib.h>

int max(int a, int b, int c);                    // signature

int main(int argc, char *argv[])
{
	printf("result is: %d\n", max(5, 1, 3));
}

int max(int a, int b, int c)
{
	int result = (a > b) ? ((a > c) ? a : c ): ((b > c) ? b: c);  // use this best way

	return result;
}





