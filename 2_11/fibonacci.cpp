#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p =1e7;
const int inf = 1e9,N = 1e5+3;

//����¼����
ll dp[N] ;

ll f(int n)
{
	if(n<=2) 
	{
		return 1;
	}
	//�������¼�������Ѿ���¼����Ӧ��ֵ
	if(dp[n]!=-1) 
	{
		return dp[n];
	}
	
	return dp[n] = (f(n-1)+f(n-2)) %p;
} 

int main()
{
	//��ʼ������¼��-1��ʾû�б���ʼ��
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	cout<<f(n)<<'\n';
	return 0;
}
