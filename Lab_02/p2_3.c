#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 30

int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    int i;
    char** name;

    name = (char**)malloc(n*sizeof(char*));
    for(i=0; i<n; i++)
        name[i] = (char*)malloc((MAX_NAME+1)*sizeof(char));

    printf("enter %d names:\n", n);
    for(i=0; i<n; i++)
        scanf("%s", name[i]);

    puts("the names you entered:");
    for(i=0; i<n; i++)
        puts(name[i]);

    for(i=0; i<n; i++)
        free(name[i]);
    free(name);

    return 0;
}
