//��Ŀ���ӣ�https://www.lanqiao.cn/problems/3820/learning/?page=1&first_category_id=1&problem_id=3820 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p =1e9+7;
const int inf = 1e9,N = 1e3+3;

int n,m,k,sx,sy,fx,fy,h[N][N];

//��λ����
int dx[] = {0,0,1,-1} ;
int dy[] = {1,-1,0,0};

int dp[N][N][2];

//�ж��Ƿ񳬳���ͼ
bool inmp(int x,int y)
{
 	return 1<=x && x<=n && 1<=y && y<=m;
}

//����ֵ��ʾ�ܷ񵽴��յ�,t��ʾ��ǰʹ�����������Ĵ��� 
bool dfs(int x,int y,int t) 
{
	//����Ŀ�ĵ�ʱֹͣ 
	if(x == fx && y == fy)
	{
		return true;
	}
	
	//����˵��Ѿ������
	if(dp[x][y][t] !=-1) 
	{
		return dp[x][y][t];
	}
	
	//��ʼ�ƶ� 
	for(int i = 0;i<4;i++)
	{
		int nx = x+dx[i],ny = y+dy[i];
		
		if(!inmp(nx,ny))
		{
			continue;
		}
		
		if(!t)//û���ù�����
		{
			//���ñ���
			if(h[x][y]>h[nx][ny] && dfs(nx,ny,0)) 
			{
				return dp[x][y][t] =true;
			}
			//ʹ�ñ���
			if(h[x][y]+k>h[nx][ny] && dfs(nx,ny,1)) 
			{
				return dp[x][y][t] =true;
			} 
		} 
		else//�Ѿ�ʹ�ù����������� 
		{
			//���� 
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
	
	//��ʼ����ͼ
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
