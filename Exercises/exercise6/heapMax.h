// header file of heap
#ifndef HEAPMAX_H
#define HEAPMAX_H

typedef struct heap *heapMax;

heapMax initializeHeap();
void insertData(char data, heapMax h);
void showHeap(heapMax h);
char deleteMax(heapMax h);
int isEmpty(heapMax h);
// int *convertToHeap(int h[], int size);

#endif