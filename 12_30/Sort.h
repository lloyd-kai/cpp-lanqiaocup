#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void Test_Sort(void)
{
	//��ʼ��
	vector<int> v= {5,1,3,9,11};
	
	//����������
	sort(v.begin(),v.end(),[](const int &u,const int &v) 
	{
		return u>v;
	});
	
	for(int i = 0;i<v.size();i++)
	{
		cout<<v[i]<<' ' ;
	}
}
