#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next,*prev;
};
struct node*head,*newnode,*temp;
void create(){
    head=NULL;
    int choice=1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
        printf("do you want to continue 0,1 [0 for NO & 1 for YES]");
        scanf("%d",&choice);
    }
}
void display_forward(){
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void display_backward(){
    temp=newnode;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
}
int main(){
    create();
    display_forward();
    printf("\n");
    display_backward();
}
 


