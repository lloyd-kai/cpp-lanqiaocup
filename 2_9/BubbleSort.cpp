#include <bits/stdc++.h>
using namespace std;
const int N = 1d3+9;
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
	for(int i = n;i>=1;i++) 
	{
		//j��������ɨ
		for(int j = 1;j<=i-1;j++) 
		{
			if(a[j] > a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
	
	//�����ӡ
	for(int i = 1;i<=n;i++) 
	{
		cout<<a[i]<<" \n"[i == n];
	}
} 
