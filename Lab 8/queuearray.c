#include<stdio.h>
int a[10];
int front=-1,rear=-1;
int data;
void enqueue(){
    if(rear==9){
        printf("The queue is full");
    }
    else if(front==-1 && rear==-1){
        printf("Enter the data ");
        scanf("%d",&data);
        front=0;
        rear=0;
        a[rear]=data;
    }
    else{
        printf("Enter the data ");
        scanf("%d",&data);
        rear++;
        a[rear]=data;
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        printf("The queue is empty");
    }
    else if(front==rear){
        printf("The dequeued data is %d",a[front]);
        front=rear=-1;
    }
    else{
        printf("The dequeued data is %d",a[front]);
        front++;
    }
}
void peek(){
    printf("The data is %d",a[front]);
}
void display(){
    if(front==-1 && rear==-1){
        printf("The queue is empty");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d ",a[i]);
        }
    }
}
int main(){
    int choice;
    while(1){
        printf("\n1: enqueue \n2: dequeue \n3: peek\n4 : display\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: peek();
            break;
            case 4: display();
            break;
            default: printf("Invalid choice");
        }
    }
    return 0;
}