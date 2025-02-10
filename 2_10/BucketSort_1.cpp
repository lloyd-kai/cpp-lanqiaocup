//题目链接： https://www.lanqiao.cn/problems/1314/learning/?page=1&first_category_id=1&problem_id=1314
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+7;
int n;
int bucket[MAXN];//一个值对应一个桶
int main()
{
	cin>>n;
	for(int i = 1;i<=n;i++)	
	{
		int x;
		cin>>x;
		bucket[x++];//由于每个只有一个值，但是可以有多个相同值的数，所以只需要记录元素个数即可 
	}
	for(int i = 0;i<=n;i++)
	{
		for(int j = 1;j<= bucket[i];j++) // 值为i的元素有bucket[i]个 
		{
			cout<<i<<" ";
		}
	}
} 
