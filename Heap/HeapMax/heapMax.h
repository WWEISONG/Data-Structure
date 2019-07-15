// header file of heap
#ifndef HEAPMAX_H
#define HEAPMAX_H

typedef struct heap *heapMax;

heapMax initializeHeap();
void insertData(int data, heapMax h);
void showHeap(heapMax h);
int deleteMax(heapMax h);
int *convertToHeap(int h[], int size);

#endif