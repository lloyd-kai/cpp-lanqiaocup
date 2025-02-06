//��Ŀ���ӣ�https://www.lanqiao.cn/problems/549/learning/?page=1&first_category_id=1&problem_id=549
#pragma once
#include <iostream>
using namespace std;
const int N = 150;
int mp[N][N],ans[N][N];



int main()
{
  int n,m;
  cin>>n>>m;

  //��ʼ����������
  for(int i = 1;i<=n;i++)
  {
    for(int j = 1;j<=m;j++)
    {
      cin>>mp[i][j];
    }
  }

  //��ʼ��̽������
  for(int i = 1;i<=n;i++)
  {
    for(int j = 1;j<=m;j++)
    {
      if(mp[i][j] == 1)
      {
        ans[i][j] = 9;
        continue;
      }

      //ɨ����Χ����
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

  //��ӡ̽������
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
