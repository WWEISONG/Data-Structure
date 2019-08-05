#include <stdio.h>
#include <stdlib.h>
#include "GraphAM.h"

typedef struct node *Quack;		// typedef a alias

Quack createQuack(void);		// create and return Quack
void push(int, Quack);			// push data into quack
void  qush(int, Quack);			// qush data into quack
int pop(Quack); 				// pop data from quack
void makeEmpty(Quack);			// clean all the data
int  isEmpty(Quack Q);			// make sure quack is empty or not
int isInQuack(int, Quack);
void showQuack(Quack Q);
void handleCycle(GraphAM, Quack, int *, int, int);