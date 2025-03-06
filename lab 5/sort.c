#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* newNode(int x) {
    struct Node* temp = 
        (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}
struct Node* segregateEvenOdd(struct Node* head) {
    struct Node* resStart = NULL;
    struct Node* resEnd = NULL;
    struct Node* curr = head;
    struct Node* prev = NULL;
    while (curr != NULL) {
        if (curr->data % 2 == 0) {
            if (prev != NULL) {
                prev->next = curr->next;
            } else {
                head = curr->next;
            }
            if (resStart == NULL) {
                resStart = curr;
                resEnd = resStart;
            } else {
                resEnd->next = curr;
                resEnd = resEnd->next;
            }
            curr = curr->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    if (resStart == NULL) {
        return head;
    }
    resEnd->next = head;
    return resStart;
}
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
int main() {
    struct Node* head = newNode(0);
    head->next = newNode(10);
    head->next->next = newNode(5);
    head->next->next->next = newNode(20);
    head->next->next->next->next = newNode(21);
    head->next->next->next->next->next = newNode(12);
    head->next->next->next->next->next->next = newNode(14);
    head->next->next->next->next->next->next->next = newNode(7);
    printf("Original Linked list: ");
    printList(head);
    head = segregateEvenOdd(head);
    printf("Modified Linked list: ");
    printList(head);
    return 0;
}