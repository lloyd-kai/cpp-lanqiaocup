void topo()
{
	queue<int> q;
	//���������Ϊ0�ĵ���뵽������
	for(itn i = 1;i<=n;i++) 
	{
		if(!ind[i])
		{
			q.push(i);
		}
	}
	while(q.size())
	{
		//ȡ����ͷ�ĵ�x,��ʱ�������һ��Ϊ0
		int x = q.front();
		q.pop();
		for(const auto &y:g[x]) 
		{
			//�����x->y
			ind[y]  --;//������ɺ�y�����--
			if(!ind[y]) 
			{
				q.push(y);//���y���Ϊ0��˵��y����������Ѿ��������ֱ����� 
			}
		}
	}
}

int main()
{
	int m;
	cin>>m;
	while(m--)
	{
		//����һ��u->v�ı�
		int u,v;
		cin>>u>>v;
		ind[v] ++;//V�����+1; 
	}
	return 0;
} 
