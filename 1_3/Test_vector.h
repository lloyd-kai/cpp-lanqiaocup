#pragma once 
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void Test_vector(void)
{
	//初始化vevtor
	vector<int> numbers;
	
	//添加元素
	numbers.push_back(5);
	numbers.push_back(2);
	numbers.push_back(8);
	numbers.push_back(5);
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(9);
	numbers.push_back(8);
	
	//遍历向量中的元素
	for(const auto &e:numbers) 
	{
		cout<<e<<" "; 
	}
	cout<<endl;
	
	//对向量元素排序
	sort(numbers.begin(),numbers.end());
	
	//打印排序后的向量 
	for(const auto &e:numbers) 
	{
		cout<<e<<" "; 
	}
	cout<<endl;
	
	//去除重复元素
	numbers.erase(unique(numbers.begin(),numbers.end()),numbers.end()) ;
	
	//打印去重后的元素
	for(const auto &e:numbers) 
	{
		cout<<e<<" "; 
	}
	cout<<endl;
	
	//插入元素
	numbers.insert(numbers.begin()+2,3) ;
}
