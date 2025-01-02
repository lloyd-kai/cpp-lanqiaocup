#pragma once 
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;


void Test_list(void) 
{
	//初始化
	list<int> myList;
	
	//向list尾部添加元素
	for(int i = 1;i<=5;i++) 
	{
		myList.push_back(i);
	}
	
	//从头到尾输出List中的元素
	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
	cout<<'\n';
	
	//将所有元素反转
	reverse(myList.begin(),myList.end());
	
	//在第一个元素的后一个位置加上元素0
	myList.insert(++ myList.begin(),0) ;
	
	//在第一个元素后两个位置和最后一个位置的前一个元素删除
	myList.erase(++ ++ myList.begin(), -- myList.end());
	
	//输出list的大小
	cout<< "链表的大小为: "<<myList.size()<<'\n' ;
	
	//遍历输出所有的元素
	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
	
}
