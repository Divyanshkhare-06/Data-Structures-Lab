#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *createNode(int x);
struct Node *insertPos(struct Node *head, int pos, int data) {
    if (pos < 1)
        return head;
    if (pos == 1) {
        struct Node *newNode = createNode(data);
        newNode->next = head;
        return newNode;
    }
    struct Node *curr = head;
    for (int i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }
    if (curr == NULL) 
        return head;
    struct Node *newNode = createNode(data);
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}
void printList(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
struct Node *createNode(int x) {
    struct Node *new_node = 
      (struct Node *)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = NULL;
    return new_node;
}
int main() {
    struct Node *head = createNode(2);
    head->next = createNode(7);
    head->next->next = createNode(4);
    head->next->next->next = createNode(10);
    int data = 17, pos = 3;
    head = insertPos(head, pos, data);
    printList(head);
    return 0;
}