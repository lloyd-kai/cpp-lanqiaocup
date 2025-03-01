#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
//这是16届蓝桥杯模拟赛的相关题目的个人解答，供以后个人学习和查漏补缺 
//const int N = 1e5+7;//第九题的大小 

//第八题 
//int main()
//{
//	ll n,m,a;
//	cin>>n>>m>>a;
//	ll res = n*m*a;
//	cout<<res;
//	
//	return 0;
//} 

//第九题 
//创建一个“前缀和 ”的数组，分别记录前一个的最大值，前两个的最大值，前n个的最大值
//int a[N] ;
//int pre[N];
//
//int main()
//{
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	int n;
//	cin>>n;
//	//先初始化第一个数 
//	cin>>a[1];
//	pre[1] = a[1];
//	for(int i = 2;i<=n-1;i++)
//	{
//		cin>>a[i] ;
//		pre[i] = a[i]>pre[i-1]?a[i]:pre[i-1] ;//初始化前缀和数组 
//	}
//	
//	int res = 1;//第一个元素默认比之前位置大
//	for(int i = 2;i<=n;i++) 
//	{
//		if(a[i]>pre[i-1])
//		{
//			res++;
//		}
//	}
//	cout<<res;
//	
//	return 0; 
//} 

//第十题 字典序
//比较字符串函数,并返回最小字典序的字符串 
//string StrCompare(string s1,string s2) 
//{
//	if(s1.compare(s2)>0)
//	{
//		return s2;
//	}
//	return s1;
//}
//
//vector<string> Q;
//
//int main() 
//{
//	//我要开始用暴力算法了:-) 
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	string s;
//	for(int i = 0;i<4;i++)
//	{
//		cin>>s;
//		Q.push_back(s);
//	}
//	
//	//开始比较，字典序小的放在前面
//	//这里用到了冒泡排序的思想 
//	for(int i = 0;i<4;i++) 
//	{
//		for(int j = i+1;j<4;j++)
//		{
//			if(Q[i]>=Q[j])
//			{
//				string temp = Q[j];
//				Q[j] = Q[i];
//				Q[i] = temp;
//			}
//		}
//	}
//	string res;
//	for(int i = 0;i<4;i++)
//	{
//		res+=Q[i];
//	}
//	cout<<res<<'\n';
// 
//	return 0;
//}


//第十一题 双指针
//const int N = 1e5+9;
//const int M = 1e5+9;
////村名期望和礼物价值数组 
//int e[N];
//int v[M];
// 
// 
//int main()
//{
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	int n,m;
//	cin>>n;
//	for(int i = 1;i<=n;i++)
//	{
//		cin>>e[i];
//	}
//	cin>>m;
//	for(int i = 1;i<=m;i++)
//	{
//		cin>>v[i];
//	}
//	
//	//开始分配礼物,利用双指针 
//	int p1 = 1;
//	int p2 = 1;
//	int res = 0;
//	while(p1<=n && p2<=m) 
//	{
//		if(v[p2]>=e[p1]) 
//		{
//			res++;
//			p1++;
//			p2++;
//		}
//		else
//		{
//			p2++;
//		}
//	}
//	cout<<res<<'\n';
//	
//	return 0;	
//} 

//12题没时间了 大概是二维数组的前缀和动态规划


//第五题
#include "code.h"
int main()
{
	string res = Find();
	cout<<res;
	return 0; 
} 


