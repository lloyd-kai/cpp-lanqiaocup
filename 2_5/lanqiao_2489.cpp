//�������� https://www.lanqiao.cn/problems/2489/learning/?page=1&first_category_id=1&problem_id=2489
#pragma once 

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 50;
int a[N];


int main()
{
  string s = "2021ABCD";
  for(int i = 0;i<s.length();i++)
  {
    if('0'<=s[i] && s[i]<='9')
    {
      a[i+1] = s[i]-'0';//�ַ���תΪ����
    }
    else
    {
      a[i+1] = s[i]-'A'+10;
    }
  }
  
  //����ת��
  ll x = 0;
  for(int i = 1;i<=s.length();i++)
  {
    x = x*16+a[i];//����ת��ģ��
  }
  cout<<x<<'\n';
  return 0;
}
