#define MAX(A, B) (A > B ? A : B)

typedef struct AVLNode* Position;
typedef struct AVLNode* AVLTree;
typedef int ElementType;

struct AVLNode {
    ElementType Element;
    AVLTree Left;
    AVLTree Right;
    int Height;
};

Position SingleRotateWithLeft(Position node);
Position SingleRotateWithRight(Position node);
Position DoubleRotateWithLeft(Position node);
Position DoubleRotateWithRight(Position node);
AVLTree Insert(ElementType X, AVLTree T);
void PrintInorder(AVLTree T);
int Height(Position P);
