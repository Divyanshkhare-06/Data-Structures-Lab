#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;  
    struct Node*next;  
};
struct Node* createNode(int new_data)
{
     struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
     new_node->data = new_data;
     new_node->next = NULL;
     return new_node;
}
struct Node* insertAtFront(struct Node* head, int new_data)
{
    struct Node* new_node = createNode(new_data);
    new_node->next = head;
    return new_node;
}
void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    struct Node* head = createNode(9);
    head->next = createNode(3);
    head->next->next = createNode(7);
    head->next->next->next = createNode(5);

    printf("Original Linked List:");
    printList(head);
    printf("After inserting Nodes at the front:");
    int data = 10;
    head = insertAtFront(head, data);
    printList(head);
    return 0;
}



