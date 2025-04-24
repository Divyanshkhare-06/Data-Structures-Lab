#include <stdio.h>
#include <stdlib.h>
#define MAX 10 
struct Node {
    int data;
    struct Node* next;
};
struct Queue {
    struct Node *front, *rear;
};
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(struct Queue* q, int num) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = num;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
void dequeue(struct Queue* q) {
    if (q->front == NULL)
        return;
    struct Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
}
int firstNonRepeating(int stream[], int size) {
    int freq[MAX] = {0};  
    struct Queue* q = createQueue();
    for (int i = 0; i < size; i++) {
        int num = stream[i];
        if (num < 0 || num >= MAX) {
            printf("Error: Number out of range. Allowed numbers are between 0 and 9.\n");
            return -1;
        }
        freq[num]++;
        enqueue(q, num);
        while (q->front && freq[q->front->data] > 1) {
            dequeue(q);
        }
        if (q->front) {
            return q->front->data;
        }
    }
    return -1;  
}
int main() {
    int n;
    printf("Enter the number of elements in the stream: ");
    scanf("%d", &n);
    int stream[n];
    printf("Enter %d numbers for the stream (only numbers between 0 and 9): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &stream[i]);
    }
    int result = firstNonRepeating(stream, n);
    if (result != -1) {
        printf("First non-repeating number: %d\n", result);
    } else {
        printf("No non-repeating number found.\n");
    }
    return 0;
}