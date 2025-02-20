//题目链接：https://www.lanqiao.cn/problems/3347/learning/?page=1&first_category_id=1&problem_id=3347 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+9;
const int P = 1e9+7;
ll fac[N];

ll qmi(ll a,ll b)
{
  ll res = 1;
  while(b)
  {
    if(b&1)
    {
      res = res*a%P;
    }
    a = a*a%P;
    b>>=1;
  }
  return res;
}

ll inv(ll x)
{
  return qmi(x,P-2);
}

//组合数的计算
ll C(ll n,ll m)
{
  ll res = 1;
  for(int i = n;i>=n-m+1;i--)
  {
    res = res*i%P;
  }
  for(int i = 1;i<=m;i++)
  {
    res = res * inv(i)%P;
  }
  return res;
}

ll mo(ll x)
{
  return (x%P+P)%P;
}

int main()
{
  int n,a,b;
  cin>>n>>a>>b;

  //正难则反
  ll ans = mo(mo(qmi(2,n)-1-C(n,a))-C(n,b));
  cout<<ans<<endl;
  return 0;
}
