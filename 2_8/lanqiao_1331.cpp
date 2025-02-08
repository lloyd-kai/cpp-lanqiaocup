//题目链接：https://www.lanqiao.cn/problems/1331/learning/?page=1&first_category_id=1&problem_id=1331 
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x;
  cin>>x;
  int ans = 0;
  while(x)
  {
  	//判断最低位是否是1 
    if(x &1)
    {
      ans++;
    }
    //判断完后右移一位 
    x>>=1;
  }
  cout<<ans;
  return 0;
}
