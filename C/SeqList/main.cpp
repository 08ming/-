#include <iostream>
using namespace std;
#include "SeqList.h"
using namespace std;

int main()
{
    int r[5]={1,2,3,4,5};
    SeqList L(r,5);
    cout<<"ִ�в������ǰ����Ϊ��"<<endl;
    L.PrintList();//�������Ԫ��
    try
    {
        L.Insert(2,3);//�ڵڶ���λ�ò���ֵΪ3��Ԫ��
    }
    catch(char *s)
    {
        cout<<s<<endl;
    }
    cout<<"ִ�в������������Ϊ��"<<endl;
    L.PrintList();//�������Ԫ��
    cout<<"ֵΪ3��Ԫ��λ��Ϊ��";t'r's's's
    cout<<L.Locate(3)<<endl;//����Ԫ��3��������˳����е�λ��
    cout<<"ִ��ɾ����һ��Ԫ�ز�����ɾ��ǰ����Ϊ��"<<endl;
    L.PrintList();
    try
    {
        L.Delete(1);//ɾ����һ��Ԫ��
    }
    catch(char *s)
    {
        cout<<s<<endl;
    }
    cout<<"ɾ���������Ϊ��"<<endl;
    L.PrintList();//�������Ԫ��
    return 0;
}
