//题目链接：https://www.lanqiao.cn/problems/4385/learning/?page=1&first_category_id=1&problem_id=4385 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int dep[N],fa[N][24];
vector<int>g[N];

//当前节点为x,父亲为p
void dfs(int x,int p)
{
    dep[x] = dep[p]+1;//更新dep
    fa[x][0] = p;
    for(int i = 1;i<=20;i++)//循环更新fa
    {
        fa[x][i] = fa[fa[x][i-1]][i-1];
    }
    //向下搜索
    for(const auto &y:g[x])
    {
        //如果y是父亲就跳过
        if(y == p)
        {
            continue;
        }
        dfs(y,x);
    }
}

int lca(int x,int y)
{
    //如果x深度比y小，就交换x,y，使得x深度更深
    if(dep[x]<dep[y])
    {
        swap(x,y);
    }
    //贪心的思想，i从大到小
    //x向上跳的过程中,保持dep[x]>=dep[y]，深度不能超过y
    for(int i = 20;i>=0;i--)
    {
        if(dep[fa[x][i]]>=dep[y])
        {
            x = fa[x][i];
        }
    }
    if(x == y)
    {
        return x;
    }
    //跳跃过程中，保持x!=y
    for(int i = 20;i>=0;i--)
    {
        if(fa[x][i]!=fa[y][i])
        {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

int main()
{
  int n;
  cin>>n;
  for(int i = 1;i<n;i++)
  {
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1,0);
  int m;
  cin>>m;
  while(m--)
  {
    int x,y;
    cin>>x>>y;
    cout<<lca(x,y)<<'\n';
  }
  return 0;
}
