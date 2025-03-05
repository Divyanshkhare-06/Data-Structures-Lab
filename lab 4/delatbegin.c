// C program to delete the head node
// from a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Delete the head node and return the new head
struct Node* deleteHead(struct Node* head) {
  
    // Check if the list is empty
    if (head == NULL)
        return NULL;

    // Store the current head in a 
      // temporary variable
    struct Node* temp = head;

    // Move the head pointer to the next node
    head = head->next;

    // Free the memory of the old head node
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
  
    // Create a hard-coded linked list:
    // 3 -> 12 -> 15 -> 18
    struct Node* head = createNode(3);
    head->next = createNode(12);
    head->next->next = createNode(15);
    head->next->next->next = createNode(18);
    head = deleteHead(head);
    printList(head);

    return 0;
}