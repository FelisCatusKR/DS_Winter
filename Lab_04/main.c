#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct CircularQueue{
	int *key;
	int front;
	int rear;
	int qsize;
	int max_queue_size;
}CircularQueue;

CircularQueue* MakeEmpty(int max);
bool IsEmpty(CircularQueue* Q);
bool IsFull(CircularQueue* Q);
void Enqueue(CircularQueue* Q, int X);
void Dequeue(CircularQueue* Q);
void PrintFirst(CircularQueue* Q);
void PrintRear(CircularQueue* Q);
void DeleteQueue(CircularQueue* Q);

void PrintQueue(CircularQueue* Q);

int main(int argc, char* argv[])
{
	FILE *fi;
	CircularQueue* queue;

	int key, size;
	char input_char;

        if (argc==1)
                fi = fopen("input.txt", "r");
        else

		fi = fopen(argv[1], "r");

	input_char = fgetc(fi);
	while(input_char != EOF)
	{
		switch(input_char)
		{
		case 'e' :
			fscanf(fi,"%d",&key);
			Enqueue(queue, key);
			break;
		case 'd' :
			Dequeue(queue);
			break;
		case 'f' :
			PrintFirst(queue);
			break;
		case 'r' :
			PrintRear(queue);
			break;
		case 'n' :
			fscanf(fi,"%d",&size);
			queue = MakeEmpty(size);
			break;
		case 'p' :
			PrintQueue(queue);
			break;
		}
		input_char = fgetc(fi);
	}
	DeleteQueue(queue);

	return 0;
}

CircularQueue* MakeEmpty(int max) {
    CircularQueue* NewQueue = (CircularQueue*)malloc(sizeof(CircularQueue));
    NewQueue->key = (int*)malloc(max*sizeof(int));
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

void Enqueue(CircularQueue* Q, int X) {
    if(IsFull(Q)) {
        puts("Enqueue Failed: Queue is full!");
        return;
    }
    Q->rear = (Q->rear+1) % Q->max_queue_size;
    Q->key[Q->rear] = X;
    Q->qsize++;
}

void Dequeue(CircularQueue* Q) {
    if(IsEmpty(Q)) {
        puts("Dequeue Failed: Queue is empty!");
        return;
    }
    Q->front = (Q->front+1) % Q->max_queue_size;
    Q->qsize--;
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
    while(IsEmpty(Q))
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
