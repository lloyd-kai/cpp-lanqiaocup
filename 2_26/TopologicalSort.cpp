void topo()
{
	queue<int> q;
	//将所有入度为0的点加入到队列中
	for(itn i = 1;i<=n;i++) 
	{
		if(!ind[i])
		{
			q.push(i);
		}
	}
	while(q.size())
	{
		//取出队头的点x,此时它的入度一定为0
		int x = q.front();
		q.pop();
		for(const auto &y:g[x]) 
		{
			//处理边x->y
			ind[y]  --;//处理完成后y的入度--
			if(!ind[y]) 
			{
				q.push(y);//如果y入度为0，说明y的所有入点已经处理完成直接入队 
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
		//新增一条u->v的边
		int u,v;
		cin>>u>>v;
		ind[v] ++;//V的入度+1; 
	}
	return 0;
} 
