//ÌâÄ¿Á´½Ó£ºhttps://www.lanqiao.cn/problems/1176/learning/?page=1&first_category_id=1&problem_id=1176  
#include <iostream>
using namespace std;
const int N = 205;
int dp[N];

int main()
{
  int n,m;
  cin>>n>>m;
  for(int i = 1;i<=n;i++)
  {
    int w,v,s;
    cin>>w>>v>>s;
    while(s--)
    {
      for(int j = m;j>=w;j--)
      {
        dp[j] = max(dp[j],dp[j-w]+v);
      }
    }
  }
  cout<<dp[m]<<"\n";

  return 0;
}
