#include<stdio.h>
int main(){
    int n,i,j=0;
    printf("Enter the size of array");
    scanf("%d",&n);
    int a[n],b[n];
    printf("Enter the elements of array");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=n-1;i>=0;i--){
        b[j]=a[i];
        j++;
    }
    for(i=0;i<n;i++){
        printf("%d\n",b[i]);
    }
    return 0;
}
