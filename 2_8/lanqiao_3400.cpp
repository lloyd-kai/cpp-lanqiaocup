//��Ŀ���ӣ�https://www.lanqiao.cn/problems/3400/learning/?page=1&first_category_id=1&problem_id=3400
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+9;
ll a[N],cnt[N],prexor[N];

int main()
{
  int n;
  cin>>n;

  //��ʼ������
  for(int i = 1;i<=n;i++)
  {
    cin>>a[i];
  }
  //��ʼ��ǰ׺�������
  for(int i = 1;i<=n;i++)
  {
    prexor[i] = prexor[i-1]^a[i];
  }
  //��¼ÿ��ǰ׺���ͳ��ֵĴ���
  cnt[0] = 1;
  //���п��ܵ����������
  ll ans = n*(n+1)/2;
  for(int i = 1;i<=n;i++)
  {
    for(ll j = 0;j<=200;j++)
    {
      ll sq = j*j;//��ȫƽ����
      ans -=cnt[sq^prexor[i]];//�����򷴣���ȥ��ȫƽ������ʣ�µľ���Ҫ���
    }
    cnt[prexor[i]]++;
  }
  cout<<ans;
  return 0;
}
