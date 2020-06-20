#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdio.h>
char firstvt[maxn][maxn],lastvt[maxn][maxn];

int find(int a,int b)   //���ȹ�ϵ��
{
    int table[6][6] = {
                       1, -1, -1, -1, 1, 1,
                       1,  1, -1, -1, 1, 1,
                       1,  1,  2,  2, 1, 1,
                      -1,- 1, -1, -1, 0, 2,
                       1,  1,  2,  2, 1, 1,
                      -1, -1,- 1, -1, 2, 0
                      };

  return table[a-1][b-1];

}
int inOpTable(char c)    //���Ը��ݷ��ص���ֵȥ���ȹ�ϵ������������ȹ�ϵ
{                    //�������ж��Ƿ��Ƿ��ս�������Ƿ��ս������0
   int n;

   switch(c)
   {
       case '+': n = 1; break;
       case '*': n = 2; break;
       case 'i': n = 3; break;
       case '(': n = 4; break;
       case ')': n = 5; break;
       case '#': n = 6; break;
       default : n = 0;
   }
   return n;
}

int judge(char *p,int k,char *psc)
{

        if(k == 1 && p[k] == '#' && (*psc == '+' || *psc == '*'))
        {
                printf("\n�����ǰ��û�в�������\n");
                return 0;
        }
        if((*psc == '+' || *psc == '*') && (*(psc + 1) == '+' || *(psc + 1) == '*'))
        {
                printf("\n����������ڣ�\n");
                return 0;
        }
        if(*psc == '#' && (*(psc - 1) == '+' || *(psc - 1) == '*'))
        {
                printf("\n���������û�в�������\n");
                return 0;
        }
        return 1;
}




int main()
{
   int  StackTop;                   //ջ��ָ��
   char Stack[30] = {'\0'};      //����ջ
   char *lastStack;
   char in_c[50] = {'\0'};   //���봮
   char *InputChar;                //ָ��ǰ�������
   int  j;
   char q;
   int  isRigth;
   int  n;

while(1)
{

   printf("\n************************************\n");
   printf("������Ҫ��Լ���ַ���(�ԡ�#������)��");
   scanf("%s",in_c);

   n = 1;          //��¼����
   StackTop = 1;
   Stack[StackTop] = '#';
   Stack[StackTop+1] = '\0';    //��ʼ��
   lastStack = Stack + 1;       //ָ��ջ��
   InputChar = in_c;


   printf("\n����\tջ���ַ�\t\t���ȹ�ϵ\t��ǰ����\tʣ�����봮\t\t\t�ƽ����Լ\n");
   while(1)
   {
          if(judge(Stack,StackTop,InputChar) == 0)
          {
                  printf("\n����\n");
                  break;
          }

          if(inOpTable(Stack[StackTop]))
              j = StackTop;
          else
              j = StackTop - 1;

          isRigth = find(inOpTable(Stack[j]),inOpTable(*InputChar));
          if(isRigth == 1)  //���s[j] > ��ǰ�����ַ�
          {
               do
               {
                   q = Stack[j];
                   if(inOpTable(Stack[j-1]))
                        j--;
                   else
                        j = j - 2;
               }while(find(inOpTable(Stack[j]),inOpTable(q)) != -1);

               printf("(%d)\t%-24s>\t\t%c\t\t%-32s��Լ\n",n++,lastStack,*InputChar,InputChar+1);
               StackTop = j + 1;
               Stack[StackTop] = 'N';
               Stack[StackTop+1] = '\0';
               continue;
          }
          else if(isRigth == -1)
               {
                   printf("(%d)\t%-24s<\t\t%c\t\t",n++,lastStack,*InputChar);
                   StackTop++;
                   Stack[StackTop] = *InputChar;
                   Stack[StackTop+1] = '\0';
                   InputChar++;
                   printf("%-32s�ƽ�\n",InputChar);
                   continue;
               }
               else if(isRigth == 0)
                    {
                          if(Stack[j] == '#')
                          {
                               printf("(%d)\t%-24s=\t\t#\t\t\t\t\t\t����\n",n,lastStack);
                               printf("\n��Լ�ɹ���\n");
                               break;
                          }
                          else
                          {
                               printf("(%d)\t%-24s=\t\t%c\t\t",n++,lastStack,*InputChar);
                               StackTop++;
                               Stack[StackTop] = *InputChar;
                               Stack[StackTop+1] = '\0';
                               InputChar++;
                               printf("%-32s�ƽ�\n",InputChar);
                               continue;
                          }
                     }
                     else
                     {
                          printf("(%d)\t%-24s��\t\t%c\t\t%-32s\\\n",n++,lastStack,*InputChar,InputChar+1);
                          printf("\n����\n");
                          break;
                     }

   }

}

 return 0;
}

