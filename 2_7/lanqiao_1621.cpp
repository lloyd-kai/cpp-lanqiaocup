//题目链接：https://www.lanqiao.cn/problems/1621/learning/?page=1&first_category_id=1&problem_id=1621 
#include <bits/stdc++.h>
using namespace std;
const int N = 2009;
int a[N];


int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n,m,k;
  cin>>n>>m>>k;

  //初始化数组
  for(int i = 1;i<=n;i++)
  {
    cin>>a[i];
  }

  int ans = 0;
  //这里cnt记录超过m值的个数
  for(int i = 1,j=0,cnt = 0;i <=n;i++)
  {
    //先移动右指针使得区间的长度超过k
    while(i > j || (j+1<=n && cnt <k))
    {
      cnt+=(a[++j]>=m);
    }
    //记录符合条件区间的个数
    if(cnt>=k)
    {
      ans+=n-j+1;
    }
    cnt-=(a[i]>=m);
  }
  cout<<ans;

  return 0;
}
