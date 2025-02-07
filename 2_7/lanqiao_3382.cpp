//��Ŀ���ӣ�https://www.lanqiao.cn/problems/3382/learning/?page=1&first_category_id=1&problem_id=3382
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p = 1e9+7;
const int N  =1e5+9;
//�����ö�ά����洢ֵ,��һ��ά�ȴ����n�η����ڶ���ά�ȴ����Ӧ�����η�֮���ֵ
//����kС��5�������ö�ֵ���
ll a[6][N],prefix[6][N];


int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int n,m;
  cin>>n>>m;

  //��ʼ��һ�η�������
  for(int i = 1;i<=n;i++)
  {
    cin>>a[1][i];
  }

  //��ʼ�������η�������
  for(int i = 2;i<=5;i++)
  {
    for(int j = 1;j<=m;j++)
    {
      //n�η�=n-1�η�*1�η�
      a[i][j] = a[i-1][j]*a[1][j]%p;
    }
  }

  //��ʼ��ǰ׺������
  for(int i = 1;i<=5;i++)
  {
    for(int j = 1;j<=m;j++)
    {
      prefix[i][j] = (prefix[i][j-1]+a[i][j])%p;
    }
  }

  //������ĺ�
  while(m--)
  {
    int l,r,k;
    cin>>l>>r>>k;

    //ע������������������Ǹ����Ļ�Ҫ+ģ��
    cout<<(prefix[k][r]-prefix[k][l-1]+p)%p<<'\n';
  }

  return 0;
}
