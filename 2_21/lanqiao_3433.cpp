//ÌâÄ¿Á´½Ó£ºhttps://www.lanqiao.cn/problems/3433/learning/?page=1&first_category_id=1&problem_id=3433
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+9;

priority_queue<ll>pq;


int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int n,q;
  cin>>n>>q;
  ll sum = 0;
  for(int i = 1;i<=n;i++)
  {
    ll x;
    cin>>x;
    sum+=x;
    pq.push(x);
  }

  for(int i = 1;i<=q;i++)
  {
    ll x;
    cin>>x;
    while(pq.top() >=x)
    {
      ll y = pq.top();
      pq.pop();
      sum+=y%x-y;
      pq.push(y%x);
    }
    cout<<sum<<" ";
  }

  return 0;
}
