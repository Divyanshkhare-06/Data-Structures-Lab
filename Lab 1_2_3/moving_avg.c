#include<stdio.h>
int main (){
    int n,l,j;
    printf("enter the size of array: ");
    scanf("%d",&n);
    float a[n];
    printf("Enter the elements of array");
    for(int z=0;z<n;z++){
        scanf("%f",&a[z]);
    }
    printf("Enter the length: ");
    scanf("%d",&l);
    float sum=0,movingavg;
    for(int i=0;i<=n-l;i++){
        sum=0;
        for(j=i;j<i+l;j++){
            sum=sum+a[j];
        }
        movingavg=sum/l;
        printf("The simple moving average is %f\n",movingavg);
    }
    return 0;
}
