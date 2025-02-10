//��Ŀ���ӣ�https://www.lanqiao.cn/problems/182/learning/?page=1&first_category_id=1&problem_id=182 
#include <bits/stdc++.h> 
using namespace std;
const int N = 1e3+5;//����������

char mp[N][N];
int scc,n;//��ɫ��� 
int col[N][N];//��ɫ���� 

//��λ���飬����������������ܱ� 
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

//��¼��ɫ�Ƿ���ʧ(�൱�ڵ�����ʧ) ,���Ǿ�Ϊ0 
bool vis[N*N];

void dfs(int x,int y)
{
	col[x][y] = scc; 
	for(int i = 0;i<4;i++) 
	{
		int nx = x+dx[i],ny = y+dy[i];//�������ҵ�����
		if(col[nx][ny] || mp[nx][ny] == '.') 
		{
			continue;//�Ǻ�������� 
		}
		else
		{
			//������������
			dfs(nx,ny);
		} 
	}
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin>>n;
    //��ʼ����ͼ 
    for(int i = 1;i<=n;i++)
    {
    	cin>>mp[i]+1;
	}
	
	//��ʼ��������ɫ
	for(int i = 1;i<=n;i++) 
	{
		for(int j = 1;j<=n;j++)
		{
			if(col[i][j] || mp[i][j] == '.')
			{
				continue;//����Ǻ�������� 
			}
			else //�����½�ؾ����������Ƿ�������������½�� 
			{
				scc++;//��ǰ��ɫ�ı�� 
				
				dfs(i,j);
			} 
		}
	}
	
	int ans = 0;//δ����û�ĵ��� 
	
	//��ʼ��û
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			if(mp[i][j] == '.')
			{
				continue;
			}
			
			bool tag = true;
			//�ж������Ƿ��к���
			 for(int k = 0;k<4;k++) 
			{
				int x = i+dx[k],y = j+dy[k];//�������ҵ�����
				if(mp[x][y] == '.') 
				{
					tag = false;
				}
			}
			if(tag)
			{
				//������Ӧ��ɫ���� 
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
