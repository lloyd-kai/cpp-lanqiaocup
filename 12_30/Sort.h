#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void Test_Sort(void)
{
	//初始化
	vector<int> v= {5,1,3,9,11};
	
	//对数组排序
	sort(v.begin(),v.end(),[](const int &u,const int &v) 
	{
		return u>v;
	});
	
	for(int i = 0;i<v.size();i++)
	{
		cout<<v[i]<<' ' ;
	}
}
