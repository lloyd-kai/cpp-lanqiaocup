#include <iostream> 
#include <vector>
using namespace std;
#define maxn 110
int n, m, v[maxn], w[maxn],s[maxn];
int f[maxn];

//创建商品的结构体(或者类也可以)
struct Goods
{
	int w, v;
};
vector<Goods>goods;

// 第二种多重背包的算法实现
//利用二进制的方法实现优化(比如将7看作是110,就是4个i与3个i ，也就是7件 
int main()
{
	//初始化数据 
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &v[i], &w[i], &s[i]);
		for (int k = 1; k <= s[i]; k++)
		{
			s[i] = k;
			goods.push_back({ w[i] * k, v[i] * k });
		}
		if (s[i] > 0)
		{
			goods.push_back({ s[i] * w[i],s[i] * v[i] });
		}
	}
	for (int i = 0; i < goods.size(); i++)
	{
		for (int j = m; j >= goods[i].w; j--)
		{
			f[j] = max(f[j], f[j - goods[i].w] + goods[i].v);
		}
	}

	cout << f[n] << endl;
	return 0;
}
