#pragma once
#include <cctype> 
#include <iostream>
using namespace std;

//定义大小写转化函数 
char convertedCh(char ch) 
{
	if(islower(ch))
	{
		ch = toupper(ch);
	}
	else if(isupper(ch))
	{
		ch = tolower(ch);
	}
	return ch;
}

void Test_Character(void)
{
	//将输入的字符串小写变大写，大写变小写
	string s;
	getline(cin,s);
	for(int j = 0;j<s.length();j++)
	{
		s[j] = convertedCh(s[j]);
	}
	cout<<s<<'\n';
}


