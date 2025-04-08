#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *newnode, *temp, *curr;
int count = 0;

void createnode() {
    int choice = 1;
    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        count++;
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue? [0 for NO & 1 for YES]: ");
        scanf("%d", &choice);
    }
    temp->next = head;  // Making circular
}

void insert() {
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos >= 1 && pos <= count + 1) {
        struct node *nnode = (struct node*)malloc(sizeof(struct node));
        count++;
        printf("Enter the data: ");
        scanf("%d", &nnode->data);

        if (pos == 1) {
            nnode->next = head;
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = nnode;
            head = nnode;
        } else {
            curr = head;
            for (int i = 1; i < pos - 1; i++) {
                curr = curr->next;
            }
            nnode->next = curr->next;
            curr->next = nnode;
        }
    } else {
        printf("Invalid position\n");
    }
}

void delete() {
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos >= 1 && pos <= count) {
        count--;
        if (pos == 1) {
            curr = head;
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
            free(curr);
        } else {
            temp = head;
            for (int i = 1; i < pos - 1; i++) {
                temp = temp->next;
            }
            curr = temp->next;
            temp->next = curr->next;
            free(curr);
        }
    } else {
        printf("Invalid position\n");
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    int i = 0;
    printf("Circular Linked List: ");
    while (i < count) {
        printf("%d ", temp->data);
        temp = temp->next;
        i++;
    }
    printf("\n");
}

int main() {
    createnode();
    int ch;
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (ch != 4);

    return 0;
}