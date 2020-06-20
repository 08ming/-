    #include <iostream>
    using namespace std;
    int a[11]={0,6,1,2,7,9,3,4,5,10,8}; //定义一个数组
    void quicksort(int left, int right) //排序函数
    {
        int i,j,t,temp;
        i=left;                         //i赋值为左起点
        j=right;                        //j赋值为右终点
        temp=a[left];                   //temp表示基准数
        if(i>j) return;                 //判断传参是否错误
        while(i != j)
        {
while(a[j]>=temp&&i<j){      //从右至左找到比基准小的数
                j--;
            }
            while(a[i]<=temp&&i<j){      //从左到右找到比基准大的数
                i++;
            }

            if(i!=j){                   //如果i和j没有在一个数上，交换i，j所指两个数的位置
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
        a[left]=a[i];                   //i和j指向一个数时，交换其与基准的值
        a[i]=temp;
        quicksort(left,i-1);            //将基准左边的数排好
        quicksort(i+1,right);           //将基准右边的数排好
        return;
    }
    int main()
    {
        quicksort(1,10);                //调用快速排序的函数
        for(int i = 1; i < 11; i ++){
            cout<<a[i]<<"  ";
        }
        return 0;
    }
