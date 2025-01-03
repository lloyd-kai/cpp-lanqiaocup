#pragma once 
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

//自定义比较函数
//方法1 重载运算符
struct Compare{
	bool operator()(int a,int b)
	{
		//自定义的比较函数 按照逆序排列
		return a>b; 
	}
	
	//使用自定义函数的方法
	//在需要的地方写 priority_queue<int,vector<int>,Compare>pq;
	//注意两种自定义函数方法对应的初始化队列的格式是不一样的 
}; 

//方法2 自定义比较函数 
void Test_Compare(void)
{
	//自定义比较函数，注意这里使用auto简化函数类型的书写
	auto compare = [](int a,int b){
		//自定义比较函数
		return a>b; 
	} 
	
	//使用自定义比较函数的方法 
	priority_queue<int,vector<int>,decltype(compare)>pq(compare);
}

