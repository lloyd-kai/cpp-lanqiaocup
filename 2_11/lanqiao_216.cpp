//题目链接：https://www.lanqiao.cn/problems/216/learning/?page=1&first_category_id=1&problem_id=216 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p =1e9+7;
const int inf = 1e9,N = 55;

int n,m,k,c[N][N];

//方位数组
int dx[] = {0,1};
int dy[] = {1,0};

//最好不要将其理解为四维数组，而是理解为二维数组的嵌套，即组成二维数组的元素为二维数组 
int dp[N][N][15][15];

//判断是否超出地图
bool inmp(int x,int y)
{
 	return 1<=x && x<=n && 1<=y && y<=m;
}

//表示从(1,1)到(x,y) 有cnt件宝贝,且最大值为mx的方案数 
ll dfs(int x,int y,int mx,int cnt) 
{
	//到达目的地时停止 
	if(x == n && y == m)
	{
		return (ll)(cnt == k);
	}
	
	//如果此点已经记忆过
	if(dp[x][y][mx][cnt] !=-1) 
	{
		return dp[x][y][mx][cnt];
	}
	
	ll res = 0;
	
	//开始移动 
	for(int i = 0;i<2;i++)
	{
		int nx = x+dx[i],ny = y+dy[i];
		
		if(!inmp(nx,ny))
		{
			continue;
		}
		
		//拿宝贝 
		if(c[nx][ny]>mx && cnt<k) 
		{
			res = (res+dfs(nx,ny,c[nx][ny],cnt+1))%p; 
		}
		
		//不拿宝贝
		res = (res+dfs(nx,ny,mx,cnt))%p;
		
	}
	return dp[x][y][mx][cnt] = res; 
}

int main()
{
	memset(dp,-1,sizeof dp);
	cin>>n>>m>>k;
	
	//初始化地图
	for(int i  =1;i<=n;i++) 
	{
		for(int j = 1;j<=m;j++)
		{
			cin>>c[i][j];
      c[i][j]++;
		}
	}
	cout<<(dfs(1,1,0,0)+dfs(1,1,c[1][1],1))%p;
	
	return 0;
}
