#pragma once
#include <bits/stdc++.h> 
using namespace std;


//��ɢ�������ʵ�� 
const int N = 1e5+9;
int a[N];

vector<int> L;//��ɢ������

//����x��L�е��±�
int getidx(int x) 
{
	return lower_bound(L.begin(),L.end(),x)-L.begin();	
} 

int main()
{	
	int n;
	cin>>n;//��ȡ���������Ԫ�صĸ���

	//��ʼ������	
	for(int i = 1;i<=n;i++)	
	{
		cin>>a[i];
	}
	
	//��Ԫ�ش�����ɢ��������
	for(int i = 1;i<=n;i++) 
	{
		L.push_back(a[i]);
	}
	
	sort(L.begin(),L.end());
	//����ȥ��
	L.erase(unique(L.begin(),L.end()),L.end()) ;
	
	cout<<"��ɢ������Ϊ:";
	for(const auto &i :L)
	{
		cout<<i<<" ";
	}
	
	int val;
	cout<<"��������Ҫ�ҵ�Ԫ��:";
	cin>>val;
	
	cout<<"��Ҫ�ҵ�Ԫ����L���±�Ϊ: "<<getidx(val)<<'\n';
	
	return 0;

} 
