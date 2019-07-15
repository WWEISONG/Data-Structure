#include <stdio.h>
#include <stdlib.h>

void showNumbers(int num, int original_num);

int main(int argc, char *argv[])
{
	if ( argc != 2 ){
		fprintf(stdout, "Usage:Please input a number ./count+ number\n");
	}else{
		int num = 0;
		if ( sscanf(argv[1], "%d", &num) ){
			showNumbers(num, num);
		}else{
			fprintf(stdout, "%s is non-numeric\n", argv[1]);
		}
	}

	return EXIT_SUCCESS;
}

void showNumbers(int num, int original_num)
{
	int n = num;                 // becareful about this initial
	if ( n == 0 ){               // if you use after should give more argument same as it
		printf("%d,", n);
		return;
	}else{
		if ( n > 0 ){             // case of number > 0
			showNumbers(n - 1, original_num);	  // recursive
		}else{
			showNumbers(n + 1, original_num);   // case of number < 0 recursive
		}
	}

	if ( n != original_num ){
		printf("%d,", n);
	}else{
		printf("%d\n", original_num);
	}
	return;
}