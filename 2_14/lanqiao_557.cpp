//题目链接：https://www.lanqiao.cn/problems/557/learning/?page=1&first_category_id=1&second_category_id=6&problem_id=557 
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 107;

int main()
{
  int n;
  int v[MAXN*2],f[MAXN*2][MAXN*2];
  memset(f,0,sizeof(f));//将f初始化为0
  cin>>n;
  for(int i = 1;i<=n;i++)
  {
    cin>>v[i];
    v[i+n] = v[i];//复制区间
  }
  for(int len = 2;len<=n;len++)
  {
    for(int i = 1;i+len-1<=n*2;i++)
    {
      int j = i+len-1;
      for(int k = i;k<j;k++)
      {
        f[i][j] = max(f[i][j],f[i][k]+f[k+1][j]+v[i]*v[k+1]*v[j+1]);
      }
    }
  }
  int ans = 0;
  for(int i = 1;i<=n;i++)
  {
    ans = max(ans,f[i][i+n-1]);//找最优答案
  }
  cout<<ans;
  return 0;
}
