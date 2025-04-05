#include<stdio.h>
int main (){
    int n,flag,temp;
    printf("enter the size of array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
               temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
                flag++;
            }
        }
        if(flag==0)
        break;
        printf("The number of swaps are %d\n",flag);
    }
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}
