//�����ظ�����ͷ�ļ�
#ifndef SEQLIST_H_INCLUDED
#define SEQLIST_H_INCLUDED

const int MaxSize = 10;//���Ա������10��Ԫ��
class SeqList
{
private:
    int length;
    int data[MaxSize];
public:
    SeqList(){length = 0;}//�޲ι��캯��������һ���ձ�
    SeqList(int a[],int n);//�вι��캯��
    ~SeqList(){}//��������
    void Insert(int i,int x);//�����Ա��i��λ�ò���ֵΪx��Ԫ��
    int Delete(int i);//ɾ�����Ա�ĵ�i��Ԫ��
    int Locate(int x);//�����Ա���ֵΪx��Ԫ�����
    void PrintList();//��������������Ԫ��
};


#endif // SEQLIST_H_INCLUDED
