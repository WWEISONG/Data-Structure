//
// Created by Sherman on 2019/6/23.
//

#include "stack.h"

Stack createStack(void)
{
    Stack S;
    S = (Stack)malloc(sizeof(Stack));
    if ( S == NULL ){
        fprintf(stderr, "createStack failure: no memary, aborting\n");
        exit(1);          // pass back to the controller
    }
    S->top = -1;       // initialize the top as a secure number -1

    return S;
}

void push(int data, Stack S)
{
    if ( S == NULL ){
        fprintf(stderr, "push failure: not initialize the stack\n");
    }else{
        if ( S->top >= HEIGHT - 1 ){
            fprintf(stderr, "push failure: the Stack is overflow\n");
        }else{
            ++S->top;           // increase the top
            S->array[S->top] = data;   // push data at the top
        }
    }

    return;
}

void qush(int data, Stack S)
{
    if ( S == NULL ){           
        fprintf(stderr, "qush failure: not initialize the stack\n");
    }else{
        if ( S->top >= HEIGHT - 1 ){
            fprintf(stderr, "qush failure: the stack is overflow\n");
        }else{
            ++S->top;                             // increase the top
            for ( int i =  S->top; i > 0; i-- )   // take all the elements up
            {
                S->array[i] = S->array[i-1];      // from top to bottom
            }
            S->array[0] = data;
        }
    }

    return;
}

int pop(Stack S)
{
    int retrive = 0;
    if ( S == NULL ){
        fprintf(stderr, "pop faliure: not initialize the stack\n");
    }else{
        if ( isEmpty(S) ){
            fprintf(stderr, "pop failure: the stack is underflow\n");
        }else{
            retrive = S->array[S->top];      // pop the top element
            --S->top;						 // update the top position
        }
    }

    return retrive;	                        // return pop element
}

int isEmpty(Stack S)
{
    int empty = 0;
    if ( S == NULL ){
        fprintf(stderr, "isEmptyStack failure: not initialize the stack\n");
    }else{
        empty = S->top < 0;         // check S->top
    }

    return empty;
}

void makeEmptyStack(Stack S)
{
    if ( S == NULL ){
        fprintf(stderr, "makeEmptyStack: not initialize the stack\n");
    }else{
        while ( !isEmpty(S) )       // good use
        {
            pop(S);                 // pop the element
        }
    }

    return;
}

void showStack(Stack S)
{
    if ( S == NULL ){
        fprintf(stderr, "showStack failure: not initialize the stack\n");
    }else{
        printf("Stack: ");
        if ( S->top < 0 ){
            printf("<< >>\n");
        }else{
            printf("<<");                      // first symbol <<
            for ( int i = S->top; i > 0; --i )
            {
                printf("%d, ", S->array[i]);   // print each element
            }
            printf("%d>>\n", S->array[0]);     // print last one element
        }
    }

    return;
}