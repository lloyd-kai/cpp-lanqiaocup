#pragma once 
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;


void Test_list(void) 
{
	//��ʼ��
	list<int> myList;
	
	//��listβ�����Ԫ��
	for(int i = 1;i<=5;i++) 
	{
		myList.push_back(i);
	}
	
	//��ͷ��β���List�е�Ԫ��
	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
	cout<<'\n';
	
	//������Ԫ�ط�ת
	reverse(myList.begin(),myList.end());
	
	//�ڵ�һ��Ԫ�صĺ�һ��λ�ü���Ԫ��0
	myList.insert(++ myList.begin(),0) ;
	
	//�ڵ�һ��Ԫ�غ�����λ�ú����һ��λ�õ�ǰһ��Ԫ��ɾ��
	myList.erase(++ ++ myList.begin(), -- myList.end());
	
	//���list�Ĵ�С
	cout<< "����Ĵ�СΪ: "<<myList.size()<<'\n' ;
	
	//����������е�Ԫ��
	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
	
}
