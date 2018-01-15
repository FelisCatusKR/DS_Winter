#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

Node Find(ElementType key, SearchTree T) {
    if(T == NULL)
        return T;
    if(key < T->Element)
        return Find(key, T->Left);
    else if(key > T->Element)
        return Find(key, T->Right);
    else
        return T;
}

Node FindMax(SearchTree T) {
    if(T == NULL)
        return NULL;
    else if(T->Right == NULL)
        return T;
    else
        return FindMax(T->Right);
}

Node FindMin(SearchTree T) {
    if(T == NULL)
        return NULL;
    else if(T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}

SearchTree Insert(ElementType key, SearchTree T) {
    if(T == NULL) {
        T = (Tree*)malloc(sizeof(Tree));
        T->Element = key;
        T->Left = NULL;
        T->Right = NULL;
    }
    else if(key < T->Element)
        T->Left = Insert(key, T->Left);
    else if(key > T->Element)
        T->Right = Insert(key, T->Right);
    return T;
}

SearchTree Delete(ElementType key, SearchTree T) {
    Node Tmp;
    if (key < T->Element)
        T->Left = Delete(key, T->Left);
    else if(key > T->Element)
        T->Right = Delete(key, T->Right);
    else if(key == T->Element) {
        if(T->Left == NULL && T->Right == NULL) {
            Tmp = T;
            free(Tmp);
            T = NULL;
        } else if(T->Left == NULL) {
            Tmp = T;
            T = T->Left;
            free(Tmp);
        } else if(T->Right == NULL) {
            Tmp = T;
            T = T->Right;
            free(Tmp);
        } else {
            Tmp = FindMin(T->Right);
            T->Element = Tmp->Element;
            T->Right = Delete(T->Element, T->Right);
        }
    }
    return T;
}

void printInorder(Tree* root) {
    if(root == NULL)
        return;
    printInorder(root->Left);
    printf("%d ", root->Element);
    printInorder(root->Right);
}

void printPreorder(Tree* root) {
    if(root == NULL)
        return;
    printf("%d ", root->Element);
    printPreorder(root->Left);
    printPreorder(root->Right);
}

void printPostorder(Tree* root) {
    if(root == NULL)
        return;
    printPostorder(root->Left);
    printPostorder(root->Right);
    printf("%d ", root->Element);
}
