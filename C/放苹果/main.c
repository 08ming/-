#include<bits/stdc++.h>
using namespace std;
const int maxx=1e5+5;
int a[maxx];
int cnt=0;
//求全排列
bool IsSwap(int st,int en)
{
    for(int i=st;i<en;i++)
    {
        if(a[i]==a[en])
            return false;
    }
    return true;
}
void swap(int i,int j)
{
    int t;
    t=a[j];
    a[j]=a[i];
    a[i]=t;
}
void print(int st,int en)
{
    if(st==en)//相等时，此时a[i]就是一个全排列
    {
        cout<<a[0]<<"=";
        for(int i=1;i<=en;i++)
        {
            cout<<a[i];
            if(i!=en)
                cout<<"+";
        }
        cout<<endl;
        return ;
    }
    else
    {
        for(int i=st;i<=en;i++)
        {
            if(IsSwap(st,i))//判断两个元素是否相等
            {
                swap(st,i);//每个元素与第一个元素交换
                print(st+1,en);
                swap(i,st);//将元素交换回来，即复原
            }
        }
    }
}
void solve(int n,int k)
{
    for(int i=n;i>=1;i--)
    {
        if(i<=a[k-1])//  //如果当前分解出的i小于等于上一个数，则可继续分解
        {
            a[k]=i;//将i保存
            if(i==n)
            {
                cnt++;//划分数+1
                print(1,k);//打印
            }
            else
            {
                solve(n-i,k+1);
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    a[0]=n;
    solve(n,1);
    cout<<"划分数"<<cnt<<endl;

    return 0;
}
