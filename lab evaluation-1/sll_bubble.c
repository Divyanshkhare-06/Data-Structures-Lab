#include<stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
int getLength(struct Node *head) {
    int len = 0;
    struct Node *curr = head;
    while (curr != NULL) {
        len++;
        curr = curr->next;
    }
    return len;
}
struct Node *bubbleSort(struct Node *head) {
    struct Node *currNode = head;
    int len = getLength(head);
    int itr = 0;
    int swapped;
    while (itr < len) {
        struct Node *traverseNode = head;
        struct Node *prevNode = head;
        swapped = 0;
        while (traverseNode->next != NULL) {
            struct Node *ptr = traverseNode->next;
            if (traverseNode->data > ptr->data) {
                swapped = 1;
                if (traverseNode == head) {
                    traverseNode->next = ptr->next;
                    ptr->next = traverseNode;
                    prevNode = ptr;
                    head = prevNode;
                }
                else {
                    traverseNode->next = ptr->next;
                    ptr->next = traverseNode;
                    prevNode->next = ptr;
                    prevNode = ptr;
                }
                continue;
            }
            prevNode = traverseNode;
            traverseNode = traverseNode->next;
        }
        if (!swapped) {
            break;
        }

        ++itr;
    }
    return head;
}
void printList(struct Node *curr) {
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}
struct Node *createNode(int x) {
    struct Node *newNode = 
      (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
int main() {
    struct Node *head = createNode(6);
    head->next = createNode(11);
    head->next->next = createNode(3);
    head->next->next->next = createNode(10);
    head->next->next->next->next = createNode(78);
    head = bubbleSort(head);
    printList(head);
    return 0;
}