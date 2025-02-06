//题目链接：https://www.lanqiao.cn/problems/3227/learning/?page=1&first_category_id=1&problem_id=3227
#pragma once
#include <bits/stdc++.h>
using namespace std;

//使用map映射，当然使用哈希表也是可以的
map<int,int> mp;

int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n,m;
  cin>>n>>m;

  for(int i = 1;i<=n*m;i++)
  {
    int x;
    cin>>x;
    mp[x]++;//每相同元素出现时值+1
  }

  //遍历值出现的次数，如果超过一半就是要找的值
  //当然如果能根据次数进行排序那再好不过了
  for(const auto &[x,y]:mp)
  {
    if(2*y>n*m)
    {
      cout<<x;
    }
  }

  return 0;
}
