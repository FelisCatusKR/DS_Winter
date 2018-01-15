#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

Position SingleRotateWithLeft(Position node) {
    Position tmpNode;

    tmpNode = node->Left;
    node->Left = tmpNode->Right;
    tmpNode->Right = node;

    node->Height = MAX(Height(node->Left), Height(node->Right)) + 1;
    tmpNode->Height = MAX(Height(tmpNode->Left), Height(tmpNode->Right)) + 1;

    return tmpNode;
}

Position SingleRotateWithRight(Position node) {
    Position tmpNode;

    tmpNode = node->Right;
    node->Right = tmpNode->Left;
    tmpNode->Left = node;

    node->Height = MAX(Height(node->Left), Height(node->Right)) + 1;
    tmpNode->Height = MAX(Height(tmpNode->Left), Height(tmpNode->Right)) + 1;

    return tmpNode;
}

Position DoubleRotateWithLeft(Position node) {
    node->Left = SingleRotateWithRight(node->Left);
    return SingleRotateWithLeft(node);
}

Position DoubleRotateWithRight(Position node) {
    node->Right = SingleRotateWithLeft(node->Right);
    return SingleRotateWithRight(node);
}

AVLTree Insert(ElementType X, AVLTree T) {
    if(T == NULL) {
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Element = X;
        T->Height = 0;
        T->Left = NULL;
        T->Right = NULL;
    }
    else if(X < T->Element) {
        T->Left = Insert(X, T->Left);
        if(Height(T->Left) - Height(T->Right) == 2) {
            if(X < T->Left->Element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    }
    else if(X > T->Element) {
        T->Right = Insert(X, T->Right);
        if(Height(T->Right) - Height(T->Left) == 2) {
            if(X > T->Right->Element)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }
    }
    T->Height = MAX(Height(T->Left), Height(T->Right)) + 1;
    return T;
}

void PrintInorder(AVLTree T) {
    if(T == NULL) return;
    PrintInorder(T->Left);
    printf("%d(%d) ", T->Element, T->Height);
    PrintInorder(T->Right);
}

int Height(Position P) {
    return P == NULL ? -1 : P->Height;
}
