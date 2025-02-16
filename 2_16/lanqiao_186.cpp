//题目链接：https://www.lanqiao.cn/problems/186/learning/?page=1&first_category_id=1&name=%E7%B3%96%E6%9E%9C
#include <bits/stdc++.h> 
using namespace std;
const int MAXN = 2100000;
//这里f表示某种口味需要的糖果包数量 
int n,m,a[MAXN],f[MAXN],k;

int main()
{
	scanf("%d%d%d",&n,&m,&k) ;
	int maxx = (1<<m)-1;
	for(int i = 0;i<MAXN;i++) 
	{
		f[i] = 0x3f3f3f3f;
	}
	for(int i  =0;i<n;i++)
	{
		int x;
		//1 3 5 10101
		for(int j = 0;j<k;j++)
		{
			scanf("%d",&x);
			a[i] = a[i]|(1<<(x-1));
		}
		f[a[i]] = 1;
	}
	f[0] = 0;
	for(int i = 0;i<n;i++)
	{
		for(int j = 1;j<maxx;j++)
		{
			f[j|a[i]] = min(f[j|a[i]],f[j]+1);
		}
	}
	//特殊情况判断 
	if(f[(1<<m)-1]>n)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<f[(1<<m)-1]<<endl;
	}
	return 0;
} 
