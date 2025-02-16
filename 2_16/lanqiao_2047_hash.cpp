//题目链接：https://www.lanqiao.cn/problems/2047/learning/?page=1&first_category_id=1&tag_relation=intersection&problem_id=2047 
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+9;
char s[N],p[N];
int nex[N];
typedef unsigned long long ull;
const ull base = 131;//base一般为质数，减少hash冲突的概率
ull h1[N],h2[N],b[N];//h[i]表示s[1-i]的hash前缀和

ull getHash(ull h[],int l,int r)
{
  return h[r]-h[l-1]*b[r-l+1];
}

int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>p;
  int m = strlen(p+1);
  cin>>s;
  int n = strlen(s+1);
  b[0] = 1;
  for(int i = 1;i<=n;i++)
  {
    b[i] = b[i-1]*base;
    h1[i] = h1[i-1]*base+(int)p[i];
    h2[i] = h2[i-1]*base+(int)s[i];
  }

  int ans = 0;
  for(int i = 1;i+m-1<=n;i++)
  {
    if(getHash(h1,1,m) == getHash(h2,i,i+m-1))
    {
      ans++;
    }
  }
  cout<<ans;

  return 0;
}
