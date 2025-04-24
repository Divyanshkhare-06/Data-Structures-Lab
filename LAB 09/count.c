#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};
int total = 0, leaves = 0;
struct TreeNode* buildTree() {
    int input;
    printf("Enter value (-1 to skip): ");
    scanf("%d", &input);
    if (input == -1) return NULL;
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = input;
    newNode->left = newNode->right = NULL;
    printf("Left child of %d:\n", input);
    newNode->left = buildTree();
    printf("Right child of %d:\n", input);
    newNode->right = buildTree();
    return newNode;
}
void countTotal(struct TreeNode* root) {
    if (root == NULL) return;
    total++;
    countTotal(root->left);
    countTotal(root->right);
}
void countLeaves(struct TreeNode* root) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        leaves++;
    }
    countLeaves(root->left);
    countLeaves(root->right);
}
int main() {
    struct TreeNode* root = buildTree();
    countTotal(root);
    countLeaves(root);
    printf("\nTotal Nodes: %d\n", total);
    printf("Leaf Nodes : %d\n", leaves);
    return 0;
}