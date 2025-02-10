//题目链接：https://www.lanqiao.cn/problems/182/learning/?page=1&first_category_id=1&problem_id=182 
#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int N = 1e5+9;//定义最大深度

//n是图中的节点数，a[]存储每个节点指向的下一个节点，而dfn是记录节点被访问的顺序
//idx是生成的时间戳(节点被访问的顺序)，表示当前访问到第几个节点
//mindfn记录当前环的最小时间戳 
int n,a[N],dfn[N],idx,mindfn;

int dfs(int x)
{
	dfn[x] = ++idx;//当前节点赋予时间戳 
	
	if(dfn[a[x]]) //如果节点已被访问 
	{
		if(dfn[a[x]]>=mindfn)// 时间戳不小于当前环的最小时间戳 mindfn,构成环 
		{
			return dfn[x]-dfn[a[x]]+1;//返回环的长度 
		}
	}
	
	return dfs(a[x]);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
    	cin>>a[i];
	}
	
	int ans = 0;
	for(int i = 1;i<=n;i++)
	{
		if(!dfn[i])//如果时间戳没有被访问 
		{
			mindfn = idx+1;
			ans = max(ans,dfs(i));
		} 
	}
    
    cout<<ans<<"\n";
    return 0;
} 
