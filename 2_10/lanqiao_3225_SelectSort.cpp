//题目链接：https://www.lanqiao.cn/problems/3225/learning/?page=1&first_category_id=1&problem_id=3225 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+9;
int a[N];

int main()
{
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) 
	{
		cin>>a[i];
	}
	
	//i表示当前要确定的位置
	for(int i = 1;i<=n;i++) 
	{
		int min_id = i;//初始化为i
		//j从左往右扫求出max_id
		for(int j = i;j<=n;j++) 
		{
			if(a[j] < a[min_id])
			{
				min_id = j;
			}
		}
		swap(a[min_id],a[i]);
	}
	
	//输出排序结果
	for(int i = 1;i<=n;i++) 
	{
		cout<<a[i]<<" \n"[i == n];
	}
} 
