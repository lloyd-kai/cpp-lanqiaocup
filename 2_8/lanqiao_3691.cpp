//��Ŀ���ӣ�https://www.lanqiao.cn/problems/3691/learning/?page=1&first_category_id=1&problem_id=3691 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int a[N],prefix[35][N];

int main()
{
  int m,q;
  cin>>m>>q;

  //��ʼ������
  for(int i = 1;i<=m;i++)
  {
    cin>>a[i];
  }

  //��ʼ��ǰ׺������
  //�����������31������(32λ-����λ)��ÿһλͳ��1�ĸ���
  for(int i = 0;i<=30;i++)
  {
    for(int j = 1;j<=m;j++)
    {
      //ȡ��ĳһλ����Ȼ����Ϊǰ׺�͵�ֵ
      prefix[i][j] = prefix[i][j-1]+(a[j]>>i&1);
    }
  }

  while(q--)
  {
    int l,r;
    cin>>l>>r;
    int ans = 0;
    for(int i = 0;i<30;i++)
    {
      //ֻҪ��1����1��ȫ0����0
      ans+=(1<<i)*(prefix[i][r]-prefix[i][l-1]?1:0);
    }
    cout<<ans<<'\n';
  }
  
  return 0;
}
