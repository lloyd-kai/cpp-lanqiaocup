#include <bits/stdc++.h> 
using namespace std;

//�ж��Ƿ�������
bool isPrime(int n) 
{
	for(int i = 2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}

//��С������ 
int SmallNum(int a,int b) 
{
	for(int i = 1;i<=1000;i++)
	{
		if(a*i%b == 0)
		{
			return a*i;
		} 
	}
	return 0;
}


//��һ��
void Problem1(void) 
{
	for(int i = 2023;i>=2;i--)
	{
		if(isPrime(i))
		{
			if(2024%i == 0) 
			{
				cout<<i;
				break;
			}
		} 
	}
}

//������
void Problem3(void) 
{
	int sum = 0; 
	for(int i = 2023;i>=2;i--)//�Ӹߵ��������������� 
	{
		if(isPrime(i))
		{
			if(2024%i == 0) 
			{
				sum+=i;
			}
		} 
	}
	cout<<sum; 
}

//������ ��������
void Problem4(void) 
{
	for(int i = 2023;i>=2;i--)
	{
		if(isPrime(i))
		{
			cout<<i; 
			break;
		}
	}
}

//������ ��������
//��һ����ʽ�ģ��������е�����?�n? 
int Problem5(void) 
{
	
	int res = 0;
	int i = 1;
	while(res !=2024)
	{
		if(2024%i == 0||i%2024 == 0)
		{
			i++;
			continue;
		}
		res++;
		i++;
	}
	return i-1;
} 

//������ �ַ���ƥ��
string Find(void)
{
	string s = "ANQNANBNQNANQNQNBNINQNQNANQNINANQNANBNQNANQNQNBNBNQNQNANQNINANQNANBNQNANQNQNBNINQNQNANQNINBNQNANBNQN";
	int max = 0;
	string res = "";
	for(int i = 1;i<=10;i++)
	{
		for(int j=0;j<s.size();j++)
		{
			string s1 = s.substr(j,j+i);//��ȡ�Ӵ� 
			int count = s.find(s1);
			if(i*count>=max)
			{
				res = s1;
			}
		}
	}
	return res;
}


//������ �������⡪��dp  ��̬�滮



//int main()
//{
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	
//	//��һ��
////	Problem1(); 
//	
//	//�ڶ��� 
//	//int res = SmallNum(2024,1024);
//	//cout<<res;
//	
//	//������
////	Problem3();
//
//	//������
//	Problem4();
//		
//	return 0;
//}
