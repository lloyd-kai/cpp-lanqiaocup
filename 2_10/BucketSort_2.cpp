//��Ŀ���ӣ� https://www.lanqiao.cn/problems/1314/learning/?page=1&first_category_id=1&problem_id=1314
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+7;
int n;

vector<int> bucket[MAXN];
int main()
{
	cin>>n;
	for(int i = 1;i<=n;i++) 
	{
		int x;
		cin>>x;
		bucket[x/1000].push_back(x);
	}
	for(int i = 0;i<MAXN;i++)
	{
		//��ÿһ��Ͱ���򣬷�������
		sort(bucket[i]);
	}
	for(int i = 0;i<MAXN;i++)
	{
		for(auto item:bucket[i])
		{
			cout<<item<< " ";
		}
	}
} 
