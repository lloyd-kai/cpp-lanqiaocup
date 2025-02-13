//ÌâÄ¿Á´½Ó£ºhttps://www.lanqiao.cn/problems/1175/learning/?page=1&first_category_id=1&problem_id=1175
#include <iostream>
using namespace std;
const int N = 1e3+9;
int dp[N];

int main()
{
  int n,m;
  cin>>n>>m;
  for(int t = 1;t<=n;t++)
  {
    int w,v;
    cin>>w>>v;
    for(int i = w;i<=m;i++)
    {
      dp[i] = max(dp[i],dp[i-w]+v);
    }
  }
  cout<<dp[m];
  return 0;
}
