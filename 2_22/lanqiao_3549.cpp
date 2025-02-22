#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int wei[N],wi[N];
vector<vector<int>> a(N);
int cnt = 0;//计数用
int in[N],out[N];

//dfs函数，注意搜索的时候同时用dfs序
void dfs(int x,int p)
{
  in[x] = ++cnt;
  wi[in[x]] = wei[x];
  for(const auto &y:a[x])
  {
    if(y == p)
    {
      continue;
    }
    dfs(y,x);
  }
  out[x] = cnt;
}

int main()
{
  int n,m;
  cin>>n>>m;
  for(int i = 1;i<=n;i++)
  {
    cin>>wei[i];//表示第i个数的权值
  }
  for(int i = 1;i<n;i++)
  {
    int u,v;
    cin>>u>>v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  dfs(1,0);
  while(m--)
  {
    int c;
    cin>>c;
    if(c == 1)
    {
      int x,w;
      cin>>x>>w;
      wi[in[x]] = w;
    }
    else
    {
      int x;
      cin>>x;
      int ans = 0;
      for(int i = in[x];i<=out[x];i++)
      {
        ans = ans^wi[i];//求异或和
      }
      cout<<ans<<'\n';
    }
  }
  return 0;
}
