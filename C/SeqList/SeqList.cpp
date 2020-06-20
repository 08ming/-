#include<iostream>
using namespace std;
#include "SeqList.h"//����ͷ�ļ�����
//��Ա�����Ķ���
SeqList::SeqList(int a[],int n)
{
    if(n>MaxSize) throw "�����Ƿ�";
    for(int i=0;i<n;i++)
        data[i]=a[i];
    length = n;
}

void SeqList::Insert(int i,int x)
{
    if(length+1>MaxSize) throw "����";
    if(i<1||i>length+1) throw "λ�÷Ƿ�";
    for(int j=length;j>=i;j--)
        data[j] = data[j-1];//����j��Ԫ�ش����j-1��
    data[i-1]=x;
    length++;
}

int SeqList::Delete(int i)
{
    if(length == 0) throw "����";
    if(i<1||i>length+1) throw "λ�÷Ƿ�";
    int x = data[i-1];
    for(int j=i;j<length;j++)
    {
        data[j-1]=data[j];//�˴�j�Ѿ���Ԫ�����ڵ��±�
    }
    length--;
    return x;

}

int SeqList::Locate(int x)
{
    for(int i =0;i<length;i++)
        if(data[i]==x)//�±�Ϊi��Ԫ�����Ϊi+1
        return i+1;//�˳�ѭ��������ʧ��
    return 0;
}

void SeqList::PrintList()
{
    for(int i=0;i<length;i++)
        cout<<data[i]<<" ";
    cout<<endl;
}
