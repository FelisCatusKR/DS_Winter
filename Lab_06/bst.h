typedef struct TreeNode* SearchTree;
typedef struct TreeNode* Node;
typedef struct TreeNode Tree;
typedef int ElementType;
struct TreeNode {
    ElementType Element;
    SearchTree Left;
    SearchTree Right;

};

Node Find(ElementType key, SearchTree T);
Node FindMax(SearchTree T);
Node FindMin(SearchTree T);
SearchTree Insert(ElementType key, SearchTree T);
SearchTree Delete(ElementType key, SearchTree T);
void printInorder(Tree* root);
void printPreorder(Tree* root);
void printPostorder(Tree* root);
