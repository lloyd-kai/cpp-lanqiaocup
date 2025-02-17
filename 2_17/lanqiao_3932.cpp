//��Ŀ���ӣ�https://www.lanqiao.cn/problems/3932/learning/?page=1&first_category_id=1&problem_id=3932
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
  ll n,k;
  cin>>n>>k;
  //�������ֱ�����
  if(k == 0)
  {
    cout<<1<<"\n";
    for(int i = 2;i<=n;i++)
    {
      cout<<0<<"\n";
    }
  }
  //����������λغ�
  else if(k & 1)
  {
    ll ans = inv(n/2);
    for(int i = 1;i<=n;i++)
    {
      //������ֺͻغϵ���ż����ͬ
      if(i&1)
      {
        cout<<0<<'\n';
      }
      else
      {
        cout<<ans<<'\n';
      }
    }
  }
  //���ż���λغ�
  else
  {
    ll ans = inv((n+1)/2);
    for(int i = 1;i<=n;i++)
    {
      if(i&1)
      {
        cout<<ans<<'\n';
      }
      else
      {
        cout<<0<<'\n';
      }
    }
  }

  return 0;
}
