//题目链接：https://www.lanqiao.cn/problems/3382/learning/?page=1&first_category_id=1&problem_id=3382
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p = 1e9+7;
const int N  =1e5+9;
//这里用二维数组存储值,第一个维度代表第n次方，第二个维度代表对应的数次方之后的值
//由于k小于5，所以用定值替代
ll a[6][N],prefix[6][N];


int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int n,m;
  cin>>n>>m;

  //初始化一次方的数组
  for(int i = 1;i<=n;i++)
  {
    cin>>a[1][i];
  }

  //初始化其他次方的数组
  for(int i = 2;i<=5;i++)
  {
    for(int j = 1;j<=m;j++)
    {
      //n次方=n-1次方*1次方
      a[i][j] = a[i-1][j]*a[1][j]%p;
    }
  }

  //初始化前缀和数组
  for(int i = 1;i<=5;i++)
  {
    for(int j = 1;j<=m;j++)
    {
      prefix[i][j] = (prefix[i][j-1]+a[i][j])%p;
    }
  }

  //找区间的和
  while(m--)
  {
    int l,r,k;
    cin>>l>>r>>k;

    //注意如果求出来的区间和是负数的话要+模数
    cout<<(prefix[k][r]-prefix[k][l-1]+p)%p<<'\n';
  }

  return 0;
}
