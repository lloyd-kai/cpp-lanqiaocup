//ÌâÄ¿Á´½Ó£ºhttps://www.lanqiao.cn/problems/152/learning/?page=1&first_category_id=1&second_category_id=3&problem_id=152
#pragma once
#include <bits/stdc++.h>
using namespace std;
int a,b,c;

bool f(int x)
{
  if(x%a !=0 && x%b!=0 && x%c!=0)
  {
    return true;
  }
  return false;
}


int main()
{
  int n;
  cin>>n>>a>>b>>c;
  int ret = 0;
  for(int i = 1;i<=n;i++)
  {
    if(f(i))
    {
      ret+=1;
    }
  }
  cout<<ret;

  return 0;
}
