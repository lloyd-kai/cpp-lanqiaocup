//ʾ�����⣺��1-n��ȫ����
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
			cout<<a[i]<<" ";//�ݹ���ڣ���ǰ��ȳ����������ʱ 
		}
		cout<<"\n";
		return;
	}
	for(int i = 1;i<=n;i++) 
	{
		//�ų����Ϸ���·����Ҳ���Ǵ˽ڵ��Ѿ����ʹ�ʱ 
		if(vis[i]) 
		{
			continue;
		}
		
		//�޸�״̬
		vis[i] = true;
		a[dep] = i;
		
		//��һ��
		dfs(dep+1);
		
		//�ָ��ֳ�
		vis[i] = false;
		//a[dep] = 0����ʡ�� 
	}
}
