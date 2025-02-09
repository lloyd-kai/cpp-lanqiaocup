//题目链接：https://www.lanqiao.cn/problems/3683/learning/?page=1&first_category_id=1&problem_id=3683 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int x[N];
int n,m;

int check(int mid)
{
  int res = 0;
  for(int i  =1,lst = 0;i<=n;i++)
  {
    if(lst && x[i] - x[lst] <mid)
    {
      continue;
    }
    res++;
    lst = i;
  }
  return res;
}


int main()
{  
  cin>>n>>m;
  for(int i = 1;i<=n;i++)
  {
    cin>>x[i];
  }
  sort(x+1,x+1+n);

  int l = 0,r = 1e9+5;
  while(l+1!=r)
  {
    int mid = (l+r)>>1;//右移一位相当于/2
    if(check(mid)>=m)
    {
      l = mid;
    }
    else
    {
      r = mid;
    }
  }
  cout<<l<<'\n';

  return 0;
}
