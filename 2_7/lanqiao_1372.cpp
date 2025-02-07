//��Ŀ���ӣ�https://www.lanqiao.cn/problems/1372/learning/?page=1&first_category_id=1&problem_id=1372 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int a[N];


int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int n,S;
  cin>>n>>S;
  //��ʼ������
  for(int i = 1;i<=n;i++)
  {
    cin>>a[i];
  }

  int ans = n+1;
  for(int i = 1,j = 0,sum = 0;i<=n;i++)
  {
    //�ںͲ�����������ƶ�j
    while(i>j || (j+1<=n && sum<S))
    {
      sum +=a[++j];
    }

    //�жϺ��Ƿ����S
    if(sum>=S)
    {
      ans = min(ans,j-i+1);
    }
    //�ںͳ���S��������ƶ�i
    sum-=a[i];
  }
  cout<<(ans>n?0:ans)<<'\n';

  return 0;
}
