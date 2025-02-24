//题目链接:https://www.lanqiao.cn/problems/3620/learning/?page=1&first_category_id=1&problem_id=3620
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+9;
ll a[N],t[N],n,m;

//lowbit函数
int lowbit(int x)
{
  return x & -x;
}

//魅力值变化函数 
void update(int k,ll x)
{
  a[k] += x;
  for(int i = k;i<=n;i+=lowbit(i))
  {
     t[i]+=x;
  }
}

//返回区间[1,k]的和
int getprefix(int k)
{
    int res = 0;
    for(int i = k;i>0;i-=lowbit(i))
    {
        res+=t[i];
    }
    return res;
}

//获取区间和
ll getsum(int l,int r)
{
  return getprefix(r)-getprefix(l-1);
}

ll b(int i)
{
  return (2*i-n-1)*a[i] -getsum(1,i-1)+getsum(i+1,n);
}


int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>n>>m;
  for(int i = 1;i<=n;i++)
  {
    int x;
    cin>>x;
    update(i,x);
  }

  while(m--)
  {
    int op;
    cin>>op;
    if(op == 1)
    {
      ll x,y;
      cin>>x>>y;
      update(x,-a[x]+y);
    }
    else
    {
      int x;
      cin>>x;
      cout<<b(x)<<endl;
    }
  }
  return 0;
} 
