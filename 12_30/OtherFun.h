#pragma once
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

void Test_Memset(void) 
{
	int arr[10];
	memset(arr,0,sizeof(arr));
	
	for(int i = 0;i<10;i++)
	{
		cout<<arr[i]<<' ';
	}
	
	int a[5] ;
	memset(a,1,sizeof(a));
	for(int i = 0;i<5;i++)
	{
		cout<<bitset<32>(a[i])<<'\n';
	}
}

void Test_Reverse(void)
{
	vector<int> v = {1,2,3,4,5};
	reverse(v.begin(),v.end());
	for(int i = 0;i<v.size();i++)
	{
		cout<<v[i]<<' ';
	}
	cout<<'\n';
}

void Test_Unique(void)
{
	int a[] = {1,1,2,2,3};
	int n = unique(a,a+5)-a;
	for(int i = 0;i<n;i++)
	{
		cout<<a[i]<<' ' ;
	}
}

void Test_permutation(void)
{
	vector<int> v = {1,2,3};
	
	//������һ������
	while(next_permutation(v.begin(),v.end()))
	{
		cout<<"��һ������";
		for(int i = 0;i<3;i++) 
		{
			cout<<v[i]<<' ';
		}
		cout<<'\n';
	} 
}

void Test_TheValue(void) 
{
	//��ʼ��
	vector<int> v = {5,1,3,4,11} ;
	
	//�������Ԫ��
	cout<<*max_element(v.begin(),v.end()) <<'\n';
}

void Test_nth(void)
{
	//��ʼ��
	vector<int> v = {5,1,7,3,10,18,9};
	
	//�������Ԫ��
	nth_element(v.begin(),v.begin()+3,v.end()) ;
	
	for(int i = 0;i<7;i++)
	{
		cout<<v[i]<<' ';
	}
}
