#pragma once 
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void Test_vector(void)
{
	//��ʼ��vevtor
	vector<int> numbers;
	
	//���Ԫ��
	numbers.push_back(5);
	numbers.push_back(2);
	numbers.push_back(8);
	numbers.push_back(5);
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(9);
	numbers.push_back(8);
	
	//���������е�Ԫ��
	for(const auto &e:numbers) 
	{
		cout<<e<<" "; 
	}
	cout<<endl;
	
	//������Ԫ������
	sort(numbers.begin(),numbers.end());
	
	//��ӡ���������� 
	for(const auto &e:numbers) 
	{
		cout<<e<<" "; 
	}
	cout<<endl;
	
	//ȥ���ظ�Ԫ��
	numbers.erase(unique(numbers.begin(),numbers.end()),numbers.end()) ;
	
	//��ӡȥ�غ��Ԫ��
	for(const auto &e:numbers) 
	{
		cout<<e<<" "; 
	}
	cout<<endl;
	
	//����Ԫ��
	numbers.insert(numbers.begin()+2,3) ;
}
