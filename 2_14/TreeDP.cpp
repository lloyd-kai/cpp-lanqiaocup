#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN = 110000;
int n, c[MAXN], dist[MAXN];

struct Edge {
	int nex, to, dis;
}edge[MAXN << 1];

int siz[MAXN], head[MAXN], cnt, tot;
int sum[MAXN];
ll f[MAXN];
//计算路径的函数 
void add(int from, int to, int dis)
{
	edge[++cnt] = { head[from],to,dis };
	head[from] = cnt;
}

void dfs(int x, int fa)
{
	siz[x] = 1;
	for (int i = head[x]; i; i= edge[i].nex)
	{
		int v = edge[i].to;
		if (v == fa)
		{
			continue;
		}
		dist[v] = dist[x] + edge[i].dis;
		dfs(v, x);
		siz[x] += siz[v];
		sum[x] += sum[v];
	}
}
void dfs1(int x, int fa)
{
	for (int i = head[x]; i;i = edge[i].nex)
	{
		int v = edge[i].to;
		if (v == fa)
		{
			continue;
		}
		f[v] = f[x] - sum[v] * edge[i].dis + (tot - sum[v]) * edge[i].dis;
		dfs(v, x);
	}
}


int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
		tot += c[i];
	}
	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
		add(b, a, c);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
	{
		f[1] += dist[i] * c[i];
	}
	dfs1(1, 0);
	ll ans = 101010101000;
	for (int i = 1; i <= n; i++)
	{
		ans = min(ans, f[i]);
	}
	cout << ans;
	return 0;
}

