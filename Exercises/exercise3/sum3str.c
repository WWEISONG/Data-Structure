#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int r, s, t;
	int k;
	k = atoi(argv[2]);        // atoi() function: converting string to integer directly
	printf("%d\n", k);
	if ( argc != 4 || !sscanf(argv[1], "%d", &r) || \
		!sscanf(argv[2], "%d", &s) || !sscanf(argv[3], "%d", &t) ){
		fprintf(stderr, "Usage: ./sum3str str1 str2 str3\n");
	}else{
		int sum = r + s +t;
		printf("%d\n", sum);
		return EXIT_SUCCESS;
	}
}