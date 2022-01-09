/**
 * Author:     Harun Kagan Danaci - 181180020
 * Created:    18.12.2021
 * Course:     CENG205 Data Structures
 * Assignment: Assignment 3
 *
 **/
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
    return (treePtr);
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
void preOrder(TreeNodePtr treePtr){
    printf("%d ",treePtr->data);
    if (treePtr->leftPtr != NULL)
        preOrder(treePtr->leftPtr);
    if (treePtr->rightPtr != NULL)
        preOrder(treePtr->rightPtr);
}
// Inorder: Left subtree, Root, Right subtree
void inOrder(TreeNodePtr treePtr){
    if (treePtr == NULL)
        return;
    inOrder(treePtr->leftPtr);
    printf("%d ",treePtr->data);

    inOrder(treePtr->rightPtr);
}
// Postorder: Left subtree, Right subtree, Root
void postOrder(TreeNodePtr treePtr){
    if (treePtr->leftPtr != NULL)
        postOrder(treePtr->leftPtr);
    if (treePtr->rightPtr != NULL)
        postOrder(treePtr->rightPtr);
    printf("%d ",treePtr->data);
}
int main() {
    // Creating an empty binary tree
    TreeNodePtr root = NULL;

    printf("The numbers being placed in the tree are:\n");
    for (int i = 0; i < 10; ++i) {
        int n = rand() % 25 + 1;
        printf("%d ", n);
        insertNode(&root, n);
    }

    printf("\n\nThe preorder traversal is:\n");
    preOrder(root);

    printf("\n\nThe inorder traversal is:\n");
    inOrder(root);

    printf("\n\nThe postorder traversal is:\n");
    postOrder(root);

    getchar();
    return 0;
}
