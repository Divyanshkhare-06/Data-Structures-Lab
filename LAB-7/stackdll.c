#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* top = NULL;  
void push(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (top == NULL) {
        top = newnode;
    }
    else {
        newnode->prev = top;
        top->next = newnode;
        top = newnode;
    }
    printf("%d pushed into stack\n", value);
}
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    printf("Popped element: %d\n", top->data);
    struct node* temp = top;
    top = top->prev;

    if (top != NULL) {
        top->next = NULL;
    }

    free(temp);
}
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    struct node* temp = top;
    printf("Stack elements (top to bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}