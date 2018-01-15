#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

int main(int argc, char* argv[]) {
    char cv;
    Heap* maxHeap;
    int heapSize, key;
    FILE* fi;

    fi = fopen(argv[1], "r");
    while(!feof(fi)) {
        fscanf(fi, "%c", &cv);
        switch(cv) {
        case 'n':
            fscanf(fi, "%d", &heapSize);
            maxHeap = CreateHeap(heapSize);
            break;
        case 'i':
            fscanf(fi, "%d", &key);
            if(maxHeap->Size == maxHeap->Capacity) {
                puts("Insertion Error: Max heap is full.");
                break;
            }
            InsertMax(key, maxHeap);
            break;
        case 'd':
            if(maxHeap->Size == 0) {
                puts("Deletion Error: Max heap is empty!");
                break;
            }
            DeleteMax(maxHeap);
            break;
        case 'p':
            if(maxHeap->Size == 0) {
                puts("Print Error: Max heap is empty!");
                break;
            }
            PrintHeap(maxHeap);
            break;
        }
    }

    fclose(fi);
    free(maxHeap->Elements);
    free(maxHeap);

    return 0;
}
