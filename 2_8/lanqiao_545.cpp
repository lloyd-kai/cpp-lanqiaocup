//��Ŀ���ӣ�https://www.lanqiao.cn/problems/545/learning/?page=1&first_category_id=1&problem_id=545 
#include <bits/stdc++.h>
using namespace std;
//˼·�ܼ򵥣�����ÿ�κϲ���С����������
//����ʹ�����ȼ�����ʵ�֣���Ȼ��ջ���������α���Ҳ�ǿ��Ե�,����Ҫ������
typedef long long ll;

priority_queue<ll,vector<ll>,greater<ll>> pq;


int main()
{
  int n;
  cin>>n;
  //��ʼ�����ȼ�����
  for(int i = 1;i<=n;i++)
  {
    ll x;
    cin>>x;
    pq.push(x);
  }

  //��ʼ�ϲ�
  ll ans = 0;
  while(pq.size()>1)
  {
    //ÿ��ȡ����С����������Ȼ��ϲ���Ż�
    ll x = pq.top();
    pq.pop();
    ll y = pq.top();
    pq.pop();
    ans+=x+y;
    pq.push(x+y);
  }
  cout<<ans;

  return 0;
}
