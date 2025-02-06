#pragma once
#include <bits/stdc++.h> 
using namespace std;


//离散化数组的实现 
const int N = 1e5+9;
int a[N];

vector<int> L;//离散化数组

//返回x在L中的下标
int getidx(int x) 
{
	return lower_bound(L.begin(),L.end(),x)-L.begin();	
} 

int main()
{	
	int n;
	cin>>n;//获取输入的数组元素的个数

	//初始化数组	
	for(int i = 1;i<=n;i++)	
	{
		cin>>a[i];
	}
	
	//将元素存入离散化数组中
	for(int i = 1;i<=n;i++) 
	{
		L.push_back(a[i]);
	}
	
	sort(L.begin(),L.end());
	//排序并去重
	L.erase(unique(L.begin(),L.end()),L.end()) ;
	
	cout<<"离散化数组为:";
	for(const auto &i :L)
	{
		cout<<i<<" ";
	}
	
	int val;
	cout<<"请输入你要找的元素:";
	cin>>val;
	
	cout<<"你要找的元素在L的下标为: "<<getidx(val)<<'\n';
	
	return 0;

} 
