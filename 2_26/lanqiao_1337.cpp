//��Ŀ���ӣ�https://www.lanqiao.cn/problems/1337/learning/?page=1&first_category_id=1&problem_id=1337 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e6+9;

int n,m,ind[N],dp[N];
vector<int>g[N];

void topo()
{
	queue<int> q;
	//���������Ϊ0�ĵ���뵽������
	for(int i = 1;i<=n;i++) 
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
			dp[y] = max(dp[y],dp[x]+1);
			if(--ind[y] == 0) 
			{
				q.push(y);//���y���Ϊ0��˵��y����������Ѿ��������ֱ����� 
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
