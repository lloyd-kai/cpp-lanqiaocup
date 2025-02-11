//��Ŀ���ӣ�https://www.lanqiao.cn/problems/1174/learning/?page=1&first_category_id=1&problem_id=1174 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105,M = 1010;
ll dp[N][M];

int main()
{
  int n,V;
  cin>>n>>V;
  for(int i = 1;i<=n;i++)
  {
    ll w,v;
    cin>>w>>v;
    for(int j = 0;j<=V;j++)
    {
      if(j>=w)
      {
        dp[i][j] = max(dp[i-1][j],dp[i-1][j-w]+v);
      }
      else
      {
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  cout<<dp[n][V]<<"\n";
  
  return 0;
}
