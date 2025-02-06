//题目链接：https://www.lanqiao.cn/problems/549/learning/?page=1&first_category_id=1&problem_id=549
#pragma once
#include <iostream>
using namespace std;
const int N = 150;
int mp[N][N],ans[N][N];



int main()
{
  int n,m;
  cin>>n>>m;

  //初始化地雷数组
  for(int i = 1;i<=n;i++)
  {
    for(int j = 1;j<=m;j++)
    {
      cin>>mp[i][j];
    }
  }

  //初始化探雷数组
  for(int i = 1;i<=n;i++)
  {
    for(int j = 1;j<=m;j++)
    {
      if(mp[i][j] == 1)
      {
        ans[i][j] = 9;
        continue;
      }

      //扫描周围区域
      for(int x = max(1,i-1);x<=min(n,i+1);x++)
      {
        for(int y = max(1,j-1);y<=min(m,j+1);y++)
        {
          if(mp[x][y])
          {
            ans[i][j]++;
          }
        }
      }
    }
  }

  //打印探测数组
  for(int i = 1;i<=n;i++)
  {
    for(int j = 1;j<=m;j++)
    {
      cout<<ans[i][j]<<" ";
    }
    cout<<'\n';
  }


  return 0;
}
