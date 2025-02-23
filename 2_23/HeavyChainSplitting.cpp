int ord;//DFS序计数
int rnk[MAXN];//rnk[i]代表入序为i的节点编号

struct NODE
{
    int fa;//当前节点的父节点
    int in;//当前节点的DFS入序
    int out;//当前节点的DFS出序
    int son;//当前节点的重儿子编号
    int top;//当前节点所需链的首节点编号
    int deep;//当前节点在树中的深度
    int size;//当前节点的子树大小
};

//第一次的dfs
void dfs1(int t,int fa) 
{
	node[t].size = 1;
	node[t].fa = fa;
	node[t].deep = node[fa].deep+1;
	for(itn i = head[t];i;i = edge[i].next) 
	{
		if(edge[i].n!=fa)
		{
			dfs1(edge[i].n,t);
			node[t].size() += node[edge[i].n].size();
			if(node[edge[i].n].size> node[node[t].son].size)
			{
				node[t].son = edge[i].n;
			}
		}
	}
}
