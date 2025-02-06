//题目链接：https://www.lanqiao.cn/problems/551/learning/?page=1&first_category_id=1&problem_id=551
#pragma once 
#include <iostream>
using namespace std;
const int N = 120;
//a是灌溉前一分钟的数组，b是灌溉后的数组，每次灌溉的时候用b替换a实现更新
bool a[N][N],b[N][N];


int main()
{
  //初始化数组
  int n,m;
  cin>>n>>m;
 
 int t;
 cin>>t;
 //记录水管的位置
 for(int i = 1;i<=t;i++)
 {
   int x,y;
   cin>>x>>y;
   a[x][y] =1;
 }

 //开始灌溉
 int k;
 cin>>k;
 while(k--)
 {
   for(int i = 1;i<=n;i++)
   {
     for(int j = 1;j<=m;j++) //开始灌溉
     {
       if(a[i][j])
       {
         b[i][j] = b[i - 1][j] = b[i + 1][j] = b[i][j - 1] =b[i][j + 1] = 1;
       }
     }
   }

   //灌溉之后将b替换a
   for(int i = 1;i<=n;i++)
   {
     for(int j = 1;j<=m;j++)
     {
       a[i][j] = b[i][j];
     }
   }
 }

 //数格子
 int ans = 0;
 for(int i =1;i<=n;i++)
 {
   for(int j = 1;j<=m;j++)
   {
     if(a[i][j])
     {
       ans++;
     }
   }
 }

 cout<<ans;


  return 0;
}
