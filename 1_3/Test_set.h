#pragma once 
#include <iostream>
#include <set>
using namespace std;

void Test_set(void)
{
	//初始化集合 
	set<int> mySet;
	
	//插入元素
	mySet.insert(5);
	mySet.insert(2);
	mySet.insert(8);
	mySet.insert(2);//重复元素 添加无效
	
	//遍历集合
	cout<<"集合的元素为: ";
	for(const auto &elem:mySet) 
	{
		cout<<elem<<" ";
	}
	
	cout<<endl;
	
	//查找元素
	int searchValue = 5;
	auto it = mySet.find(searchValue) ;
	if(it!=mySet.end())
	{
		cout<<searchValue<<"找到了"	<<endl;
	} 
	else
	{
		cout<<searchValue<<"没有被找到"<<endl;
	}
	
	//移除元素
	int removeValue = 2;
	mySet.erase(removeValue);
	
	//再次遍历集合 
	cout<<"集合的元素为: ";
	for(const auto &elem:mySet) 
	{
		cout<<elem<<" ";
	}
	
	cout<<endl;
	
	//清空集合
	mySet.clear();
	
	//检查集合是否为空
	if(mySet.empty()){
		cout<<"集合为空" <<endl;
	} 
	else
	{
		cout<<"集合不为空"<<endl; 
	}
}
