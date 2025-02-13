//ÌâÄ¿Á´½Ó£ºhttps://www.lanqiao.cn/problems/3937/learning/?page=1&first_category_id=1&problem_id=3937
#include <bits/stdc++.h>
using namespace std;
const int N = 105;
typedef long long ll;
ll dp[N][N];

int main()
{
  int n,V,M;
  cin>>n>>V>>M;
  for(int i = 1;i<=n;i++)
  {
    int v,m,w;
    cin>>v>>m>>w;
    for(int j = V;j>=v;j--)
    {
      for(int k = M;k>=m;k--)
      {
        dp[j][k] = max(dp[j][k],dp[j-v][k-m]+w);
      }
    }
  }
  cout<<dp[V][M]<<endl;
  
  return 0;
}
