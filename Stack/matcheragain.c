#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define OPENA '('
#define OPENB '['
#define OPENC '{'
#define CLOSEA ')'
#define CLOSEB ']'
#define CLOSEC '}'

// case A : no opening
// case B : not same
// case C : left something

int main(int argc, char *argv[])
{
	int mismatch = 0;          // use to describe mismatch or not
	char temp;
	Stack S;                   // be carefule about initialize Stack
	S = createStack();
	while ( (temp = getchar()) != '\n' && !mismatch )
	{
		if ( temp == OPENA || temp == OPENB || temp == OPENC ){
			push(temp, S);
		}else if ( temp == CLOSEA || temp == CLOSEB || temp == CLOSEC ){
			if ( isEmpty(S) ){
				mismatch = 1;
			}else{                                                // totally, 3 cases
				if ( !(( temp == CLOSEA && pop(S) == OPENA ) || 
					(temp == CLOSEB && pop(S) == OPENB) ||
					(temp == CLOSEC && pop(S) == OPENC))){
					mismatch = 1;
				}
			}
		}
	}

	if ( !isEmpty(S) || mismatch ){
		printf("mismatch detected\n");
	}
	return EXIT_SUCCESS;
}
