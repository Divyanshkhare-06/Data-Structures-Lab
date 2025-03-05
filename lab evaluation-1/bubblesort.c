#include<stdio.h>
int main(){
    int i,j,n,temp;
    int a[n];
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter the elements of array");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++){
        int flag=0;
        for(j=0;j<n-i-1;j++){
            if(a[j+1]<a[j]){
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
                
            }
            flag=1;
        }
        if(flag==0)
        break;
    }
    printf("The sorted array is: ");
    for(i=0;i<n;i++){
        printf("%d",a[i]);
    }
    return 0;
}