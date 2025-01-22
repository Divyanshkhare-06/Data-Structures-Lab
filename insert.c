#include<stdio.h>
int main (){
    int n;
    printf("enter the size of array: ");
    scanf("%d",&n);
    int a[n+1];
    printf("Enter the elements of array");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
     int pos,num,i;
    printf("Enter the postion: ");
    scanf("%d",&pos);
    printf("Enter the new number: ");
    scanf("%d",&num);
    //insertion at end 
    if(pos==n){
        a[n]=num;
        for(i=0;i<n+1;i++){
            printf("%d\n",a[i]);
        }    
    }
   // insertion at specific position 
   if(pos>=1 && pos<n){
    for(i=n;i>pos-1;i--){
        a[i]=a[i-1];
    }
    a[pos-1]=num;
    for(i=0;i<n+1;i++){
        printf("%d\n",a[i]);
    }
   }
   return 0;
}
