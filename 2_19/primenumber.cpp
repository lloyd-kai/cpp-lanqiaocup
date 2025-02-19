#include <iostream>
using namespace std;

//判定一个数是素数还是质数
bool isPrime(int n)
{
	if (n < 2)
	{
		return false;
	}
	for (int i = 2; i <= n / i; i++)
	{
		if (n % i == 0)
		{
			return false;//i<=n/i等价于i<=sqrt(n)这样就可以防止溢出 
		}
	}
	return true;
}


int main()
{
	int num;
	cin >> num;
	if (isPrime(num))
	{
		cout << "是素数" << endl;
	}
	else
	{
		cout << "不是素数" << endl;
	}
}

