#include <stdio.h>

void swap_integer(int*, int*);

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("before: %d %d\n", a, b);
    swap_integer(&a, &b);
    printf("after: %d %d\n", a, b);

    return 0;
}

void swap_integer(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
