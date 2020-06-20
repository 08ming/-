#include <iostream>
#include<cmath>
#define size 52
using namespace std;


 #define MAX_NUM 52

  int map[MAX_NUM][MAX_NUM];     //好心程度 | 权值
  int dp[MAX_NUM][MAX_NUM][MAX_NUM][MAX_NUM];

 int maxPath(int m, int n)
 {
     for (int x1 = 1; x1 <= m; x1++)
    {
         for (int y1 = 1; y1 <= n; y1++)
         {
             for (int x2 = 1; x2 <= m; x2++)
           {
                for (int y2 = 1; y2 <= n; y2++)
                 {
                     /*
                         如果第一个人没有走到最后一行或最后一列，并且两个人没有重复
                         因为走到最后一行或最后一列，容易造成第二个人无路可走的情况
                     */
                     if ((x1 < m || y1 < n) && x1 == x2 && y1 == y2)
                     {
                         continue;
                     }
                     dp[x1][y1][x2][y2] = max( max(dp[x1-1][y1][x2-1][y2], dp[x1-1][y1][x2][y2-1]),
                                               max(dp[x1][y1-1][x2-1][y2], dp[x1][y1-1][x2][y2-1]))
                                              + map[x1][y1] + map[x2][y2];
                 }
            }
         }
     }
     return dp[m][n][m][n];
 }

 int main()
 {
     int m, n;
     cin>>m>>n;

     for (int i = 1;i <= m; i++)
        for (int j = 1;j <= n; j++)
             cin>>map[i][j];

     int ans = maxPath(m, n);
     cout<<ans<<endl;

     return 0;
 }
/*int a[size][size][size][size]={0};
int map[size][size]={0};
int maxPath(int m,int n){
    for(int x1=1;x1<=m;x1++){
        for(int y1=1;y1<=n;y1++){
            for(int x2=1;x2<=m;x2++){
                for(int y2=1;y2<=n;y2++){
                    if((x1<m||y1<n)&&x1==x2&&y1==y2){
                        continue;
                    }
                    a[x1][y1][x2][y2]=max(max(a[x1-1][y1][x2-1][y2],a[x1-1][y1][x2][y2-1]),max(a[x1][y1-1][x2-1][y2],a[x1][y1-1][x2][y2-1]))+map[x1][y1]+map[x2][y2];
                }
            }
        }
    }
    return a[m][n][m][n];
}
int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
        cin>>map[i][j];
    int ans=maxPath(m,n);
    cout<<ans<<endl;
    return 0;
}
*/
