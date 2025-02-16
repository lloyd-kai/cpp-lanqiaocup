//题目链接：https://www.lanqiao.cn/problems/2047/learning/?page=1&first_category_id=1&tag_relation=intersection&problem_id=2047 
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+9;
char s[N],p[N];
int nex[N];

int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>p;
  int m = strlen(p+1);
  cin>>s;
  int n = strlen(s+1);

  //获取next数组
  nex[0] = nex[1] = 0;
  for(int i  =2,j=0;i<=m;i++)
  {
    while(j&&p[i]!=p[j+1])
    {
      j=nex[j];
    }
    if(p[i] == p[j+1])
    {
      j++;
    }
    nex[i] = j;
  }
  int ans = 0;
  for(int i = 1,j=0;i<=n;i++)
  {
    while(j && s[i]!=p[j+1])
    {
      j = nex[j];
    }
    if(s[i] == p[j+1])
    {
      j++;
    }
    if(j == m)
    {
      ans++;
    }
  }
  cout<<ans;

  return 0;
}
