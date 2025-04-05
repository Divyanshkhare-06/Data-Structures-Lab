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
void display (){
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void insert_pos(){
    int pos;
    printf("Enter the position: ");
    scanf("%d",&pos);
    struct node*anode,*bnode,*curr;
    anode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data of inserted node");
    scanf("%d",&anode->data);
    anode->next=NULL;
    anode->prev=NULL;
    int i=1;
    curr=head;
    while(i!=pos-1){
        curr=curr->next;
        i++;
    }
    anode->next=curr->next;
    anode->prev=curr;
    bnode=curr->next;
    curr->next=anode;
    bnode->prev=anode;
}
int main(){
    create();
    display();
    printf("\n");
    insert_pos();
    display();
}