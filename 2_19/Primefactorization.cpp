#include <bits/stdc++.h> 
using namespace std;
const int N = 2e5+9;

vector<pair<int,int>>v;

int main()
{
	int x;
	cin>>x;
	//ö�����п��ܵ�������
	for(int i = 2;i<=x/i;i++) 
	{
		//�����������ֱ������
		if(x%i) 
		{
			continue;
		}
		//���������������ô��Ȼ��һ��������
		
		//cnt��ʾ���װ����������i��ָ��
		int cnt = 0;
		//һֱ����ֱ�����ɾ�
		while(x%i == 0) 
		{
			cnt++;
			x/=i;
		}	
	}
	if(x>1)
	{
		v.push_back({x,1});
	}
	for(const auto i:v)
	{
		cout<<i.first<<' '<<i.second<<endl;
	}
	return 0;
}
