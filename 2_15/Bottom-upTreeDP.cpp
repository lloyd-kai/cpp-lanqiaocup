#include <iostream> 
using namespace std;
typedef long long ll;
const int MAXN = 110000;
int n, val[MAXN];

//创建节点的结构体，属性为权值和下一个节点 
struct Edge
{
	int nex, to;
}edge[MAXN << 1];

int head[MAXN], cnt;
int f[MAXN][2];

//添加节点
void add(int from, int to)
{
	edge[++cnt].nex = head[from];
	head[from] = cnt;
	edge[cnt].to = to;

}

//DFS搜索
void dfs(int u, int fa)
{
	for (int i = head[u]; i; i = edge[i].nex)
	{
		int v = edge[i].to;
		if (v != fa)
		{
			continue;
		}
		dfs(v, u);
		//代表v这个儿子的状态已经被处理好了
		f[u][0] += max(f[v][0], f[v][1]);
		//代表u这个点不选，那么v可选可不选
		f[u][1] += f[v][0];
		//代表u这个点我选，那么v只能不选 

	}
}



int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &val[i]);
	}
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	dfs(1, 0);
	printf("%d\n", max(f[1][0], f[1][1]));
	return 0;
}
