//例题链接https://www.lanqiao.cn/problems/1230/learning/?page=1&first_category_id=1&problem_id=1230
#pragma once

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 10000;
int a[N];


void solve()
{
  int n,m;
  cin>>n>>m;
  string s;
  cin>>s;
  for(int i = 0;i<s.length();i++)
  {
    if('0'<=s[i] && s[i]<='9')
    {
      a[i+1] = s[i]-'0';
    }
    else
    {
      a[i+1] = s[i]-'A'+10;
    }
  }

  //N进制转化为十进制
  ll x = 0;
  for(int i = 1;i<=s.length();i++)
  {
    x = x*n+a[i];
  }

  //十进制转化为M进制
  string ans;
  while(x)
  {
    if(x%m<=9)
    {
      ans+=to_string(x%m);
      x/=m;
    }
    else{
      ans+=char(x%m-10+'A');
      x/=m;
    }
  }

  reverse(ans.begin(),ans.end());
  cout<<ans<<endl;
}


int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }

  return 0;
}
