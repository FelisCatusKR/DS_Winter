#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "circular.h"

CircularQueue* MakeEmpty(int max) {
    CircularQueue* NewQueue = (CircularQueue*)malloc(sizeof(CircularQueue));
    NewQueue->key = (Vertex*)malloc(max*sizeof(Vertex));
    NewQueue->max_queue_size = max;
    NewQueue->front = 0;
    NewQueue->rear = -1;
    NewQueue->qsize = 0;
    return NewQueue;
}

bool IsEmpty(CircularQueue* Q) {
    return Q->qsize == 0;
}

bool IsFull(CircularQueue* Q) {
    return Q->qsize == Q->max_queue_size;
}

void Enqueue(CircularQueue* Q, Vertex X) {
    if(IsFull(Q)) {
        puts("Enqueue Failed: Queue is full!");
        exit(-1);
    }
    Q->rear = (Q->rear+1) % Q->max_queue_size;
    Q->key[Q->rear] = X;
    Q->qsize++;
}

Vertex Dequeue(CircularQueue* Q) {
    Vertex tmp = Q->key[Q->front];
    if(IsEmpty(Q)) {
        puts("Dequeue Failed: Queue is empty!");
        exit(-1);
    }
    Q->front = (Q->front+1) % Q->max_queue_size;
    Q->qsize--;
    return tmp;
}

void PrintFirst(CircularQueue* Q) {
    if(IsEmpty(Q)) {
        puts("Print Failed: Queue is empty!");
        return;
    }
    printf("First element is %d.\n", Q->key[Q->front]);
}

void PrintRear(CircularQueue* Q) {
    if(IsEmpty(Q)) {
        puts("Print Failed: Queue is empty!");
        return;
    }
    printf("Last element is %d.\n", Q->key[Q->rear]);
}

void DeleteQueue(CircularQueue* Q) {
    while(!IsEmpty(Q))
        Dequeue(Q);
}

void PrintQueue(CircularQueue* Q) {
    int tmp;
    if(IsEmpty(Q)) {
        puts("Print Failed: Queue is empty!");
        return;
    }
    for(tmp = 0; tmp < Q->qsize; tmp++)
        printf("key: %d ", Q->key[(Q->front+tmp)%Q->max_queue_size]);
    putchar('\n');
}
