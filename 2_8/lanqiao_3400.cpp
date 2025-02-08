//题目链接：https://www.lanqiao.cn/problems/3400/learning/?page=1&first_category_id=1&problem_id=3400
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+9;
ll a[N],cnt[N],prexor[N];

int main()
{
  int n;
  cin>>n;

  //初始化数组
  for(int i = 1;i<=n;i++)
  {
    cin>>a[i];
  }
  //初始化前缀异或数组
  for(int i = 1;i<=n;i++)
  {
    prexor[i] = prexor[i-1]^a[i];
  }
  //记录每个前缀异或和出现的次数
  cnt[0] = 1;
  //所有可能的数组的数量
  ll ans = n*(n+1)/2;
  for(int i = 1;i<=n;i++)
  {
    for(ll j = 0;j<=200;j++)
    {
      ll sq = j*j;//完全平方数
      ans -=cnt[sq^prexor[i]];//正难则反，减去完全平方数，剩下的就是要求的
    }
    cnt[prexor[i]]++;
  }
  cout<<ans;
  return 0;
}
