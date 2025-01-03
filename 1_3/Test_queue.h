#pragma once 
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

//�Զ���ȽϺ���
//����1 ���������
struct Compare{
	bool operator()(int a,int b)
	{
		//�Զ���ıȽϺ��� ������������
		return a>b; 
	}
	
	//ʹ���Զ��庯���ķ���
	//����Ҫ�ĵط�д priority_queue<int,vector<int>,Compare>pq;
	//ע�������Զ��庯��������Ӧ�ĳ�ʼ�����еĸ�ʽ�ǲ�һ���� 
}; 

//����2 �Զ���ȽϺ��� 
void Test_Compare(void)
{
	//�Զ���ȽϺ�����ע������ʹ��auto�򻯺������͵���д
	auto compare = [](int a,int b){
		//�Զ���ȽϺ���
		return a>b; 
	} 
	
	//ʹ���Զ���ȽϺ����ķ��� 
	priority_queue<int,vector<int>,decltype(compare)>pq(compare);
}

