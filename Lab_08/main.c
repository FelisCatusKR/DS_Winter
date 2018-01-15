#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(int argc, char* argv[]) {
    FILE* fp;
    AVLTree myTree = NULL;
    ElementType num;

    fp = fopen(argv[1], "r");
    while(!feof(fp)) {
        fscanf(fp, "%d", &num);
        myTree = Insert(num, myTree);
        PrintInorder(myTree);
        putchar('\n');
    }
    fclose(fp);
    return 0;
}
