#include<bits/stdc++.h>
using namespace std;
const int maxx=1e5+5;
int a[maxx];
int cnt=0;
//��ȫ����
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
    if(st==en)//���ʱ����ʱa[i]����һ��ȫ����
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
            if(IsSwap(st,i))//�ж�����Ԫ���Ƿ����
            {
                swap(st,i);//ÿ��Ԫ�����һ��Ԫ�ؽ���
                print(st+1,en);
                swap(i,st);//��Ԫ�ؽ�������������ԭ
            }
        }
    }
}
void solve(int n,int k)
{
    for(int i=n;i>=1;i--)
    {
        if(i<=a[k-1])//  //�����ǰ�ֽ����iС�ڵ�����һ��������ɼ����ֽ�
        {
            a[k]=i;//��i����
            if(i==n)
            {
                cnt++;//������+1
                print(1,k);//��ӡ
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
    cout<<"������"<<cnt<<endl;

    return 0;
}
