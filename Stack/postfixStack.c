#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc, char *argv[])
{
	char *postfix;
	Stack s;                        // create a stack
	s = createStack();              // initialize stack

	if ( argc != 2 ){
		fprintf(stderr, "Usage: ./postfix postfixexpression\n");
	}else{
		postfix = argv[1];
		while ( *postfix != '\0' )
		{
			switch(*postfix)
			{
				case '+': push(pop(s) + pop(s), s);
				case '*': push(pop(s) * pop(s), s);
				case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
				push(*postfix - '0', s);             //remember from single char to integer!!! char - '0'
			} 

			postfix++;
		}

		printf("%d\n", pop(s));
	}

	return EXIT_SUCCESS;
}

/*
<<1>>
<<2, 1>>
<<3, 2, 1>>
<<5, 1>>
<<4, 5, 1>>
<<5, 4, 5, 1>>
<<20, 5, 1>>
<<25, 1>>
<<6, 25, 1>>
<<150, 1>>
<<151>>
*/

// queue
/*
<<1>>
<<1, 2>>
<<1, 2, 3>>
<<3, 3>>
<<3, 3, 4>>
<<3, 3, 4, 5>>
<<4, 5, 9>>
<<9, 9>>
<<9, 9, 6>>
<<6, 81>>
<<87>>
*/