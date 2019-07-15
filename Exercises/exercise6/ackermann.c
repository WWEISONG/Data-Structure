#include <stdio.h>
#include <stdlib.h>

int ackermann(int m, int n);
int main(int argc, char *argv[])
{
	int m = 0, n = 0, result = -1;
	if ( argc != 3 || !sscanf(argv[1], "%d", &m) || !sscanf(argv[2], "%d", &n)){
		fprintf(stderr, "Usage: ./ackermann m n\n");
		exit(1);
	}else{
		if (m < 0 || n < 0){
			fprintf(stderr, "Ackermann function is not defined for negative number\n");
			exit(1);
		}

		result = ackermann(m, n);
	}

	printf("Ackermann(%d, %d) = %d\n", m, n, result);
	return result;
}

int ackermann(int m, int n)
{
	if (m == 0 && n != 0){
		return n + 1;
	}else if (m != 0 && n == 0){
		ackermann(m-1, 1);
	}else if (m != 0 && n != 0){
		ackermann(m-1, ackermann(m, n-1));
	}
}