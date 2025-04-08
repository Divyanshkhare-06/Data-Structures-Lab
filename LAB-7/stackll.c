#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* top = NULL; 
void push(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory Overflow\n");
        return;
    }
    newnode->data = value;
    newnode->next = top;
    top = newnode;
    printf("%d pushed into stack\n", value);
}
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct node* temp = top;
    printf("Popped element: %d\n", top->data);
    top = top->next;
    free(temp);
}
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
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
        
        switch(choice) {
            case 1:
                printf("Enter the value to push: ");
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
                printf("Invalid choice\n");
        }
    }
    return 0;
}