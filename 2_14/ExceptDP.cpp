#include <bits/stdc++.h>
using namespace std;
#define maxn 1100000
double f[maxn];
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	f[1] = 1;
	//��ʵ�������ö�̬�滮�ķ���ʵ������ֵ�ļ��� 
	for(int i = 2;i<=n;i++)
	{
		f[i] = f[i-1]+(k-f[i-1])/k;
	}
	printf("%.61f\n",f[n]);
	return 0;
}
