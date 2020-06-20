#include <iostream>

using namespace std;
int a[31]={0};
int main(){
    int v,n,i,sum=0,Max=0,j;
    cin>>v>>n;
    for( i = 0;i<n;i++)
        cin>>a[i];
    for(i =0;i<n;i++){
        for(j = 0;sum<=v&&j<n;j++){
            sum+=a[j];
        }
        if(sum>v)
            sum-=a[j];
        if(sum>Max)
            Max=sum;
        sum = 0;
    }
    cout<<v-Max;


    return 0;
}
