//题目链接：https://www.lanqiao.cn/problems/4059/learning/?page=1&first_category_id=1&problem_id=4059 
#include <bits/stdc++.h>
using namespace std;
//使用二进制优化后的多重背包算法
typedef long long ll;
const int N = 1e3+7,M = 2e4+7;
ll dp[M];

int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n,m;
  cin>>n>>m;
  for(int i = 1;i<=n;i++)
  {
    ll v,w,s;
    cin>>v>>w>>s;
    for(int k = 1;k<=s;s-=k,k+=k)
    {
      for(int j = m;j>=k*v;j--)
      {
        dp[j] = max(dp[j],dp[j-k*v]+k*w);
      }
    }
    for(int j = m;j>=s*v;j--)
    {
      dp[j] = max(dp[j],dp[j-s*v]+s*w);
    }
  }
  cout<<dp[m]<<'\n';
  return 0;
}
