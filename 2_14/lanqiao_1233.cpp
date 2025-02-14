//题目链接：https://www.lanqiao.cn/problems/1233/learning/?page=1&first_category_id=1&sort=difficulty&asc=1&problem_id=1233
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3+7;

int main()
{
	int n,a[MAXN] ,f[MAXN][MAXN];
	cin>>n;
	memset(f,127,sizeof(f));//将f初始化为无穷大
	for(int i = 1;i<=n;i++) 
	{
		cin>>a[i];
		f[i][i] = 0;//长度为1的区间不需要合并，代价是0
		a[i]+=a[i-1] ;//计算前缀和，sum(i,j) = a[j]-a[i-1] 
	}
	for(int len = 2;len<=n;len++)
	{
		for(int i = 1;i<=n-len+1;i++)
		{
			int j = i+len-1;
			for(int k = i;k<j;k++)
			{
				f[i][j] = min(f[i][j],f[i][k]+f[k+1][j]+a[j]-a[i-1]);
			}
		}
	}
	cout<<f[1][n]<<endl;
	return 0;
} 
