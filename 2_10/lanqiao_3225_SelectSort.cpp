//��Ŀ���ӣ�https://www.lanqiao.cn/problems/3225/learning/?page=1&first_category_id=1&problem_id=3225 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+9;
int a[N];

int main()
{
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) 
	{
		cin>>a[i];
	}
	
	//i��ʾ��ǰҪȷ����λ��
	for(int i = 1;i<=n;i++) 
	{
		int min_id = i;//��ʼ��Ϊi
		//j��������ɨ���max_id
		for(int j = i;j<=n;j++) 
		{
			if(a[j] < a[min_id])
			{
				min_id = j;
			}
		}
		swap(a[min_id],a[i]);
	}
	
	//���������
	for(int i = 1;i<=n;i++) 
	{
		cout<<a[i]<<" \n"[i == n];
	}
} 
