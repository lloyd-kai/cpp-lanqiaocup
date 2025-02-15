#include <iostream> 
using namespace std;
typedef long long ll;
const int MAXN = 110000;
int n, val[MAXN];

//�����ڵ�Ľṹ�壬����ΪȨֵ����һ���ڵ� 
struct Edge
{
	int nex, to;
}edge[MAXN << 1];

int head[MAXN], cnt;
int f[MAXN][2];

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
	for (int i = head[u]; i; i = edge[i].nex)
	{
		int v = edge[i].to;
		if (v != fa)
		{
			continue;
		}
		dfs(v, u);
		//����v������ӵ�״̬�Ѿ����������
		f[u][0] += max(f[v][0], f[v][1]);
		//����u����㲻ѡ����ôv��ѡ�ɲ�ѡ
		f[u][1] += f[v][0];
		//����u�������ѡ����ôvֻ�ܲ�ѡ 

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
