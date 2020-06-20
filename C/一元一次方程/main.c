#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    int a[3][4],i,j,max1=0,max2=0;
    for(i=0;i<3;i++)
    for(j=0;j<4;j++)
        scanf("%d",&a[i][j]);
    for(i=0;i<3;i++){
    for(j=0;j<4;j++){
        if(abs(a[i][j])>abs(a[max1][max2]))
            {max1=i;max2=j;}
    }
    }
    printf("%d %d %d",a[max1][max2],max1+1,max2+1);
    return 0;

}
