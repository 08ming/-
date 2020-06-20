#include<iostream>
using namespace std;
#include "SeqList.h"//引入头文件声明
//成员函数的定义
SeqList::SeqList(int a[],int n)
{
    if(n>MaxSize) throw "参数非法";
    for(int i=0;i<n;i++)
        data[i]=a[i];
    length = n;
}

void SeqList::Insert(int i,int x)
{
    if(length+1>MaxSize) throw "上溢";
    if(i<1||i>length+1) throw "位置非法";
    for(int j=length;j>=i;j--)
        data[j] = data[j-1];//将第j个元素存入第j-1处
    data[i-1]=x;
    length++;
}

int SeqList::Delete(int i)
{
    if(length == 0) throw "下溢";
    if(i<1||i>length+1) throw "位置非法";
    int x = data[i-1];
    for(int j=i;j<length;j++)
    {
        data[j-1]=data[j];//此处j已经是元素所在的下标
    }
    length--;
    return x;

}

int SeqList::Locate(int x)
{
    for(int i =0;i<length;i++)
        if(data[i]==x)//下表为i的元素序号为i+1
        return i+1;//退出循环，查找失败
    return 0;
}

void SeqList::PrintList()
{
    for(int i=0;i<length;i++)
        cout<<data[i]<<" ";
    cout<<endl;
}
