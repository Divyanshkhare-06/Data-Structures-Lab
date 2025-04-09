#include<stdio.h>
int front=-1;
int rear=-1;
int queue[10];
int data;
void isempty(){
    if(front==-1&&rear==-1){
        printf("The queue is empty");
    }
}
int isfull(){
    if(rear==10-1){
        printf("The queue is full");
    }
    return 0;
}
void enqueue(){
   
    isfull();
    
        printf("Enter the data");
        scanf("%d",&data);
        if(front==-1){
            front=0;
        }
        rear=rear+1;
    queue[rear]=data;
}

void dequeue(){
    isempty();
    
        printf("The deleted element is %d",queue[front]);
        front=front+1;
        if(front>rear){
            front=-1;
            rear=-1;
        }
    
}
void display(){
    int i;
    isempty();
    
        for(i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    
}
int main(){
    int choice;
    while(1){
        printf("Enter your choice\n1.enqueue\n2.dequeue\n3.display\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            default:
            printf("Invalid choice");
        }
}
return 0;
}


