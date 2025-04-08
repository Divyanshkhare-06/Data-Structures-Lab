#include<stdio.h>
int top=-1;
int stack[10];
void push(){
    int data;
    if(top==10-1)
    printf("Overflow");
    else{
        printf("Enter the data you want to push: ");
        scanf("%d",&data);
        top++;
        stack[top]=data;
    }
}
void pop(){
    int temp;
    if(top==-1){
        printf("Underflow");
    }
    else{
        temp=stack[top];
        top--;
        printf("The popped element is %d\n",temp);
    }
}
void display(){
    int i=top;
    for(i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
}
void peek(){
    printf("%d\n",stack[top]);
}
int main(){
push();
push();
push();
push();
peek();
pop();
pop();
push();
display();
}

