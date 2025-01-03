#pragma once 
#include <iostream>
#include <set>
using namespace std;

void Test_set(void)
{
	//��ʼ������ 
	set<int> mySet;
	
	//����Ԫ��
	mySet.insert(5);
	mySet.insert(2);
	mySet.insert(8);
	mySet.insert(2);//�ظ�Ԫ�� �����Ч
	
	//��������
	cout<<"���ϵ�Ԫ��Ϊ: ";
	for(const auto &elem:mySet) 
	{
		cout<<elem<<" ";
	}
	
	cout<<endl;
	
	//����Ԫ��
	int searchValue = 5;
	auto it = mySet.find(searchValue) ;
	if(it!=mySet.end())
	{
		cout<<searchValue<<"�ҵ���"	<<endl;
	} 
	else
	{
		cout<<searchValue<<"û�б��ҵ�"<<endl;
	}
	
	//�Ƴ�Ԫ��
	int removeValue = 2;
	mySet.erase(removeValue);
	
	//�ٴα������� 
	cout<<"���ϵ�Ԫ��Ϊ: ";
	for(const auto &elem:mySet) 
	{
		cout<<elem<<" ";
	}
	
	cout<<endl;
	
	//��ռ���
	mySet.clear();
	
	//��鼯���Ƿ�Ϊ��
	if(mySet.empty()){
		cout<<"����Ϊ��" <<endl;
	} 
	else
	{
		cout<<"���ϲ�Ϊ��"<<endl; 
	}
}
