//ÌâÄ¿Á´½Ó£ºhttps://www.lanqiao.cn/problems/1178/learning/?page=1&first_category_id=1&problem_id=1178 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 150;
ll dp[N][N];

int main()
{
  int n,V;
  cin>>n>>V;

  for(int i = 1;i<=n;i++)
  {
    int s;
    cin>>s;
    for(int j = 0;j<=V;j++)
    {
      dp[i][j] = dp[i-1][j];
    }
    while(s--)
    {
      ll w,v;
      cin>>w>>v;
      for(int j = w;j<=V;j++)
      {
        dp[i][j] = max(dp[i][j],dp[i-1][j-w]+v);
      }
    }
  }
  cout<<dp[n][V]<<'\n';
  return 0;
}
