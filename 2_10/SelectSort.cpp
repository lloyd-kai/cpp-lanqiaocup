#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+9;
int a[N];


//ע��������������Ľ���Ǵ�С����
int main()
{
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) 
	{
		cin>>a[i];
	}
	
	//i��ʾ��ǰҪȷ����λ��
	for(int i = n;i>=1;i--) 
	{
		int max_id = 1;//��ʼ��Ϊ1
		//j��������ɨ���max_id
		for(int j = 1;j<=i;j++) 
		{
			if(a[j] > a[max_id])
			{
				max_id = j;
			}
		}
		swap(a[max_id],a[i]);
	}
	
	//���������
	for(int i = 1;i<=n;i++) 
	{
		cout<<a[i]<<" \n"[i == n];
	}
} 
