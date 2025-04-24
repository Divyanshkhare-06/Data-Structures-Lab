#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};
struct TreeNode* addNode(struct TreeNode* root, int val) {
    if (root == NULL) {
        struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        temp->val = val;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (val < root->val) {
        root->left = addNode(root->left, val);
    } else if (val > root->val) {
        root->right = addNode(root->right, val);
    }
    return root;
}
bool find(struct TreeNode* root, int key) {
    if (root == NULL) return false;
    if (key == root->val) return true;
    return (key < root->val) ? find(root->left, key) : find(root->right, key);
}
struct TreeNode* buildTree() {
    struct TreeNode* root = NULL;
    int total, num;
    printf("How many nodes? ");
    scanf("%d", &total);
    printf("Enter %d integers:\n", total);
    for (int i = 0; i < total; i++) {
        scanf("%d", &num);
        root = addNode(root, num);
    }
    return root;
}
void printInOrder(struct TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    printf("%d ", root->val);
    printInOrder(root->right);
}
void freeTree(struct TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
int main() {
    struct TreeNode* root = buildTree();
    printf("\nInorder Traversal: ");
    printInOrder(root);
    int target;
    printf("\n\nEnter number to find: ");
    scanf("%d", &target);
    if (find(root, target)) {
        printf("%d found in tree.\n", target);
    } else {
        printf("%d not present in tree.\n", target);
    }
    freeTree(root);
    return 0;
}