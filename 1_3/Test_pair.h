#pragma once 
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//定义一个结构体，表示一个人的信息
struct Person
{
	string name;
	int age;
};

void Test_pair(void)
{
	//创建一个存储Person对象的vector容器
	vector<Person> people;
	
	//添加一些Person对象到vector中
	people.push_back({"Alice",25});
	people.push_back({"Bob",30});
	people.push_back({"Charlie",20});
	
	//创建一个存储pair的vector
	vector<pair<Person,int>>scores;
	
	//添加一些元素
	scores.push_back({people[0],90});
	scores.push_back({people[1],85});
	scores.push_back({people[2],95});
	
	//遍历，打印姓名年龄和评分
	for(auto it:scores) {
		cout<<"Name is "<<it.first.name<<'\n';
		cout<<"Age is "<<it.first.age<<'\n';
		cout<<"Score is "<<it.second<<'\n';
    }
}
