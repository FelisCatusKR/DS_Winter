#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

#define MAX_DATA 600000

int main(void) {
    int i;
    time_t before, after, ms, hs, qs;
    ElementType *MdataArray, *tmpArray;
    ElementType *HdataArray;
    ElementType *QdataArray;

    srand(time(NULL));

    /* Merge Sort */
    MdataArray = (ElementType *)malloc(sizeof(ElementType)*MAX_DATA);
    tmpArray = (ElementType *)malloc(sizeof(ElementType)*MAX_DATA);
    for(i=0; i<MAX_DATA; i++)
        MdataArray[i] = rand() % MAX_DATA;

    puts("Merge Sort");
    before = clock();
    MergeSort(MdataArray, tmpArray, 0, MAX_DATA-1);
    after = clock();
    ms = after - before;
    puts("Sorted data by Merge Sort:");
    printData(MdataArray, 0, 20);
    printf("Running Time: %u msec\n", ms);

    free(MdataArray);
    free(tmpArray);

    /* Heap Sort */
    HdataArray = (ElementType *)malloc(sizeof(ElementType)*(MAX_DATA+1));
    for(i=1; i<=MAX_DATA; i++)
        HdataArray[i] = rand() % MAX_DATA;

    puts("Heap Sort");
    before = clock();
    HeapSort(MdataArray, MAX_DATA);
    after = clock();
    hs = after - before;
    puts("Sorted data by Heap Sort:");
    printData(MdataArray, 1, 21);
    printf("Running Time: %u msec\n", hs);

    free(HdataArray);

    /* Quick Sort */
    QdataArray = (ElementType *)malloc(sizeof(ElementType)*MAX_DATA);
    for(i=0; i<MAX_DATA; i++)
        QdataArray[i] = rand() % MAX_DATA;

    puts("Quick Sort");
    before = clock();
    QuickSort(MdataArray, 0, MAX_DATA-1);
    after = clock();
    qs = after - before;
    puts("Sorted data by Quick Sort:");
    printData(MdataArray, 0, 20);
    printf("Running Time: %u msec\n", qs);

    free(QdataArray);

    return 0;
}
