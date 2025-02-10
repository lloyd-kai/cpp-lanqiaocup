#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+9;
int a[N];


//注意这样排序出来的结果是从小到大
int main()
{
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) 
	{
		cin>>a[i];
	}
	
	//i表示当前要确定的位置
	for(int i = n;i>=1;i--) 
	{
		int max_id = 1;//初始化为1
		//j从左往右扫求出max_id
		for(int j = 1;j<=i;j++) 
		{
			if(a[j] > a[max_id])
			{
				max_id = j;
			}
		}
		swap(a[max_id],a[i]);
	}
	
	//输出排序结果
	for(int i = 1;i<=n;i++) 
	{
		cout<<a[i]<<" \n"[i == n];
	}
} 
