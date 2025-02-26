//ÌâÄ¿Á´½Ó£ºhttps://www.lanqiao.cn/problems/1121/learning/?page=1&first_category_id=1&problem_id=1121
#include <iostream>
using namespace std;
using ll = long long;
const int N = 405;
const ll inf = 2e18;
ll dp[N][N];

int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n,m,q;
  cin>>n>>m>>q;
  for(int i = 1;i<=n;i++)
  {
    for(int j = 1;j<=n;j++)
    {
      dp[i][j] = inf;
    }
  }
  for(int i = 1;i<=n;i++)
  {
    dp[i][i] = 0;
  }
  while(m--)
  {
    ll u,v,w;
    cin>>u>>v>>w;
    dp[u][v] = min(dp[u][v],w);
    dp[v][u] = min(dp[v][u],w);
  }
  for(int k = 1;k<=n;k++)
  {
    for(int i = 1;i<=n;i++)
    {
      for(int j = 1;j<=n;j++)
      {
        dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
      }
    }
  }
  while(q--)
  {
    int st,ed;
    cin>>st>>ed;
    cout<<(dp[st][ed]>=inf?-1:dp[st][ed])<<'\n';
  }
  return 0;
}
