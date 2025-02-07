#ÌâÄ¿Á´½Ó£ºhttps://www.lanqiao.cn/problems/1371/learning/?page=1&first_category_id=1&problem_id=1371 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
char s[N];

int main()
{
  cin>>s;
  int l = 0,r = strlen(s);
  while(l<=r)
  {
    if(s[l] != s[r])
    {
      cout<<"N";
      return 0;
    }
    l++;
    r--;
  }
  cout<<"Y";
  
  
  return 0;
}
