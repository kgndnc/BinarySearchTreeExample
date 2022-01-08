#include <stdio.h>
struct treeNode  {
    int data;
    struct treeNode* leftPtr;
    struct treeNode* rightPtr;
};
typedef struct treeNode TreeNode;
typedef TreeNode* TreeNodePtr;
void insertNode(TreeNodePtr* treePtr, int value);
void preorder(TreeNodePtr treePtr);
void inorder(TreeNodePtr treePtr);
void postorder(TreeNodePtr treePtr);

int main() {
    printf("Hello, World!\n");
    return 0;
}
