//��Ŀ���ӣ�https://www.lanqiao.cn/problems/1469/learning/?page=1&first_category_id=1&name=%E5%A7%8B%E7%A5%96%E9%B8%9F 
/*
����൱��һ�������飬ÿ����xi=1����ȥ���Σ�xi=0����ȥ���� ���������ѵ������Ľ����1��ż�������Ľ����0
*/
#include<bits/stdc++.h>
using namespace std;           
const int N=2e3+5;
bitset<N>a[N];
int n;
void gauss()
{
  int r=1;
  for(int i=1;i<=n;i++)      //����
  {
    int maxx=r;
    for(int j=r+1;j<=n;j++)
    {
      if(a[j][i])
      {
        maxx=j;
        break;
      }
    }
    if(a[maxx][i]==0)
    continue;
    swap(a[maxx],a[r]);
    
    for(int j=1;j<=n;j++)
    {
      if(a[j][i]&&i!=j)
      {
          a[j]=a[j]^a[r];
        
      }
    }
    r++;
  }
  for(int i=r;i<=n;i++)
  {
    if(a[i][n+1])
    {
      cout<<"Impossible"<<'\n';
      return ;
    }
  }
}
int main()
{
   cin>>n;
  for(int i=1;i<=n;i++)
  {
    int m;cin>>m;
    if(m&1)     //��ǰ�������������ѵ����
    a[i][n+1]=1,a[i][i]=1;
    //ż�����������ֻ��ȥ�����ζ���
    while(m--)
    {
       int x;cin>>x;
       a[i][x]=1;
    }
  }
  gauss();
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    if(a[i][n+1])
    ans++;
  }
  cout<<ans<<'\n';
  for(int i=1;i<=n;i++)
  {
    if(a[i][n+1])
    cout<<i<<" ";
  }
  return 0;
}
