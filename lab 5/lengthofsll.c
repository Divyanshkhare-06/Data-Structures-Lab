#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int new_data) {
    struct Node* new_node = 
       (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}
int main() {
    struct Node* head = createNode(10);
    head->next = createNode(3);
    head->next->next = createNode(6);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(3);
    printf("Count of nodes is %d", countNodes(head));
    return 0;
}