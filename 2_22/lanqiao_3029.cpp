//题目链接： 
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+10;
ll dep1[N],depU[N],fa1[N],faU[N];
vector<int> g[N];
bitset<N> vis;
void dfs(int x,int p,ll dep[],ll fa[])
{
    dep[x]=dep[p]+1;
    fa[x]=p;
    for(const auto &y:g[x])
    {
      if(y==p)  continue;
      dfs(y,x,dep,fa);
    }
}//得到以1为根节点下各节点的深度,以及其父子关系
int dfs2(int x,int p)
{
  if(vis[x]) return 0; 
  int res=dep1[x];
  for(const auto &y:g[x])
  {
    if(y==p) continue;
    res=max(res,dfs2(y,x));
  }
  return res;
}
void solve()
{
  ll n,k,c; cin>>n>>k>>c;//树的结点数，每条边的价值，操作一次的代价
  for(int i=1;i<=n;i++)
  {
    dep1[i]=depU[i]=0;//结点i到1 U的深度
    g[i].clear();
  }
  for(int i=1;i<=n-1;i++)
  {
    int u,v; cin>>u>>v;
    g[u].push_back(v),g[v].push_back(u);//建图
  }
  dep1[0]=-1;
  dfs(1,0,dep1,fa1);
  int U=0,V=0;
  for(int i=1;i<=n;i++) if(dep1[i]>dep1[U])  U=i;//找到深度最大的点
  depU[0]=-1;
  dfs(U,0,depU,faU);
  for(int i=1;i<=n;i++) if(depU[i]>depU[V]) V=i;//找到了树的直径的另一个端点
  if(k<=c)  cout<<k*dep1[U]<<'\n';
  else
  {
    vis.reset();
    int x=U,y=V;//进行朴素的LCA,记忆树的直径上有哪些点
    while(dep1[x]>dep1[y]) vis[x]=true,x=fa1[x];//dep1[x]=dep1[y]
    while(x!=y)
    {
      vis[x]=true,x=fa1[x];
      vis[y]=true,y=fa1[y];
    }//x==y跳出
    vis[x]=true;
    int maxdep=dfs2(1,0);
    ll ans=max(dep1[U]*k+maxdep*(k-1),depU[V]*k-dep1[V]*c);
    cout<<ans<<'\n';
  }

}
int main()
{
  int t;cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}
