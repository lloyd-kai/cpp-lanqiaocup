#include <iostream>
using namespace std;

//�ж�һ������������������
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
			return false;//i<=n/i�ȼ���i<=sqrt(n)�����Ϳ��Է�ֹ��� 
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
		cout << "������" << endl;
	}
	else
	{
		cout << "��������" << endl;
	}
}

