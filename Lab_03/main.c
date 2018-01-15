#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linkedList.h"

int main(int argc, char* argv[])
{
    char cmd;
    int key1, key2;
    FILE* input;
    Position header = NULL;
    Position tmpPosition = NULL;

    input = fopen(argv[1], "r");
    header = MakeEmpty();

    while(true)
    {
        cmd = fgetc(input);
        if(feof(input)) break;
        switch(cmd)
        {
        case 'i':
            fscanf(input, "%d %d", &key1, &key2);
            tmpPosition = Find(key1, header);
            if(tmpPosition != NULL)
            {
                printf("Insertion failed: there already is an element with key %d.\n", key1);
                break;
            }
            if(key2 == -1)
                tmpPosition = header;
            else
                tmpPosition = Find(key2, header);
            Insert(key1, header, tmpPosition);
//          PrintList(header);
            break;
        case 'd':
            fscanf(input, "%d", &key1);
            Delete(key1, header);
//          PrintList(header);
            break;
        case 'f':
            fscanf(input, "%d", &key1);
            tmpPosition = FindPrevious(key1, header);
            if (tmpPosition == NULL)
                printf("Could not find %d in the list\n", key1);
            else
            {
                if(tmpPosition->element>0)
                    printf("Key of the previous node of %d is %d.\n", key1, tmpPosition->element);
                else
                    printf("Key of the previous node of %d is header.\n", key1);
            }
            break;
        case 'p':
            PrintList(header);
        }
    }
    DeleteList(header);
    fclose(input);
    return 0;
}
