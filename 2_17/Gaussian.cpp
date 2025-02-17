#include <iostream> 
using namespace std;
const int MAXN = 510;
int n;//n个方程就有n个未知数
double a[MAXN][MAXN], ans[MAXN];

//定义一个解决函数
int solve(int n, int m)
{
	for (int i = 1; i <= n; i++)
	{
		int r = i;//记录最大值的下标 
		for (int j = i + 1; j <= n; j++)
		{
			if (fabs(a[r][i]) < fabs(a[j][i]))
			{
				r = j;//记录最大值的下标	
			}
		}
		//第i行第i列a[i][i]
		if (fabs(a[r][i]))
		{
			continue;
		}
		for (int j = 1; j <= n + 1; j++)
		{
			swap(a[i][j], a[r][j]);
		}
		double div = a[i][i];
		for (int j = 1; j <= n + 1; j++)
		{
			a[i][j] /= a[i][i];
		}
		for (int j = i + 1; j <= n; j++)
		{
			div = a[j][i];
			for (int k = i; k <= n + 1; k++)
			{
				a[j][k] -= a[i][k] * div;
			}
		}
	}
	ans[n] = a[n][n + 1];
	for (int i = n - 1; i >= 1; i--)
	{
		ans[i] = a[i][n + 1];
		for (int j = i + 1; j <= n; j++)
		{
			ans[i] -= (a[i][j] * ans[j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%.2lf\n", ans[i]);
	}
	return 0;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n + 1; j++)
		{
			scanf("%lf", &a[i][j]);
		}
	}
	int guass = solve(n, n);
}

