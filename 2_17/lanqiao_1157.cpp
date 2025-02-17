//ÌâÄ¿Á´½Ó£ºhttps://www.lanqiao.cn/problems/1157/learning/?page=1&first_category_id=1&problem_id=1157 
#include <iostream>
using namespace std;
typedef long long ll;
const ll p = 1e9+7;
ll qmi(ll a,ll b)
{
  ll res = 1;
  while(b)
  {
    if(b &1)
    {
      res = res*a%p;
    }
    a = a * a % p;
    b>>=1;
  }
  return res;
}

ll inv(ll x)
{
  return qmi(x,p-2);
}

int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int num;
  cin>>num;
  while(num--)
  {
    ll n;
    cin>>n;
    cout<<inv(n)<<'\n';
  }
  return 0;
}
