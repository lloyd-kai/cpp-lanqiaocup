//��Ŀ���ӣ�https://www.lanqiao.cn/problems/3227/learning/?page=1&first_category_id=1&problem_id=3227
#pragma once
#include <bits/stdc++.h>
using namespace std;

//ʹ��mapӳ�䣬��Ȼʹ�ù�ϣ��Ҳ�ǿ��Ե�
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
    mp[x]++;//ÿ��ͬԪ�س���ʱֵ+1
  }

  //����ֵ���ֵĴ������������һ�����Ҫ�ҵ�ֵ
  //��Ȼ����ܸ��ݴ��������������ٺò�����
  for(const auto &[x,y]:mp)
  {
    if(2*y>n*m)
    {
      cout<<x;
    }
  }

  return 0;
}
