//ÌâÄ¿Á´½Ó£ºhttps://www.lanqiao.cn/problems/3404/learning/?page=1&first_category_id=1&problem_id=3404 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
ll rnk(ll mid)
{
  ll res = 0;
  for(int i = 1;i<=n;i++)
  {
    res+=min(m,mid/i);
  }
  return res;
}


int main()
{
  cin>>n>>m>>k;
  ll l = 0,r = 1e14;
  while(l+1!=r)
  {
    ll mid = (l+r)>>1;
    if(rnk(mid)>=k)
    {
      r = mid;
    }
    else
    {
      l = mid;
    }
  }
  cout<<r<<'\n';
  return 0;
}
