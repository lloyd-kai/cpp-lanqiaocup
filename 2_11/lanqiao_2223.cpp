//��Ŀ���ӣ�https://www.lanqiao.cn/problems/2223/learning/?page=1&first_category_id=1&problem_id=2223 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+9;
ll dp[N][2];

int main()
{
  int n,m,k;
  cin>>n>>m>>k;

  for(int i = 1;i<=n;i++)
  {
    ll w,v;
    cin>>w>>v;
    for(int j = m;j>=0;j--)
    {
      if(j>=w)
      {
        dp[j][0] = max(dp[j][0],dp[j-w][0]+v);
        dp[j][1] = max(dp[j][1],dp[j-w][1]+v);
      }
      if(j>=w+k)
      {
        dp[j][1] = max(dp[j][1],dp[j-w-k][0]+2*v);
      }
    }
  }
  cout<<max(dp[m][0],dp[m][1])<<"\n";
  return 0;
}
