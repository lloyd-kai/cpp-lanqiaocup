#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
//����16�����ű�ģ�����������Ŀ�ĸ��˽�𣬹��Ժ����ѧϰ�Ͳ�©��ȱ 
//const int N = 1e5+7;//�ھ���Ĵ�С 

//�ڰ��� 
//int main()
//{
//	ll n,m,a;
//	cin>>n>>m>>a;
//	ll res = n*m*a;
//	cout<<res;
//	
//	return 0;
//} 

//�ھ��� 
//����һ����ǰ׺�� �������飬�ֱ��¼ǰһ�������ֵ��ǰ���������ֵ��ǰn�������ֵ
//int a[N] ;
//int pre[N];
//
//int main()
//{
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	int n;
//	cin>>n;
//	//�ȳ�ʼ����һ���� 
//	cin>>a[1];
//	pre[1] = a[1];
//	for(int i = 2;i<=n-1;i++)
//	{
//		cin>>a[i] ;
//		pre[i] = a[i]>pre[i-1]?a[i]:pre[i-1] ;//��ʼ��ǰ׺������ 
//	}
//	
//	int res = 1;//��һ��Ԫ��Ĭ�ϱ�֮ǰλ�ô�
//	for(int i = 2;i<=n;i++) 
//	{
//		if(a[i]>pre[i-1])
//		{
//			res++;
//		}
//	}
//	cout<<res;
//	
//	return 0; 
//} 

//��ʮ�� �ֵ���
//�Ƚ��ַ�������,��������С�ֵ�����ַ��� 
//string StrCompare(string s1,string s2) 
//{
//	if(s1.compare(s2)>0)
//	{
//		return s2;
//	}
//	return s1;
//}
//
//vector<string> Q;
//
//int main() 
//{
//	//��Ҫ��ʼ�ñ����㷨��:-) 
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	string s;
//	for(int i = 0;i<4;i++)
//	{
//		cin>>s;
//		Q.push_back(s);
//	}
//	
//	//��ʼ�Ƚϣ��ֵ���С�ķ���ǰ��
//	//�����õ���ð�������˼�� 
//	for(int i = 0;i<4;i++) 
//	{
//		for(int j = i+1;j<4;j++)
//		{
//			if(Q[i]>=Q[j])
//			{
//				string temp = Q[j];
//				Q[j] = Q[i];
//				Q[i] = temp;
//			}
//		}
//	}
//	string res;
//	for(int i = 0;i<4;i++)
//	{
//		res+=Q[i];
//	}
//	cout<<res<<'\n';
// 
//	return 0;
//}


//��ʮһ�� ˫ָ��
//const int N = 1e5+9;
//const int M = 1e5+9;
////���������������ֵ���� 
//int e[N];
//int v[M];
// 
// 
//int main()
//{
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	int n,m;
//	cin>>n;
//	for(int i = 1;i<=n;i++)
//	{
//		cin>>e[i];
//	}
//	cin>>m;
//	for(int i = 1;i<=m;i++)
//	{
//		cin>>v[i];
//	}
//	
//	//��ʼ��������,����˫ָ�� 
//	int p1 = 1;
//	int p2 = 1;
//	int res = 0;
//	while(p1<=n && p2<=m) 
//	{
//		if(v[p2]>=e[p1]) 
//		{
//			res++;
//			p1++;
//			p2++;
//		}
//		else
//		{
//			p2++;
//		}
//	}
//	cout<<res<<'\n';
//	
//	return 0;	
//} 

//12��ûʱ���� ����Ƕ�ά�����ǰ׺�Ͷ�̬�滮


//������
#include "code.h"
int main()
{
	string res = Find();
	cout<<res;
	return 0; 
} 


