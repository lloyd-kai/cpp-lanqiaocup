#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p =1e7;
const int inf = 1e9,N = 1e5+3;

//备忘录数组
ll dp[N] ;

ll f(int n)
{
	if(n<=2) 
	{
		return 1;
	}
	//如果备忘录数组中已经记录过对应的值
	if(dp[n]!=-1) 
	{
		return dp[n];
	}
	
	return dp[n] = (f(n-1)+f(n-2)) %p;
} 

int main()
{
	//初始化备忘录，-1表示没有被初始化
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	cout<<f(n)<<'\n';
	return 0;
}
