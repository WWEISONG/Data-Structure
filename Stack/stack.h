//
// Created by Sherman on 2019/6/23.
//

#ifndef QUACK_STACK_H
#define QUACK_STACK_H
/*
	1. we can implement a stack using array or linked list
	2. Stack : LIFO / Queue : FIFO
	3. Quack : Stack + Queue
*/
#include <stdio.h>
#include <stdlib.h>
#define HEIGHT 20

typedef struct stack *Stack;
// use a struct to describe stack
struct stack
{
    int array[HEIGHT];        // use array as container
    int top;                  // index of top of stack
};

Stack createStack(void);      // create and return Quack
void push(int, Stack);        // put the given integer onto the quack
int pop(Stack);               // pop and return the top element on the quack
int isEmpty(Stack);      // return 1 is Quack is empty, else 0
void makeEmptyStack(Stack);   // remove all the elements on Quack
void showStack(Stack);        // print the contents of Quack, from the top down
void qush(int, Stack);        // used for queue

#endif //QUACK_STACK_H
