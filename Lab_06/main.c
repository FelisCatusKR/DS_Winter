#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int main(int argc, char* argv[]) {
    FILE* in;
    int key;
    char cv;
    Tree* root = NULL;

    in = fopen(argv[1], "r");

    while(!feof(in)) {
        fscanf(in, "%c", &cv);
        switch(cv) {
        case 'i':
            fscanf(in, "%d", &key);
            if(Find(key, root) != NULL) {
                printf("Insertion failed: %d already is in the tree\n", key);
                break;
            }
            root = Insert(key, root);
            printf("Insert %d\n", key);
            break;
        case 'd':
            fscanf(in, "%d", &key);
            if(Find(key, root) == NULL) {
                printf("Deletion failed: %d is not in the tree\n", key);
                break;
            }
            Delete(key, root);
            printf("Delete %d\n", key);
            break;
        case 'f':
            fscanf(in, "%d", &key);
            Find(key, root) == NULL ? printf("%d is not in the tree\n", key) : printf("%d is in the tree\n", key);
            break;
        case 'p':
            fscanf(in, "%c", &cv);
            if(cv == 'i')
                printInorder(root);
            else if(cv == 'r')
                printPreorder(root);
            else if(cv == 'o')
                printPostorder(root);
            printf("\n");
            break;
        }
    }
    fclose(in);
    while(root == NULL)
        Delete(FindMin(root)->Element, root);

    return 0;
}
