#include <bits/stdc++.h> 
using namespace std;

//判断是否是质数
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

//最小公倍数 
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


//第一题
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

//第三题
void Problem3(void) 
{
	int sum = 0; 
	for(int i = 2023;i>=2;i--)//从高到低依次找质因数 
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

//第四题 最大的质数
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

//第五题 互质问题
//有一个公式的，但是我有点忘了?﹏? 
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

//第六题 字符串匹配
string Find(void)
{
	string s = "ANQNANBNQNANQNQNBNINQNQNANQNINANQNANBNQNANQNQNBNBNQNQNANQNINANQNANBNQNANQNQNBNINQNQNANQNINBNQNANBNQN";
	int max = 0;
	string res = "";
	for(int i = 1;i<=10;i++)
	{
		for(int j=0;j<s.size();j++)
		{
			string s1 = s.substr(j,j+i);//提取子串 
			int count = s.find(s1);
			if(i*count>=max)
			{
				res = s1;
			}
		}
	}
	return res;
}


//第七题 背包问题——dp  动态规划



//int main()
//{
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	
//	//第一题
////	Problem1(); 
//	
//	//第二题 
//	//int res = SmallNum(2024,1024);
//	//cout<<res;
//	
//	//第三题
////	Problem3();
//
//	//第四题
//	Problem4();
//		
//	return 0;
//}
