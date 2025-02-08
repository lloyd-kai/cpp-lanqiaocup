//题目链接：https://www.lanqiao.cn/problems/3691/learning/?page=1&first_category_id=1&problem_id=3691 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int a[N],prefix[35][N];

int main()
{
  int m,q;
  cin>>m>>q;

  //初始化数组
  for(int i = 1;i<=m;i++)
  {
    cin>>a[i];
  }

  //初始化前缀和数组
  //将结果看作是31个部分(32位-符号位)，每一位统计1的个数
  for(int i = 0;i<=30;i++)
  {
    for(int j = 1;j<=m;j++)
    {
      //取出某一位的数然后作为前缀和的值
      prefix[i][j] = prefix[i][j-1]+(a[j]>>i&1);
    }
  }

  while(q--)
  {
    int l,r;
    cin>>l>>r;
    int ans = 0;
    for(int i = 0;i<30;i++)
    {
      //只要有1就是1，全0才是0
      ans+=(1<<i)*(prefix[i][r]-prefix[i][l-1]?1:0);
    }
    cout<<ans<<'\n';
  }
  
  return 0;
}
