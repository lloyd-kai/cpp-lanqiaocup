//��Ŀ���ӣ�https://www.lanqiao.cn/problems/1621/learning/?page=1&first_category_id=1&problem_id=1621 
#include <bits/stdc++.h>
using namespace std;
const int N = 2009;
int a[N];


int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n,m,k;
  cin>>n>>m>>k;

  //��ʼ������
  for(int i = 1;i<=n;i++)
  {
    cin>>a[i];
  }

  int ans = 0;
  //����cnt��¼����mֵ�ĸ���
  for(int i = 1,j=0,cnt = 0;i <=n;i++)
  {
    //���ƶ���ָ��ʹ������ĳ��ȳ���k
    while(i > j || (j+1<=n && cnt <k))
    {
      cnt+=(a[++j]>=m);
    }
    //��¼������������ĸ���
    if(cnt>=k)
    {
      ans+=n-j+1;
    }
    cnt-=(a[i]>=m);
  }
  cout<<ans;

  return 0;
}
