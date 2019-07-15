#include <stdio.h>
#include <stdlib.h>

typedef struct node *Quack;        // typedef a alias

Quack createQuack(void);          // create and return Quack
void push(int, Quack);            // push
void  qush(int, Quack);           // qush
int pop(Quack);                  // pop
void makeEmpty(Quack);            // clean all
int  isEmpty(Quack Q);            // is empty
void showQuack(Quack Q);          // show