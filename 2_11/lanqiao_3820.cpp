//题目链接：https://www.lanqiao.cn/problems/3820/learning/?page=1&first_category_id=1&problem_id=3820 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p =1e9+7;
const int inf = 1e9,N = 1e3+3;

int n,m,k,sx,sy,fx,fy,h[N][N];

//方位数组
int dx[] = {0,0,1,-1} ;
int dy[] = {1,-1,0,0};

int dp[N][N][2];

//判断是否超出地图
bool inmp(int x,int y)
{
 	return 1<=x && x<=n && 1<=y && y<=m;
}

//返回值表示能否到达终点,t表示当前使用喷气背包的次数 
bool dfs(int x,int y,int t) 
{
	//到达目的地时停止 
	if(x == fx && y == fy)
	{
		return true;
	}
	
	//如果此点已经记忆过
	if(dp[x][y][t] !=-1) 
	{
		return dp[x][y][t];
	}
	
	//开始移动 
	for(int i = 0;i<4;i++)
	{
		int nx = x+dx[i],ny = y+dy[i];
		
		if(!inmp(nx,ny))
		{
			continue;
		}
		
		if(!t)//没有用过背包
		{
			//不用背包
			if(h[x][y]>h[nx][ny] && dfs(nx,ny,0)) 
			{
				return dp[x][y][t] =true;
			}
			//使用背包
			if(h[x][y]+k>h[nx][ny] && dfs(nx,ny,1)) 
			{
				return dp[x][y][t] =true;
			} 
		} 
		else//已经使用过喷气背包了 
		{
			//不用 
			if(h[x][y]>h[nx][ny] && dfs(nx,ny,1)) 
			{
				return dp[x][y][t] =true;
			}
		}
	}
	return dp[x][y][t] = false; 
}

int main()
{
	memset(dp,-1,sizeof dp);
	cin>>n>>m>>k;
	cin>>sx>>sy>>fx>>fy;
	
	//初始化地图
	for(int i  =1;i<=n;i++) 
	{
		for(int j = 1;j<=m;j++)
		{
			cin>>h[i][j];
		}
	}
	cout<<(dfs(sx,sy,0)?"Yes":"No")<<"\n";
	
	return 0;
}
