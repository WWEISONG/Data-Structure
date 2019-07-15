// prefixes output as requirements
#include <stdio.h>
#include <stdlib.h>

// the time complexity is O(n), we visit every element of the input string
// it's linear complexity, thus O(n) complexity
int main(int argc, char *argv[])
{
	char *start, *end;
	if ( argc != 1 ){
		fprintf(stderr, "Usage: ./prefixes string\n");
	}else{
		start = argv[1];                // two pointers to control a same memory
		end = argv[1];                  // both of them can change the value of memory

		while ( end != '\0' )
		{
			end++;
		}

		while ( start != end )
		{                             // smart use of two pointers
			printf("%s\n", start);
			end--;
			*end = '\0';
		}

	}
}