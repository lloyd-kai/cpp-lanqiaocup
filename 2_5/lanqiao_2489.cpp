//例题链接 https://www.lanqiao.cn/problems/2489/learning/?page=1&first_category_id=1&problem_id=2489
#pragma once 

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 50;
int a[N];


int main()
{
  string s = "2021ABCD";
  for(int i = 0;i<s.length();i++)
  {
    if('0'<=s[i] && s[i]<='9')
    {
      a[i+1] = s[i]-'0';//字符串转为整数
    }
    else
    {
      a[i+1] = s[i]-'A'+10;
    }
  }
  
  //进制转换
  ll x = 0;
  for(int i = 1;i<=s.length();i++)
  {
    x = x*16+a[i];//进制转换模板
  }
  cout<<x<<'\n';
  return 0;
}
