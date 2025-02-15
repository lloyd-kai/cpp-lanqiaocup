#include <iostream>
#include <vector> 
using namespace std;
typedef long long ll;
const int MAXN = 1100;
int n, V;
int f[MAXN][MAXN];//以u为根的子树内用v体积
int w[MAXN], v[MAXN];
int cnt, head[MAXN];
vector<int>g[MAXN];
//创建节点的结构体，属性为权值和下一个节点 
struct Edge
{
	int nex, to;
}edge[MAXN << 1];

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
	memset(f[u], -0x3f, sizeof(f[u]));
	//把当前节点u的子树对应的子树看作是物品，然后01背包转移 
	if (v[u] <= V) //u这个节点为根对饮的子树只有u这一个节点。 
	{
		f[u][v[u]] = w[u];
	}

	for (int i = head[u]; i; i = edge[i].nex)
	{
		int v = edge[i].to;
		if (v == fa)
		{
			continue;
		}
		dfs(v, u);
		//当前子树的背包过程 
		vector<int>nf(f[u], f[u] + V + 1);
		for (int v1 = 0; v1 <= V; v1++)
		{
			for (int v2 = 0; v1 + v2 <= V; v2++)
			{
				nf[v1 + v2] = max(nf[v1+v2], f[u][v1] + f[v][v2]);
			}
		}
		for (int v = 0; v <= V; v++)
		{
			f[u][v] = nf[v];
		}

	}
}


int main()
{
	scanf("%d%d", &n, &V);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		add(u, v);
		add(v, u);
	}
	dfs(1, 0);
	int ans = 0;
	for (int i = 0; i <= V; i++)
	{
		ans = max(ans, f[1][i]);
	}
	cout << ans;
	return 0;
}

