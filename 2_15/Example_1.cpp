#include <iostream>
#include <vector> 
using namespace std;
typedef long long ll;
const int MAXN = 1100;
int n, V;
int f[MAXN][MAXN];//��uΪ������������v���
int w[MAXN], v[MAXN];
int cnt, head[MAXN];
vector<int>g[MAXN];
//�����ڵ�Ľṹ�壬����ΪȨֵ����һ���ڵ� 
struct Edge
{
	int nex, to;
}edge[MAXN << 1];

//��ӽڵ�
void add(int from, int to)
{
	edge[++cnt].nex = head[from];
	head[from] = cnt;
	edge[cnt].to = to;
}

//DFS����
void dfs(int u, int fa)
{
	memset(f[u], -0x3f, sizeof(f[u]));
	//�ѵ�ǰ�ڵ�u��������Ӧ��������������Ʒ��Ȼ��01����ת�� 
	if (v[u] <= V) //u����ڵ�Ϊ������������ֻ��u��һ���ڵ㡣 
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
		//��ǰ�����ı������� 
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

