#include <stdio.h>
#include <stdlib.h>

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

TreeNodePtr newNode(int value) {
    TreeNodePtr treePtr = (TreeNodePtr) malloc(sizeof(TreeNode));
    treePtr->data = value;
    treePtr->leftPtr = NULL;
    treePtr->rightPtr = NULL;
    return treePtr;
}
void insertNode(TreeNodePtr* treePtr, int value){
    // If the node is empty assign the value to its data variable
    if( *treePtr == NULL) {
        *treePtr = newNode(value);
        return;
    }
    // If the value to be inserted is less than the current node's data than move on to the left of tree.
    else if (value < (*treePtr)->data) {
        // If the left child node of this node is empty it means that we found
        // value's place. We establish a link between parent and child nodes.
        if((*treePtr)->leftPtr == NULL) {
            (*treePtr)->leftPtr = newNode(value);
            return;
        }
        insertNode ( &(*treePtr)->leftPtr, value);
    }// If the value to be inserted is greater than the current node's data than move on to the left of tree.
    else if (value > (*treePtr)->data) {
        // If the right child node of this node is empty it means that we found
        // value's place. We establish a link between parent and child nodes.
        if((*treePtr)->rightPtr == NULL) {
            (*treePtr)->rightPtr = newNode(value);
            return;
        }
        insertNode ( &(*treePtr)->rightPtr, value);
    }
    // If the value is the as the current node's data then don't insert it.
}
/* Preorder:
 * Root
 * Left subtree
 * Right subtree
 */
void preOrder(TreeNodePtr treeNodePtr){
    printf("%d",treeNodePtr->data);
    if (treeNodePtr->leftPtr != NULL)
        preOrder(treeNodePtr->leftPtr);
    if (treeNodePtr->rightPtr != NULL)
        preOrder(treeNodePtr->rightPtr);
}
// Inorder: Left subtree, Root, Right subtree
void inOrder(TreeNodePtr treeNodePtr){
    if (treeNodePtr->leftPtr != NULL)
        preOrder(treeNodePtr->leftPtr);
    printf("%d",treeNodePtr->data);
    if (treeNodePtr->rightPtr != NULL)
        preOrder(treeNodePtr->rightPtr);
}
// Postorder: Left subtree, Right subtree, Root
void postOrder(TreeNodePtr treeNodePtr){
    if (treeNodePtr->leftPtr != NULL)
        preOrder(treeNodePtr->leftPtr);
    if (treeNodePtr->rightPtr != NULL)
        preOrder(treeNodePtr->rightPtr);
    printf("%d",treeNodePtr->data);
}
int main() {
    TreeNodePtr root;




    return 0;
}
