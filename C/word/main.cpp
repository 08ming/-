#include <iostream>
#include <algorithm>
using namespace std;
bool myfunction2 (int i,int j) { return (i>j); }
int main()
{
    //map为地图，bookx为X行需要分隔，记为1
    int bookx[2001]={0},booky[2001]={0};
    int M,N,K,L,D,i,x1,x2,y1,y2;
    cin>>M>>N>>K>>L>>D;
    for(i=1;i<=D;i++)
    {
        //对每组输入进行判断
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2)
        {
            if(y1>y2)
                booky[y2]++;
            else
                booky[y1]++;
        }
        else
        {
            if(x1>x2)
                bookx[x2]++;
            else
                bookx[x1]++;
        }
    }
    sort(bookx+1,bookx+2001,myfunction2);
    sort(booky+1,booky+2001,myfunction2);
    for(int i =1;i<=K;i++)
        if(bookx[i]!=0)
        cout<<i<<" ";
    cout<<endl;
    for(int i =1;i<=L;i++)
        if(booky[i]!=0)
        cout<<i<<" ";
        return 0;
}
