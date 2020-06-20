#include<bits/stdc++.h>
using namespace std;

void  findIn(int index,int n,int sum);
int a[16][16]={0};
bool flag[16] = {true};
int maxSum = 999999, temp = 999999;
int main()
{
    int n;
    cin >> n;
    int a[16][16];
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cin>>a[i][j];
        }
    }

    findIn(0,n,0);
    cout<<maxSum;

}

void  findIn(int i,int n,int sum)
{
    if(i == n && sum < maxSum){
        maxSum = sum;
    }
    if(sum < maxSum){
        for(int j = 0; j < n; j++){
            if(flag[j]){
                flag[j] = false;
                findIn(i+1,n,sum + a[i][j]);
                flag[i] = true;
            }
        }
    }
}
