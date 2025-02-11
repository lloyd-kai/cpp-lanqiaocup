//��Ŀ���ӣ�https://www.lanqiao.cn/problems/216/learning/?page=1&first_category_id=1&problem_id=216 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p =1e9+7;
const int inf = 1e9,N = 55;

int n,m,k,c[N][N];

//��λ����
int dx[] = {0,1};
int dy[] = {1,0};

//��ò�Ҫ�������Ϊ��ά���飬�������Ϊ��ά�����Ƕ�ף�����ɶ�ά�����Ԫ��Ϊ��ά���� 
int dp[N][N][15][15];

//�ж��Ƿ񳬳���ͼ
bool inmp(int x,int y)
{
 	return 1<=x && x<=n && 1<=y && y<=m;
}

//��ʾ��(1,1)��(x,y) ��cnt������,�����ֵΪmx�ķ����� 
ll dfs(int x,int y,int mx,int cnt) 
{
	//����Ŀ�ĵ�ʱֹͣ 
	if(x == n && y == m)
	{
		return (ll)(cnt == k);
	}
	
	//����˵��Ѿ������
	if(dp[x][y][mx][cnt] !=-1) 
	{
		return dp[x][y][mx][cnt];
	}
	
	ll res = 0;
	
	//��ʼ�ƶ� 
	for(int i = 0;i<2;i++)
	{
		int nx = x+dx[i],ny = y+dy[i];
		
		if(!inmp(nx,ny))
		{
			continue;
		}
		
		//�ñ��� 
		if(c[nx][ny]>mx && cnt<k) 
		{
			res = (res+dfs(nx,ny,c[nx][ny],cnt+1))%p; 
		}
		
		//���ñ���
		res = (res+dfs(nx,ny,mx,cnt))%p;
		
	}
	return dp[x][y][mx][cnt] = res; 
}

int main()
{
	memset(dp,-1,sizeof dp);
	cin>>n>>m>>k;
	
	//��ʼ����ͼ
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
