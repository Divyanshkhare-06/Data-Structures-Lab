#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}
void findKthSmallest(struct TreeNode* root, int k, int* count, int* result) {
    if (root == NULL || *count >= k) return;
    findKthSmallest(root->left, k, count, result);
    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }
    findKthSmallest(root->right, k, count, result);
}
int main() {
    struct TreeNode* root = NULL;
    int n, value, k;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d values to insert into BST:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("Enter k (to find k-th smallest element): ");
    scanf("%d", &k);
    int count = 0, result = -1;
    findKthSmallest(root, k, &count, &result);
    if (result != -1)
        printf("The %d-th smallest element is: %d\n", k, result);
    else
        printf("Invalid k value. Tree has fewer than %d elements.\n", k);
    return 0;
}