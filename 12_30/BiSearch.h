#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void Test_BiSearch(void)
{
	vector<int> numbers = {1,3,5,7,9};
	int target = 5;
	bool flag = binary_search(numbers.begin(),numbers.end(),target);
	if(flag)
	{
		cout<<"目标元素"<<target<<"被找到"<<'\n';
	}
}

void Test_bound(void) 
{
	//初始化 
	vector<int> v = {5,1,7,3,10,18,9};
	sort(v.begin(),v.end());
	
	for(int i = 0;i<v.size();i++)
	{
		cout<<i<<' ';
	}
	cout<<'\n';
	
	//找到数组中第一个大于等于8元素的位置 
	cout<<(lower_bound(v.begin(),v.end(),8)-v.begin())<<'\n';
	
}
