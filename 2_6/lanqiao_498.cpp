//题目链接：https://www.lanqiao.cn/problems/498/learning/?page=1&first_category_id=1&problem_id=498
#pragma once 
#include <bits/stdc++.h>
using namespace std;

//字符串转数字
int s2i(string s)
{
  int res = 0;
  for(const auto &i:s)
  {
    res = res*10+i-'0';
  }
  return res;
}

//数字转字符串
string i2s(int x,int w)
{
  string res;
  while(x)
  {
    res+=(x%10)+'0';
    x/=10;
  }
  //缺0的补齐
  while(res.length()<w)
  {
    res+='0';
  }
  reverse(res.begin(),res.end());
  return res;
}

//判断闰年函数
bool isLeapYear(int year)
{
  return (year %4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

//判断日期是否合法
bool isok(int year, int month, int day)
{
  int days[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if(isLeapYear(year))
  {
    days[2] = 29;
  }
  return day <= days[month];
}

//判断是否是回文日期
bool isPa(string s)
{
  for(int i = 0;i<s.length()/2;i++)
  {
    if(s[i]!=s[s.length()-1-i])
    {
      return false;
    }
  }
  return true;
}

//判断是不是AB类的字符串 
bool isPa2(string s)
{
  if(!isPa(s))
  {
    return false;
  }
  return s[0] == s[2] && s[1] == s[3];
}


int main()
{
  string s;cin >> s;
  //处理日期
  int year = s2i(s.substr(0, 4)), month = s2i(s.substr(4, 2)), day = s2i(s.substr(6, 2));
  //设置标志，一旦找到对应的日期就改为true停止判断 
  bool ans1 = false, ans2 = false;
  
  //枚举日期 
  for(int i = year;i <= 9999; ++ i)
  {
    for(int j = 1;j <= 12; ++ j)
    {
	  //跳过指定日期之前的枚举 
      if(i == year && j < month)continue;
       
      for(int k = 1 ;k <= 31; ++ k)
      {
      	//跳过指定日期之前的枚举  
        if(i == year & j == month && k <= day)continue;
        if(!isok(i, j,k))continue;

		//如果找到对应条件的日期就打印输出 
        string date = i2s(i,4)+i2s(j,2)+i2s(k,2);
        if(!ans1 && isPa(date))
        {
          cout << date<<'\n';
          ans1 = true;
        }
        if(!ans2 && isPa2(date))
        {
          cout << date << '\n';
          ans2 = true;
        }
      }
    }

  }


  return 0;
}
