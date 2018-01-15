#include <stdio.h>
#include "sorting.h"

void MergeSort(ElementType A[], ElementType TmpArray[], int Left, int Right) {
    int Center;
    if(Left < Right) {
        Center = (Left+Right) / 2;
        MergeSort(A, TmpArray, Left, Center);
        MergeSort(A, TmpArray, Center+1, Right);
        Merge(A, TmpArray, Left, Center+1, Right);
    }
}

void Merge(ElementType A[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd) {
    int i, LeftEnd, NumElements, TmpPos;
    LeftEnd = Rpos - 1;
    TmpPos = Lpos;
    NumElements = RightEnd - Lpos + 1;

    while(Lpos <= LeftEnd && Rpos <=RightEnd) {
        if(A[Lpos] <= A[Rpos])
            TmpArray[TmpPos++] = A[Lpos++];
        else
            TmpArray[TmpPos++] = A[Rpos++];
    }

    while(Lpos<= LeftEnd)
        TmpArray[TmpPos++] = A[Lpos++];
    while(Rpos<= RightEnd)
        TmpArray[TmpPos++] = A[Rpos++];

    for(i=0; i<NumElements; i++, RightEnd--)
        A[RightEnd] = TmpArray[RightEnd];
}

void HeapSort(ElementType A[], int N) {
    int i;
    for(i = N/2; i>0; i--)
        PercDown(A, i, N);
    for(i = N; i>0; i--) {
        Swap(&A[1], &A[i]);
        PercDown(A, 1, i-1);
    }
}

void PercDown(ElementType A[], int root, int Size) {
    int Child, i;
    ElementType rootkey;

    rootkey = A[root];
    for(i = root; i*2 <= Size; i = Child) {
        Child = i*2;
        if(Child != Size && A[Child+1] > A[Child])
            Child++;
        if(rootkey < A[Child])
            A[i] = A[Child];
        else
            break;
    }
    A[i] = rootkey;
}

void Swap(ElementType* a, ElementType* b) {
    ElementType tmp = *a;
    *a = *b;
    *b = tmp;
}

void QuickSort(ElementType A[], int l, int r) {
    int p;
    if(l >= r)
        return;
    p = Partition(A, l, r);
    QuickSort(A, l, p-1);
    QuickSort(A, p+1, r);
}

int Partition(ElementType A[], int l, int r) {
    ElementType pivot;
    int i, j;
    pivot = select_pivot(A, l, r);
    i = l - 1;
    j = r;
    while(1) {
        while(A[--j] > pivot);
        while(A[++i] < pivot);
        if(i < j)
            Swap(&A[i], &A[j]);
        else {
            Swap(&A[i], &A[r]);
            return i;
        }
    }
}

ElementType select_pivot(ElementType A[], int l, int r) {
    return A[r];
}

void printData(ElementType A[], int start, int endt) {
    int i;
    for(i = start; i<endt; i++)
        printf("%d ", A[i]);
    putchar('\n');
}
