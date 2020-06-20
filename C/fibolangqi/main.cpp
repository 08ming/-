#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a[1001],b[1001],n,m,i,j,c[2000],d[1000],k=0,q,flag=1;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    for(i=0;i<m;i++)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    for(i = 0;i<n;i++){
        for(j = 0;j<m;j++){
            if(a[i]==b[j]){
                d[k]=a[i];
                k++;
                cout<<a[i]<<" ";
            }
        }
    }
    cout<<endl;
    for(i=0;i<n;i++){
        c[i]=a[i];
    }
    for(j=0;j<m;j++,i++){
        for(q=0;q<k;q++)
        {
            if(d[q]==b[j]){flag=0;break;}
        }
        if(flag)
            c[i] = b[j];
    }
    sort(c,c+m+n);
    for(i = 0;i<m+n;i++)
        cout<<c[i]<<" ";
    return 0;
}
