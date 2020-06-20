
#include<iostream>
using namespace std;
int main()
{
    short i,j,n,k;
    cin>>n>>i>>j;
    for(k=1;k<=n;k++)
        cout<<"("<<i<<","<<k<<")";
    cout<<endl;
    for(k=1;k<=n;k++)
        cout<<"("<<k<<","<<j<<")";
    cout<<endl;
    short a;
    for(a=i,k=j;a!=1||k!=1;a--,k--){};
    for( ;a<=n&&k<=n;a++,k++)
        cout<<"("<<a<<","<<k<<")";
    cout<<endl;
    for(a=i,k=j;a!=n||k!=n;a++,k++){};
    for( ;a>=1&&k>=1;a--,k--)
        cout<<"("<<a<<","<<k<<")";
    cout<<endl;
    return 0;
}
