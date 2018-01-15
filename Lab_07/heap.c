#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "heap.h"

Heap* CreateHeap(int heapSize) {
    Heap* tmpHeap;
    tmpHeap = (Heap*)malloc(sizeof(Heap));
    tmpHeap->Capacity = heapSize;
    tmpHeap->Size = 0;
    tmpHeap->Elements = (int*)malloc(sizeof(int) * (heapSize+1));
    return tmpHeap;
}

void InsertMax(ElementType X, Heap* H) {
    int pos;
    for(pos = ++(H->Size); pos/2 > 0 && X > H->Elements[pos/2]; pos /= 2)
        H->Elements[pos] = H->Elements[pos/2];
    H->Elements[pos] = X;
}

int DeleteMax(Heap* H) {
    int pos, child;
    ElementType maxElement, lastElement;

    maxElement = H->Elements[1];
    lastElement = H->Elements[H->Size--];

    for(pos = 1; pos*2 <= H->Size; pos = child ) {
        child = pos*2;
        if(child != H->Size && H->Elements[child+1] > H->Elements[child])
            child++;

        if(lastElement < H->Elements[child])
            H->Elements[pos] = H->Elements[child];
        else
            break;
    }
    H->Elements[pos] = lastElement;
    return maxElement;
}

void PrintHeap(Heap* H) {
    int i;
    for(i = 1; i <= H->Size; i++)
        printf("%d ", H->Elements[i]);
    putchar('\n');
}
