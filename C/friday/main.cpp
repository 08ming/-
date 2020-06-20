#include <iostream>

using namespace std;

int main()
{
    int y,i,days=4,a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},total=0,j,sum=0;
    cin>>y;
    for(i=1999;i<=y;i++)
    {
        if(((i%4==0)&&(i%100!=0))||((i%100==0)&&(i%400==0)))
            days=days+2;
        else
            days=days+1;
    }
    for(i=1;i<13;i++){
        for(j=1;j<i;j++){
            if(j==2&&(((y%4==0)&&(y%100!=0))||((y%100==0)&&(y%400==0))))
                total+=29;
            else
                total+=a[j];
        }
        total+=12;
        if((total+days)%7==5)
            sum++;
        total=0;
    }
    cout<<sum;
    return 0;

}
