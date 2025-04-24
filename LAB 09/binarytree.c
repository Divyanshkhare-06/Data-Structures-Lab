#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};
struct TreeNode* createTree() {
    int input;
    printf("Enter value (-1 for NULL): ");
    scanf("%d", &input);
    if (input == -1) return NULL;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = input;
    node->left = node->right = NULL;
    printf("Enter left child of %d\n", input);
    node->left = createTree();
    printf("Enter right child of %d\n", input);
    node->right = createTree();
    return node;
}
void inOrder(struct TreeNode* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->val);
    inOrder(root->right);
}
void preOrder(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(struct TreeNode* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->val);
}
int main() {
    struct TreeNode* root = createTree();
    printf("\nInorder Traversal: ");
    inOrder(root);
    printf("\nPreorder Traversal: ");
    preOrder(root);
    printf("\nPostorder Traversal: ");
    postOrder(root);
    return 0;
}