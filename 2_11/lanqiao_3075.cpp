//题目链接：https://www.lanqiao.cn/problems/3075/learning/?page=1&first_category_id=1&problem_id=3075
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+9;

//这里的cnt数组存放合法的三角形个数，用前缀和找到对应区间合法的三角形次数
int n,cnt[N],prefix[N];

//mul是边乘积，sum是除去最后一条边之和
void dfs(int dep,int st,int mul,int sum)
{
  //剪枝
  if(mul >1e5)
  {
    return;
  }

  if(dep == n+1)
  {
    cnt[mul]++;
    return;
  }

  //计算边的上限
  int up = pow(1e5/mul,1.0/(n+1-dep))+3;

  //枚举所有的边
  for(int i = st+1;i<(dep == n?min(sum,up):up);i++)
  {
    dfs(dep+1,i,mul*i,sum+i);
  }
}


int main()
{
  int q;
  cin>>q>>n;
  dfs(1,0,1,0);
  for(int i = 1;i<=1e5;i++)
  {
    prefix[i] = prefix[i-1]+cnt[i];
  }

  
  while(q--)
  {
    int l,r;
    cin>>l>>r;
    cout<<prefix[r]-prefix[l-1]<<"\n";
  }
  return 0;
}
