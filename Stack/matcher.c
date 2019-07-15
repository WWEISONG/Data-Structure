#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// case A : no opening
// case B : not same
// case C : left something

int main(int argc, char *argv[])
{
	char *input;
	Stack S = NULL;           // create a stack
	S = createStack();        // initialize the stack

	fgets(input, 50, stdin);              // get input from stdin or file
	printf("%s\n", input);
	while ( *input != '\0' )
	{
		if ( !isspace(*input) ){      // we do NOT need space
			switch(*input)
			{
				case '(': push(*input, S);
						break;
				case '[': push(*input, S);
						break;
				case '{': push(*input, S);
						break;
				case ')': 
						if ( isEmpty(S) ){
							fprintf(stderr, "mismatch detected\n"); // case B
							return EXIT_FAILURE;
						}else{
							if ( pop(S) != '(' ){
								fprintf(stderr, "mismatch detected\n");  // case A
								return EXIT_FAILURE;
							}
						}
						break;
				case ']': 
						if ( isEmpty(S) ){
							fprintf(stderr, "mismatch detected\n"); // case B
							return EXIT_FAILURE;
						}else{
							if ( pop(S) != '[' ){
								fprintf(stderr, "mismatch detected\n");  // case A
								return EXIT_FAILURE;
							}
						}
						break;
				case '}':
						if ( isEmpty(S) ){
							fprintf(stderr, "mismatch detected\n"); // case B
							return EXIT_FAILURE;
						}else{
							if ( pop(S) != '{' ){
								fprintf(stderr, "mismatch detected\n");  // case A
								return EXIT_FAILURE;
							}
						}
						break;
				default: break;
			}
		}

		++input;
	}

	if ( !isEmpty(S) ){
		fprintf(stderr, "mismatch detected\n");   // case C
		return EXIT_FAILURE;
	}

	printf("No problem, Sir\n");
	return EXIT_SUCCESS;
}
