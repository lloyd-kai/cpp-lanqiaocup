#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;

void Test_map(void)
{
	//初始化map
	map<int,string> myMap = {{1,"Apple"},{2,"Banana"},{3,"Orange"}};
	
	//插入元素
	myMap.insert(make_pair(4,"Grapes")) ;
	
	//查找和访问元素
	cout<<"键为2对应的字符串为"<<myMap[2]<<'\n' ;
	
	//遍历并打印map中的元素
	for (map<int, string>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
        cout <<"键为："<< it->first <<"值为: "<< it->second << endl;
    } 
    
    //删除元素-删除指定键 
	myMap.erase(3) ;
	
	//判断元素是否存在-也就是判断某个键是否数量为0 
	if(myMap.count(3)==0) 
	{
		cout<<"键3没有找到" <<'\n';
	}
	
	//清空map
	myMap.clear();
	
	//判断map是否为空
	if(myMap.empty()) 
	{
		cout<<"Map是空的" <<'\n';
	}
	
}
