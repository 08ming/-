    #include <iostream>
    using namespace std;
    int a[11]={0,6,1,2,7,9,3,4,5,10,8}; //����һ������
    void quicksort(int left, int right) //������
    {
        int i,j,t,temp;
        i=left;                         //i��ֵΪ�����
        j=right;                        //j��ֵΪ���յ�
        temp=a[left];                   //temp��ʾ��׼��
        if(i>j) return;                 //�жϴ����Ƿ����
        while(i != j)
        {
while(a[j]>=temp&&i<j){      //���������ҵ��Ȼ�׼С����
                j--;
            }
            while(a[i]<=temp&&i<j){      //�������ҵ��Ȼ�׼�����
                i++;
            }

            if(i!=j){                   //���i��jû����һ�����ϣ�����i��j��ָ��������λ��
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
        a[left]=a[i];                   //i��jָ��һ����ʱ�����������׼��ֵ
        a[i]=temp;
        quicksort(left,i-1);            //����׼��ߵ����ź�
        quicksort(i+1,right);           //����׼�ұߵ����ź�
        return;
    }
    int main()
    {
        quicksort(1,10);                //���ÿ�������ĺ���
        for(int i = 1; i < 11; i ++){
            cout<<a[i]<<"  ";
        }
        return 0;
    }
