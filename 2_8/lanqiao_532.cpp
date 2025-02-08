// 题目链接：https://www.lanqiao.cn/problems/532/learning/?page=1&first_category_id=1&problem_id=532 
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+9;
int a[N];


int main()
{
  int w,n;
  cin>>w>>n;
  //初始化数组
  for(int i = 1;i<=n;i++)
  {
    cin>>a[i];
  }

  //排序
  sort(a+1,a+n+1);

  //运用双指针实现贪心
  int ans = 0;
  int l = 1,r = n;
  while(l<=r)
  {
    if(a[l]+a[r]>w)
    {
      ans++;
      r--;
    }
    else
    {
      ans++;
      l++;
      r--;
    }
  }

  cout<<ans;
  return 0;
}
