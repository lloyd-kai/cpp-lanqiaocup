//��Ŀ���ӣ� https://www.lanqiao.cn/problems/1314/learning/?page=1&first_category_id=1&problem_id=1314
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+7;
int n;
int bucket[MAXN];//һ��ֵ��Ӧһ��Ͱ
int main()
{
	cin>>n;
	for(int i = 1;i<=n;i++)	
	{
		int x;
		cin>>x;
		bucket[x++];//����ÿ��ֻ��һ��ֵ�����ǿ����ж����ֵͬ����������ֻ��Ҫ��¼Ԫ�ظ������� 
	}
	for(int i = 0;i<=n;i++)
	{
		for(int j = 1;j<= bucket[i];j++) // ֵΪi��Ԫ����bucket[i]�� 
		{
			cout<<i<<" ";
		}
	}
} 
