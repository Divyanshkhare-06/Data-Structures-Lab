#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
int main(){
struct node*head,*newnode,*temp;
int choice;
head=NULL;
while(choice==1){
printf("Do you want to continue (0 for no,1 for yes)");
scanf("%d",&choice);
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter data");
scanf("%d",&newnode->data);
newnode->next=NULL;
if(head==NULL)
head=temp=newnode;
else{
    temp->next=newnode;
    temp=newnode;
}
}
temp=head;
while(temp!=NULL){
    printf("%d",temp->data);
    temp=temp->next;
}
return 0;
}
