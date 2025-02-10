//示例例题：求1-n的全排列
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+9;

int a[N];
bool vis[N];

void dfs(int dep)
{
	if(dep == n+1)
	{
		for(int i = 1;i<=n;i++)
		{
			cout<<a[i]<<" ";//递归出口，当前深度超过树的深度时 
		}
		cout<<"\n";
		return;
	}
	for(int i = 1;i<=n;i++) 
	{
		//排除不合法的路径，也就是此节点已经访问过时 
		if(vis[i]) 
		{
			continue;
		}
		
		//修改状态
		vis[i] = true;
		a[dep] = i;
		
		//下一层
		dfs(dep+1);
		
		//恢复现场
		vis[i] = false;
		//a[dep] = 0可以省略 
	}
}
