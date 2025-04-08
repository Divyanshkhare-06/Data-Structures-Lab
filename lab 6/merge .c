#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newnode = NULL;
    int value;

    for (int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

struct node* mergeLists(struct node* head1, struct node* head2) {
    struct node *mergedHead = NULL, *temp = NULL, *newnode = NULL;

    while (head1 != NULL) {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = head1->data;
        newnode->next = NULL;
        
        if (mergedHead == NULL) {
            mergedHead = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        head1 = head1->next;
    }

    while (head2 != NULL) {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = head2->data;
        newnode->next = NULL;

        if (mergedHead == NULL) {
            mergedHead = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        head2 = head2->next;
    }

    return mergedHead;
}

void display(struct node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n1, n2;
    struct node *head1, *head2, *mergedHead;

    printf("Enter the number of nodes for first linked list: ");
    scanf("%d", &n1);
    head1 = createList(n1);

    printf("Enter the number of nodes for second linked list: ");
    scanf("%d", &n2);
    head2 = createList(n2);

    printf("\nFirst Linked List:\n");
    display(head1);

    printf("\nSecond Linked List:\n");
    display(head2);

    mergedHead = mergeLists(head1, head2);

    printf("\nMerged Linked List:\n");
    display(mergedHead);

    return 0;
}