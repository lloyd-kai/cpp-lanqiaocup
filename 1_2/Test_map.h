#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;

void Test_map(void)
{
	//��ʼ��map
	map<int,string> myMap = {{1,"Apple"},{2,"Banana"},{3,"Orange"}};
	
	//����Ԫ��
	myMap.insert(make_pair(4,"Grapes")) ;
	
	//���Һͷ���Ԫ��
	cout<<"��Ϊ2��Ӧ���ַ���Ϊ"<<myMap[2]<<'\n' ;
	
	//��������ӡmap�е�Ԫ��
	for (map<int, string>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
        cout <<"��Ϊ��"<< it->first <<"ֵΪ: "<< it->second << endl;
    } 
    
    //ɾ��Ԫ��-ɾ��ָ���� 
	myMap.erase(3) ;
	
	//�ж�Ԫ���Ƿ����-Ҳ�����ж�ĳ�����Ƿ�����Ϊ0 
	if(myMap.count(3)==0) 
	{
		cout<<"��3û���ҵ�" <<'\n';
	}
	
	//���map
	myMap.clear();
	
	//�ж�map�Ƿ�Ϊ��
	if(myMap.empty()) 
	{
		cout<<"Map�ǿյ�" <<'\n';
	}
	
}
