#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* removeDuplicates(struct Node* head) {
    struct Node* curr1 = head; 
    while (curr1 != NULL) {
        struct Node* curr2 = curr1; 
        while (curr2->next != NULL) {
            if (curr2->next->data == curr1->data) {
                struct Node* duplicate = curr2->next;  
                curr2->next = curr2->next->next;  
                free(duplicate);
            } else {
                curr2 = curr2->next;
            }
        }
        curr1 = curr1->next;
    }
    return head;
}
void printList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
struct Node* createNode(int data) {
    struct Node* newNode =
      (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int main() {
    struct Node* head = createNode(1);
    head->next = createNode(11);
    head->next->next = createNode(1);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(41);
    head->next->next->next->next->next = createNode(43);
    head->next->next->next->next->next->next = createNode(2);

    head = removeDuplicates(head);
    printList(head);
    return 0;
}