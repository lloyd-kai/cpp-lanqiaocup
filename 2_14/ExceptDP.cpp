#include <bits/stdc++.h>
using namespace std;
#define maxn 1100000
double f[maxn];
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	f[1] = 1;
	//其实就是在用动态规划的方法实现期望值的计算 
	for(int i = 2;i<=n;i++)
	{
		f[i] = f[i-1]+(k-f[i-1])/k;
	}
	printf("%.61f\n",f[n]);
	return 0;
}
