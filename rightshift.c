#include<stdio.h>
int main (){
    int n,d,i;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int a[n+1];
    printf("Enter the elements of array");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=n-1;i>=0;i--){
        a[i+1]=a[i];
    }
    a[0]=0;
    for(i=0;i<n+1;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}