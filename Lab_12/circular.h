#include <stdbool.h>

typedef int Vertex;
typedef struct CircularQueue {
    int *key;
    int front;
    int rear;
    int qsize;
    int max_queue_size;
} CircularQueue;

CircularQueue* MakeEmpty(int max);
bool IsEmpty(CircularQueue* Q);
bool IsFull(CircularQueue* Q);
void Enqueue(CircularQueue* Q, Vertex X);
Vertex Dequeue(CircularQueue* Q);
void PrintFirst(CircularQueue* Q);
void PrintRear(CircularQueue* Q);
void DeleteQueue(CircularQueue* Q);

void PrintQueue(CircularQueue* Q);
