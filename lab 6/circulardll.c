#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL, *tail = NULL, *newnode, *temp;
int count = 0;
void createNode() {
    int choice = 1;
    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = newnode->prev = NULL;
        count++;

        if (head == NULL) {
            head = tail = newnode;
            head->next = head;
            head->prev = head;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            head->prev = newnode;
            tail = newnode;
        }
        printf("Do you want to continue? [1-Yes / 0-No]: ");
        scanf("%d", &choice);
    }
}
void insert() {
    int pos;
    printf("Enter position to insert: ");
    scanf("%d", &pos);

    if (pos >= 1 && pos <= count + 1) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = newnode->prev = NULL;
        count++;

        if (pos == 1) {
            newnode->next = head;
            newnode->prev = tail;
            tail->next = newnode;
            head->prev = newnode;
            head = newnode;
        } else if (pos == count) {
            newnode->next = head;
            newnode->prev = tail;
            tail->next = newnode;
            head->prev = newnode;
            tail = newnode;
        } else {
            temp = head;
            for (int i = 1; i < pos - 1; i++) {
                temp = temp->next;
            }
            newnode->next = temp->next;
            newnode->prev = temp;
            temp->next->prev = newnode;
            temp->next = newnode;
        }
    } else {
        printf("Invalid Position\n");
    }
}
void delete() {
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos >= 1 && pos <= count) {
        count--;

        if (pos == 1) {
            temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            free(temp);
        } else if (pos == count + 1) {
            temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            free(temp);
        } else {
            temp = head;
            for (int i = 1; i < pos; i++) {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
    } else {
        printf("Invalid Position\n");
    }
}
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    printf("Doubly Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    createNode();
    int ch;
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid Choice\n");
        }
    } while (ch != 4);

    return 0;
}