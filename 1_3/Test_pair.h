#pragma once 
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//����һ���ṹ�壬��ʾһ���˵���Ϣ
struct Person
{
	string name;
	int age;
};

void Test_pair(void)
{
	//����һ���洢Person�����vector����
	vector<Person> people;
	
	//���һЩPerson����vector��
	people.push_back({"Alice",25});
	people.push_back({"Bob",30});
	people.push_back({"Charlie",20});
	
	//����һ���洢pair��vector
	vector<pair<Person,int>>scores;
	
	//���һЩԪ��
	scores.push_back({people[0],90});
	scores.push_back({people[1],85});
	scores.push_back({people[2],95});
	
	//��������ӡ�������������
	for(auto it:scores) {
		cout<<"Name is "<<it.first.name<<'\n';
		cout<<"Age is "<<it.first.age<<'\n';
		cout<<"Score is "<<it.second<<'\n';
    }
}
