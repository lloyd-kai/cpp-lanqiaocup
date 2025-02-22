//��Ŀ���ӣ� 
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
}//�õ���1Ϊ���ڵ��¸��ڵ�����,�Լ��丸�ӹ�ϵ
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
  ll n,k,c; cin>>n>>k>>c;//���Ľ������ÿ���ߵļ�ֵ������һ�εĴ���
  for(int i=1;i<=n;i++)
  {
    dep1[i]=depU[i]=0;//���i��1 U�����
    g[i].clear();
  }
  for(int i=1;i<=n-1;i++)
  {
    int u,v; cin>>u>>v;
    g[u].push_back(v),g[v].push_back(u);//��ͼ
  }
  dep1[0]=-1;
  dfs(1,0,dep1,fa1);
  int U=0,V=0;
  for(int i=1;i<=n;i++) if(dep1[i]>dep1[U])  U=i;//�ҵ�������ĵ�
  depU[0]=-1;
  dfs(U,0,depU,faU);
  for(int i=1;i<=n;i++) if(depU[i]>depU[V]) V=i;//�ҵ�������ֱ������һ���˵�
  if(k<=c)  cout<<k*dep1[U]<<'\n';
  else
  {
    vis.reset();
    int x=U,y=V;//�������ص�LCA,��������ֱ��������Щ��
    while(dep1[x]>dep1[y]) vis[x]=true,x=fa1[x];//dep1[x]=dep1[y]
    while(x!=y)
    {
      vis[x]=true,x=fa1[x];
      vis[y]=true,y=fa1[y];
    }//x==y����
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
