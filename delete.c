
#include<stdio.h>
int main (){
    int n;
    printf("enter the size of array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
     int pos;
    printf("Enter the postion: ");
    scanf("%d",&pos);
    //delete from the end
    if(pos==n){
    for(int i=0;i<n-1;i++){
        printf("%d\n",a[i]);
    }
    }
    //delete from any specific position 
    else if(pos>=1 && pos<n){
    for(int i=pos-1;i<n-1;i++){
        a[i]=a[i+1];
    }
    for(int i=0;i<n-1;i++){
        printf("%d\n",a[i]);
    }
    }
    return 0;
}