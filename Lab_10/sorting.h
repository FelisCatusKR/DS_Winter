typedef int ElementType;

void MergeSort(ElementType A[], ElementType TmpArray[], int Left, int Right);
void Merge(ElementType A[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd);
void HeapSort(ElementType A[], int N);
void PercDown(ElementType A[], int root, int Size);
void Swap(ElementType* a, ElementType* b);
void QuickSort(ElementType A[], int l, int r);
int Partition(ElementType A[], int l, int r);
ElementType select_pivot(ElementType A[], int l, int r);
void printData(ElementType A[], int start, int endt);
