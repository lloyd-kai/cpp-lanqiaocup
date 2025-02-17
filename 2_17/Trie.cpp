#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+9;

void insert(char s[]) //长度为n的字符串s插入到trie中 
{
	int n = strlen(s+1);
	int x = 1;//从1开始往下面走
	for(int i = 1;i<=n;i++) 
	{
		//先检查x是否存在s[i]的边
		if(!nex[x][s[i]-'a']]) 
		{
			nex[x][s[i]-'a']] = idx++;
		}
		x = nex[s][s[i]-'a']];//x移动到新点上 
	}
	cnt[x]++;
}

int check(char s[]) 
{
	int n = strlen(s+1);
	int x = 1;
	for(int i = 1;i<=n;i++)
	{
		x = nex[x][s[i]-'a'];
	} 
	return cnt[x];
} 



int main()
{
	int nex[N][27];//nex[i][0]表示从节点出发，边为a的下一个节点地址
	int cnt[N] ;//cnt[i]表示以节点i结尾的字符串数量
	int idx = 2;//内存池，用语动态开点
	//初始时，只有一个节点1作为根节点 
}
