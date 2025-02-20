//ÌâÄ¿Á´½Ó£ºhttps://www.lanqiao.cn/problems/3197/learning/?page=1&first_category_id=1&problem_id=3197 
#include <iostream>
using namespace std;
using ll = long long;
const ll p = 1e9+7;

ll qmi(ll a,ll b)
{
  ll res = 1;
  while(b)
  {
    if(b&1)
    {
      res = res*a%p;
    }
    a = a*a%p;
    b>>=1;
  }
  return res;
}

int main()
{
  int n,m;
  cin>>n>>m;
  cout<<(6*(qmi(2,n)+qmi(2,m))-24+p)%p<<endl;
  
  return 0;
}
