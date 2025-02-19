//题目链接：https://www.lanqiao.cn/problems/3334/learning/?page=1&first_category_id=1&problem_id=3334
#include <iostream>
using namespace std;

//将十进制数的每一位相加
int f(int x)
{
  int res = 0;
  while(x)
  {
    res+=x%10;
    x/=10;
  }
  return res;
}

bool isprime(int n)
{
  if(n<2)
  {
    return false;
  }
  for(int i = 2;i<=n/i;i++)
  {
    if(n%i == 0)
    {
      return false;
    }
  }
  return true;
}


int main()
{
  int n;
  cin>>n;
  int ans = 0;
  for(int i = 1;i<=n;i++)
  {
    if(isprime(f(i)))
    {
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
