#include <iostream>
using namespace std;
#include "SeqList.h"
using namespace std;

int main()
{
    int r[5]={1,2,3,4,5};
    SeqList L(r,5);
    cout<<"执行插入操作前数据为："<<endl;
    L.PrintList();//输出所有元素
    try
    {
        L.Insert(2,3);//在第二个位置插入值为3的元素
    }
    catch(char *s)
    {
        cout<<s<<endl;
    }
    cout<<"执行插入操作后数据为："<<endl;
    L.PrintList();//输出所有元素
    cout<<"值为3的元素位置为：";t'r's's's
    cout<<L.Locate(3)<<endl;//查找元素3，返回在顺序表中的位置
    cout<<"执行删除第一个元素操作，删除前数据为："<<endl;
    L.PrintList();
    try
    {
        L.Delete(1);//删除第一个元素
    }
    catch(char *s)
    {
        cout<<s<<endl;
    }
    cout<<"删除后的数据为："<<endl;
    L.PrintList();//输出所有元素
    return 0;
}
