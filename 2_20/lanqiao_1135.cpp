//题目链接：https://www.lanqiao.cn/problems/1135/learning/?page=1&first_category_id=1&problem_id=1135 
#include <iostream>
using namespace std;

const int N = 2e5+9;
int pre[N];

//路径压缩函数
int root(int x)
{
  return pre[x] = (pre[x] == x?x:root(pre[x]));
}

int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n,m;
  cin>>n>>m;
  for(int i = 1;i<=n;i++)
  {
    pre[i] = i;
  }
  while(m --)
  {
    int op,x,y;
    cin>>op>>x>>y;
    if(op == 1)
    {
      pre[root(x)] = root(y);
    }
    else
    {
      cout<<(root(x) == root(y)?"YES":"NO")<<'\n';
    }
  }
  return 0;
}
