
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
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}


