#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int value;
    struct TreeNode *left, *right;
};
struct TreeNode* createTree() {
    int input;
    printf("Enter value (-1 to skip): ");
    scanf("%d", &input);
    if (input == -1) return NULL;
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = input;
    printf("Enter left child of %d:\n", input);
    newNode->left = createTree();
    printf("Enter right child of %d:\n", input);
    newNode->right = createTree();
    return newNode;
}
void printInorder(struct TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    printf("%d ", root->value);
    printInorder(root->right);
}
int getHeight(struct TreeNode* root) {
    if (root == NULL) return 0;
    int lHeight = getHeight(root->left);
    int rHeight = getHeight(root->right);
    return (lHeight > rHeight ? lHeight : rHeight) + 1;
}
int main() {
    struct TreeNode* root = createTree();
    printf("\nInorder Traversal: ");
    printInorder(root);
    int h = getHeight(root);
    printf("\nTree Height: %d\n", h);
    return 0;
}