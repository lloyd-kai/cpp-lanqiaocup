#pragma once
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//����ȫ�ֱ���
const int N = 1e5+9;
const ll p = 1e9+7;//�������Ŀ�о�������1e9+7�����������Ѵ���������int�ı�ʾ��Χ����Ҫʹ�ø����ʾ��Χ����

//������¼�ĵݹ飬�ܱ�����ǰ�ļ��������,���һ����Ч��
ll dp[N];

ll fib(int n) 
{
	if(dp[n])//�����ǰ��¼����쳲���������ֱ����� 
	{
		return dp[n];
	}
	if(n<=2)
	{
		return 1;//�ݹ�߽� 
	}
	return dp[n] = (fib(n-1)+fib(n-2))%p;//�ֽ�Ϊ������ 
}

void Test_fib(void)
{
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cout<<fib(i)<<endl;//���Ҫ��ַ��ӱ���¼�����ã������õ����ķ�ʽ�����3��n������fibֵ 
	}
} 
 
