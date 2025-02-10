//题目链接：https://www.lanqiao.cn/problems/182/learning/?page=1&first_category_id=1&problem_id=182 
#include <bits/stdc++.h> 
using namespace std;
const int N = 1e3+5;//定义最大深度

char mp[N][N];
int scc,n;//颜色编号 
int col[N][N];//颜色函数 

//方位数组，方便后续深入搜索周边 
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

//记录颜色是否消失(相当于岛屿消失) ,不是就为0 
bool vis[N*N];

void dfs(int x,int y)
{
	col[x][y] = scc; 
	for(int i = 0;i<4;i++) 
	{
		int nx = x+dx[i],ny = y+dy[i];//上下左右的坐标
		if(col[nx][ny] || mp[nx][ny] == '.') 
		{
			continue;//是海洋就跳过 
		}
		else
		{
			//继续深入搜索
			dfs(nx,ny);
		} 
	}
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin>>n;
    //初始化地图 
    for(int i = 1;i<=n;i++)
    {
    	cin>>mp[i]+1;
	}
	
	//开始给岛屿填色
	for(int i = 1;i<=n;i++) 
	{
		for(int j = 1;j<=n;j++)
		{
			if(col[i][j] || mp[i][j] == '.')
			{
				continue;//如果是海洋就跳过 
			}
			else //如果是陆地就深入搜索是否有其他相连的陆地 
			{
				scc++;//当前颜色的编号 
				
				dfs(i,j);
			} 
		}
	}
	
	int ans = 0;//未被淹没的岛屿 
	
	//开始淹没
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			if(mp[i][j] == '.')
			{
				continue;
			}
			
			bool tag = true;
			//判断四周是否有海洋
			 for(int k = 0;k<4;k++) 
			{
				int x = i+dx[k],y = j+dy[k];//上下左右的坐标
				if(mp[x][y] == '.') 
				{
					tag = false;
				}
			}
			if(tag)
			{
				//如果点对应颜色存在 
				if(!vis[col[i][j]])
				{
					ans++;
				}
				vis[col[i][j]] = true;
			}
		}
	}
	
	cout<<scc-ans<<"\n";
	
    return 0;
} 
