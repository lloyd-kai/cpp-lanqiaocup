int ord;//DFS�����
int rnk[MAXN];//rnk[i]��������Ϊi�Ľڵ���

struct NODE
{
    int fa;//��ǰ�ڵ�ĸ��ڵ�
    int in;//��ǰ�ڵ��DFS����
    int out;//��ǰ�ڵ��DFS����
    int son;//��ǰ�ڵ���ض��ӱ��
    int top;//��ǰ�ڵ����������׽ڵ���
    int deep;//��ǰ�ڵ������е����
    int size;//��ǰ�ڵ��������С
};

//��һ�ε�dfs
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
