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
struct Node* append(struct Node* head, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (head == NULL) {
        return new_node;
    }
    struct Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return head;
}
void printList(struct Node* node) {
    while (node != NULL) {
        printf(" %d", node->data);
        node = node->next;
    }
}
int main() {
    struct Node* head = createNode(5);
    head->next = createNode(13);
    head->next->next = createNode(8);
    head->next->next->next = createNode(12);
    head->next->next->next->next = createNode(6);

    printf("Created Linked list is:");
    printList(head);
    head = append(head, 11);
    printf("\nAfter inserting 11 at the end:");
    printList(head);
    return 0;
}