#pragma once
#include <bits/stdc++.h>
using namespace std;

void Test_1531(void)
{
  //���㷨�У�һ�㽨�齫�����������ں���֮�⣬Ҳ�����ڶ����п��٣���ֹջ��� 
  map<string,vector<string>>mp;
  //һ�����ж�Ӧ�����ݵ��ţ��������ʹ��vector��������map�����ʻ���鷳
  vector<string>citys;
	
  //ʩ��ǰҡ
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int num = 0;
  cin>>num;

  for(int i = 0;i<num;i++)
  {
    string a,b;
    cin>>a>>b;
    mp[b].push_back(a);
    if(mp[b].size() == 1) //���ﲻ��ʹ��mp.count(b) �ж����Ƿ����city������ᵼ��citys�о�ֻ��һ������ 
    {
      citys.push_back(b);
    }
  }

  for(const auto &city : citys)
  {
    cout<< city <<' '<<mp[city].size()<<'\n';
    for(const auto &i:mp[city])
    {
      //������ݱ��
      cout << i <<'\n';
    }
  }
}

