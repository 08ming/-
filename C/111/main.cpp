#include<iostream>
using namespace std;
bool istree=true;
int parent[4001];
int node[4001];
void init()
{
   for(int i=1;i<=4000;i++)
   {
     parent[i]=-1;
node[i]=-1;
   }
   istree=true;


}
int find(int a)
{
    while(parent[a]>0)
{
  a=parent[a];
}
return a;


}
void combine(int a,int b,int &head)
{
   int p1=find(a);
   int p2=find(b);
   if(p1==p2)
   {
      istree=false;
 return;
   }
   else{
  if(parent[p1]>=parent[p2])
  {
  head=p2;
  parent[p2]+=parent[p1];
      parent[p1]=p2;
  
         
  }
  else{
  head=p1;
  parent[p1]+=parent[p2];
      parent[p2]=p1;
  
  
  }
 
   
   
   }




}
int main()
{
//freopen("in.txt","r",stdin);


  int a,b;
  int k=0;
  while(scanf("%d%d",&a,&b)&&(a>=00&&b>=0))
  {
 int count=0;
 int head=0;
 k++;
      init();
 int temp=a;
 if(a==0&&b==0)
 {
          printf("Case %d is a tree.\n",k);
 continue;
 }
 combine(a,b,head);
 if(node[a]==-1)
 {
    count++;
node[a]=0;
 }
 if(node[b]==-1)
 {
   count++;
node[b]=0;
 
 }
 cin>>a>>b;
 while(a!=0&&b!=0)
 {
    
   if(istree)
{
  
    if(node[a]==-1)
{
        count++;
    node[a]=0;
}
       if(node[b]==-1)
{
        count++;
    node[b]=0;
 
}
   combine(a,b,head);


}
cin>>a>>b;

 
 }
 int len=parent[head]*(-1);


 if(istree&&len==count)
 {
    printf("Case %d is a tree.\n",k);
 
 
 }
 else{
   printf("Case %d is not a tree.\n",k);
 }
 
  
  
  }
  return 0;


}
