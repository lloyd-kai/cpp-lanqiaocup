//��Ŀ���ӣ�https://www.lanqiao.cn/problems/3225/learning/?page=1&first_category_id=1&problem_id=3225 
#include <bits/stdc++.h>
using namespace std;
const int N = 1009;
int a[N];

int main()
{
  // ���ڴ��������Ĵ���
  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  int n;
  cin>>n;
  for(int i = 1;i<=n;i++)
  {
    cin>>a[i];
  }
  //i��ʾ��ǰҪȷ����λ��
	for(int i = n;i>=1;i--) 
	{
		//j��������ɨ
		for(int j = 1;j<i;j++) 
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



  return 0;
}
