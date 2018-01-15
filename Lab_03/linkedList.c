#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linkedList.h"

List MakeEmpty(void)
{
    List L = (PtrToNode)malloc(sizeof(struct Node));
    L->element = 0;
    L->next = NULL;
    return L;
}

bool IsEmpty(List L)
{
    return L->next == NULL;
}

bool isLast(Position P, List L)
{
    return P->next == NULL;
}

void Delete(ElementType X, List L)
{
    Position P, tmp;
    P = FindPrevious(X, L);
    if(P == NULL)
    {
        printf("Deletion(%d) failed: the element is not in the list\n", X);
        return;
    }
    tmp = P->next;
    P->next = tmp->next;
    free(tmp);
}

Position FindPrevious(ElementType X, List L)
{
    Position P;
    P = Find(X, L);
    if(P == NULL) return NULL;
    P = L;
    while(P->next->element != X)
        P = P->next;
    return P;
}

Position Find(ElementType X, List L)
{
    Position P = L->next;
    while(P != NULL && P->element != X)
        P = P->next;
    return P;
}

void Insert(ElementType X, List L, Position P)
{
    Position tmp = (PtrToNode)malloc(sizeof(struct Node));
    if(P == NULL)
    {
        printf("Insertion(%d) Failed: cannot find the location to be inserted\n", X);
        free(tmp);
        return;
    }
    tmp->element = X;
    tmp->next = P->next;
    P->next = tmp;
}

void DeleteList(List L)
{
    Position P, tmp;
    P = L->next;
    while(!isLast(P, L))
    {
        tmp = P->next;
        free(P);
        P = tmp;
    }
    free(L);
}

void PrintList(List L)
{
    PtrToNode tmp;
    if(IsEmpty(L))
    {
        printf("List is empty!\n");
        return;
    }
    tmp = L->next;
    while(tmp != NULL)
    {
        printf("key: %d\t", tmp->element);
        tmp = tmp->next;
    }
    printf("\n");
}
