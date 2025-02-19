//题目链接：https://www.lanqiao.cn/problems/3205/learning/?page=1&first_category_id=1&problem_id=3205 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+7;

//对于布尔数组可以用bitset进一步减少空间复杂度
bitset<N>vis;

vector<int>primes;

void init(int n)
{
  vis[0] = vis[1] = true;
  for(ll i = 2;i<=n;i++)
  {
    if(!vis[i])
    {
      for(int j = 2*i;j<=n;j+=i)
      {
        vis[j] = true;
      }
    }
  }
  //将所有的素数放在一个数里
  for(int i = 1;i<=n;i++)
  {
    if(!vis[i])
    {
      primes.push_back(i);
    }
  }
}

int main()
{
  int n;
  cin>>n;
  init(n);
  int ans = 0;

  for(int i = 0;i<primes.size();i++)
  {
    for(int j = 0;j<i;j++)
    {
      if(!vis[primes[i]-primes[j]])
      {
        ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
