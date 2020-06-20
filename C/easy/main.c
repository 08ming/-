#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    int a[6]={3},i,man;
    for( i=2;i<6;i++)
        a[i]=pow(3,i-1)+a[i-1];
    int n,d=0;
    scanf("%d",&n);
    for( i=1;n>=10;i*=10){
        n=n/i;
        d++;
    }
    if(n<3&&d==0){
        printf("%d",n+1);
    }
    else if(n<10&&d==0){
        printf("3");
    }
    else{
        if(n<3){
                man=pow(a[d],n);
            printf("%d",man);
        }
        else{
            printf("%d",a[d+1]);
        }
    }
    return 0;
}
