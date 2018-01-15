typedef int ElementType;
typedef struct HeapStruct {
    int Capacity;
    int Size;
    ElementType* Elements;
} Heap;

Heap* CreateHeap(int heapSize);
void InsertMax(ElementType X, Heap* H);
int DeleteMax(Heap* H);
void PrintHeap(Heap* H);
