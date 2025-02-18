//ÌâÄ¿Á´½Ó£ºhttps://www.lanqiao.cn/problems/1260/learning/?page=1&first_category_id=1&problem_id=1260 
#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
  return b == 0?a:gcd(b,a%b);
}

int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<"\n";
  }
  return 0;
}
