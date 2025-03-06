#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* deleteHead(struct Node* head) { 
    if (head == NULL)
        return NULL;
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}
void printList(struct Node* curr) {
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}
struct Node *createNode(int new_data){
    struct Node *new_node =
      (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}
int main() {
    struct Node* head = createNode(3);
    head->next = createNode(12);
    head->next->next = createNode(15);
    head->next->next->next = createNode(18);
    head = deleteHead(head);
    printList(head);

    return 0;
}
