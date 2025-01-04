#pragma once
#include <bits/stdc++.h>
using namespace std;

void Test_1531(void)
{
  //在算法中，一般建议将这种容器放在函数之外，也就是在堆区中开辟，防止栈溢出 
  map<string,vector<string>>mp;
  //一个城市对应多个快递单号，这里最好使用vector容器，用map键访问会很麻烦
  vector<string>citys;
	
  //施法前摇
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int num = 0;
  cin>>num;

  for(int i = 0;i<num;i++)
  {
    string a,b;
    cin>>a>>b;
    mp[b].push_back(a);
    if(mp[b].size() == 1) //这里不能使用mp.count(b) 判断其是否添加city，否则会导致citys中就只有一个城市 
    {
      citys.push_back(b);
    }
  }

  for(const auto &city : citys)
  {
    cout<< city <<' '<<mp[city].size()<<'\n';
    for(const auto &i:mp[city])
    {
      //输出其快递编号
      cout << i <<'\n';
    }
  }
}

