#pragma once
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//定义全局变量
const int N = 1e5+9;
const ll p = 1e9+7;//在许多题目中经常出现1e9+7，这是在提醒此数超出了int的表示范围，需要使用更大表示范围的数

//带备忘录的递归，能保存以前的计算过的数,提高一定的效率
ll dp[N];

ll fib(int n) 
{
	if(dp[n])//如果以前记录过此斐波那契数就直接输出 
	{
		return dp[n];
	}
	if(n<=2)
	{
		return 1;//递归边界 
	}
	return dp[n] = (fib(n-1)+fib(n-2))%p;//分解为子问题 
}

void Test_fib(void)
{
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cout<<fib(i)<<endl;//如果要充分发挥备忘录的作用，可以用迭代的方式求出从3到n的所有fib值 
	}
} 
 
