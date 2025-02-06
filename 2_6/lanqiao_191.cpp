//题目链接 https://www.lanqiao.cn/problems/191/learning/?page=1&first_category_id=1&problem_id=191
#pragma once
#include <bits/stdc++.h>
using namespace std;


//判断此数是否符合条件
bool fun(int x)
{
  while(x)
  {
    int y = x%10;
    if(y == 2 || y == 1 || y == 9 || y == 0)
    {
      return true;
    }
    x/=10;
  }
  return false;
}


int main()
{
  int n;
  cin>>n;
  int ans = 0;
  for(int i = 1;i<=n;i++)
  {
    if(fun(i))
    {
      ans+=i;
    }
  }
  cout<<ans<<'\n';

  return 0;
}
