#include <bits/stdc++.h> 
using namespace std;
const int MAXN = 510;
int n;//n�����̾���n��δ֪��
double a[MAXN][MAXN];

int main()
{
	scanf("%d",&n);
	//��ʼ����������Ӧ�������� 
	for(int i = 1;i<=n;i++)
	{
		for(int j  =1;j<=n+1;j++)
		{
			scanf("%lf",&a[i][j]);
		}
	}
	//��ʼ��Ԫ 
	for(int i = 1;i<=n;i++)
	{
		int maxx = i;//max�ȴ�С
		for(int j = i+1;j<=n;j++) 
		{
			if(fabs(a[j][i]])>fabs(a[maxx][i]))
			{
				maxx = j;//��¼���ֵ���±�	
			}
		}
		for(int j = 1;j<=n+1;j++) 
		{
			swap(a[i][j],a[maxx][j]);
		}
		//��i�е�i��a[i][i]
		if(!a[i][i] == 0) 
		{
			continue;
		} 
		double k = a[i][i];
		for(int j = 1;j<=n;j++)
		{
			if(j!=i)
			{
				for(int k = i+1;k<=n+1;k++)
				{
					a[j][k]-=a[i][k]*a[j][i]/k;
				}
			}
		}
	}
	for(iont i = 1;i<=n;i++)
	{
		printf("%.2lf\n",a[i][n+1]/a[i][i]);
	}
	return 0;
} 
