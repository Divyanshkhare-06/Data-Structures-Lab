#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* constructTree(int preorder[], int* index, int inStart, int inEnd, int* indexMap, int offset) {
    if (inStart > inEnd) return NULL;
    int curr = preorder[(*index)++];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = curr;
    root->left = root->right = NULL;
    if (inStart == inEnd) return root;
    int splitIndex = indexMap[curr - offset];
    root->left = constructTree(preorder, index, inStart, splitIndex - 1, indexMap, offset);
    root->right = constructTree(preorder, index, splitIndex + 1, inEnd, indexMap, offset);
    return root;
}
void printInorder(struct TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}
void cleanup(struct TreeNode* root) {
    if (!root) return;
    cleanup(root->left);
    cleanup(root->right);
    free(root);
}
int main() {
    int inorder[100], preorder[100];
    int n = 0;
    printf("Enter inorder traversal (space-separated): ");
    char buffer[500];
    fgets(buffer, sizeof(buffer), stdin);
    char* token = strtok(buffer, " \n");
    while (token && n < 100) {
        inorder[n++] = atoi(token);
        token = strtok(NULL, " \n");
    }
    int size = n;
    n = 0;
    printf("Enter preorder traversal (space-separated): ");
    fgets(buffer, sizeof(buffer), stdin);
    token = strtok(buffer, " \n");
    while (token && n < 100) {
        preorder[n++] = atoi(token);
        token = strtok(NULL, " \n");
    }
    if (n != size) {
        printf("Error: Mismatched traversal lengths.\n");
        return 1;
    }
    if (size == 0) {
        printf("Tree is empty.\n");
        return 0;
    }
    int minVal = inorder[0], maxVal = inorder[0];
    for (int i = 1; i < size; i++) {
        if (inorder[i] < minVal) minVal = inorder[i];
        if (inorder[i] > maxVal) maxVal = inorder[i];
    }
    int range = maxVal - minVal + 1;
    int* indexMap = (int*)malloc(range * sizeof(int));
    if (!indexMap) {
        printf("Memory allocation error.\n");
        return 1;
    }
    for (int i = 0; i < range; i++) indexMap[i] = -1;
    for (int i = 0; i < size; i++) indexMap[inorder[i] - minVal] = i;
    int current = 0;
    struct TreeNode* root = constructTree(preorder, &current, 0, size - 1, indexMap, minVal);
    printf("\nConstructed Tree (Inorder): ");
    printInorder(root);
    printf("\n");
    free(indexMap);
    cleanup(root);
    return 0;
}