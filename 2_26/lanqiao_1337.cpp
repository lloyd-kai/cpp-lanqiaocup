//题目链接：https://www.lanqiao.cn/problems/1337/learning/?page=1&first_category_id=1&problem_id=1337 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e6+9;

int n,m,ind[N],dp[N];
vector<int>g[N];

void topo()
{
	queue<int> q;
	//将所有入度为0的点加入到队列中
	for(int i = 1;i<=n;i++) 
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
			dp[y] = max(dp[y],dp[x]+1);
			if(--ind[y] == 0) 
			{
				q.push(y);//如果y入度为0，说明y的所有入点已经处理完成直接入队 
			}
		}
	}
}

void solve()
{
  cin>>n>>m;
  for(int i = 1;i<=m;i++)
  {
    int x,y;
    cin>>x>>y;
    ind[y]++;
    g[x].push_back(y);
  }
  topo();
  int ans = 0;
  for(int i = 1;i<=n;i++)
  {
    ans = max(ans,dp[i]);
  }
  cout<<ans<<'\n';
}


int main()
{
	solve();
	return 0;
} 
