#include <stdio.h>
#include <stdlib.h>
struct Node {
    int value;
    struct Node* next;
};
struct Node *head = NULL, *tail = NULL;
int count = 0;
void enqueue(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = val;
    newNode->next = NULL;
    if (head == NULL && tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}
void showQueue() {
    struct Node* current = head;
    while (current != tail) {
        printf("%d ", current->value);
        current = current->next;
    }
    if (current != NULL)
        printf("%d\n", current->value);
}
void refreshValues() {
    struct Node* ptr = head;
    int i = 1;
    while (i < count && ptr != NULL) {
        ptr->value = i;
        ptr = ptr->next;
        i++;
    }
    showQueue();
}
void dequeue() {
    if (head == NULL && tail == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
    }
    free(temp);
    count--;
    refreshValues();
}
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    enqueue(4);
    enqueue(5);
    dequeue();
    return 0;
}