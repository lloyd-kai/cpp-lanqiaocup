#pragma once
#include <cctype> 
#include <iostream>
using namespace std;

//�����Сдת������ 
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
	//��������ַ���Сд���д����д��Сд
	string s;
	getline(cin,s);
	for(int j = 0;j<s.length();j++)
	{
		s[j] = convertedCh(s[j]);
	}
	cout<<s<<'\n';
}


