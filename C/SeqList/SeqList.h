//避免重复包含头文件
#ifndef SEQLIST_H_INCLUDED
#define SEQLIST_H_INCLUDED

const int MaxSize = 10;//线性表最多有10个元素
class SeqList
{
private:
    int length;
    int data[MaxSize];
public:
    SeqList(){length = 0;}//无参构造函数，创建一个空表
    SeqList(int a[],int n);//有参构造函数
    ~SeqList(){}//析构函数
    void Insert(int i,int x);//在线性表第i个位置插入值为x的元素
    int Delete(int i);//删除线性表的第i个元素
    int Locate(int x);//求线性表中值为x的元素序号
    void PrintList();//按序号依次输出各元素
};


#endif // SEQLIST_H_INCLUDED
