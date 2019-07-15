#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int num1, num2;
	if( argc != 3 || !sscanf(argv[1], "%d", &num1) || !sscanf(argv[2], "%d", &num2) ){
		fprintf(stderr, "Usage: ./Comparelist list1 list2\n");
	}else{
		( num1 > num2 ) ? printf("%d\n", num1):printf("%d\n", num2);
	}

	return EXIT_SUCCESS;
}