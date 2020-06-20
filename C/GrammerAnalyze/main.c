#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdio.h>
char firstvt[maxn][maxn],lastvt[maxn][maxn];

int find(int a,int b)   //优先关系表
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
int inOpTable(char c)    //可以根据返回的数值去优先关系表里面查找优先关系
{                    //还可以判断是否是非终结符，不是非终结符返回0
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
                printf("\n运算符前面没有操作数！\n");
                return 0;
        }
        if((*psc == '+' || *psc == '*') && (*(psc + 1) == '+' || *(psc + 1) == '*'))
        {
                printf("\n运算符号相邻！\n");
                return 0;
        }
        if(*psc == '#' && (*(psc - 1) == '+' || *(psc - 1) == '*'))
        {
                printf("\n运算符后面没有操作数！\n");
                return 0;
        }
        return 1;
}




int main()
{
   int  StackTop;                   //栈顶指针
   char Stack[30] = {'\0'};      //分析栈
   char *lastStack;
   char in_c[50] = {'\0'};   //输入串
   char *InputChar;                //指向当前输入符号
   int  j;
   char q;
   int  isRigth;
   int  n;

while(1)
{

   printf("\n************************************\n");
   printf("请输入要归约的字符串(以‘#’结束)：");
   scanf("%s",in_c);

   n = 1;          //记录步骤
   StackTop = 1;
   Stack[StackTop] = '#';
   Stack[StackTop+1] = '\0';    //初始化
   lastStack = Stack + 1;       //指向栈底
   InputChar = in_c;


   printf("\n步骤\t栈内字符\t\t优先关系\t当前符号\t剩余输入串\t\t\t移进或归约\n");
   while(1)
   {
          if(judge(Stack,StackTop,InputChar) == 0)
          {
                  printf("\n出错！\n");
                  break;
          }

          if(inOpTable(Stack[StackTop]))
              j = StackTop;
          else
              j = StackTop - 1;

          isRigth = find(inOpTable(Stack[j]),inOpTable(*InputChar));
          if(isRigth == 1)  //如果s[j] > 当前输入字符
          {
               do
               {
                   q = Stack[j];
                   if(inOpTable(Stack[j-1]))
                        j--;
                   else
                        j = j - 2;
               }while(find(inOpTable(Stack[j]),inOpTable(q)) != -1);

               printf("(%d)\t%-24s>\t\t%c\t\t%-32s归约\n",n++,lastStack,*InputChar,InputChar+1);
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
                   printf("%-32s移进\n",InputChar);
                   continue;
               }
               else if(isRigth == 0)
                    {
                          if(Stack[j] == '#')
                          {
                               printf("(%d)\t%-24s=\t\t#\t\t\t\t\t\t接受\n",n,lastStack);
                               printf("\n归约成功！\n");
                               break;
                          }
                          else
                          {
                               printf("(%d)\t%-24s=\t\t%c\t\t",n++,lastStack,*InputChar);
                               StackTop++;
                               Stack[StackTop] = *InputChar;
                               Stack[StackTop+1] = '\0';
                               InputChar++;
                               printf("%-32s移进\n",InputChar);
                               continue;
                          }
                     }
                     else
                     {
                          printf("(%d)\t%-24s无\t\t%c\t\t%-32s\\\n",n++,lastStack,*InputChar,InputChar+1);
                          printf("\n错误！\n");
                          break;
                     }

   }

}

 return 0;
}

