#include <iostream> 
#include <vector>
using namespace std;
#define maxn 110
int n, m, v[maxn], w[maxn], s[maxn];
int f[2][maxn];

//创建商品的结构体(或者类也可以)
struct Goods
{
	int w, v;
};
int q[maxn];

int main()
{
	//初始化数据 
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &v[i], &w[i], &s[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int r = 0; r <= v[i]; r++)
		{
			int hh = 0, tt = 1;
			for (int j = r; j <= m; j += v[i])
			{
				while (hh <= tt && j - q[hh] > s[i] * v[i])
				{
					hh++;
				}
				while (hh <= tt && f[(i - 1) & 1][q[tt]] + (j - q[tt]) / v[i] * w[i] <= f[(i - 1) & 1][j])
				{
					tt--;
				}
				q[++tt] = j;
				f[i & 1][j] = f[(i - 1) * 1][q[hh]] + (j - q[hh]) / v[i] * w[i];
			}
		}
	}
	cout << f[n & 1][m] << endl;
	return 0;
}
