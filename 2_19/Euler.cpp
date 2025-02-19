#include <iostream>
using namespace std;
const int MAXN = 1e5 + 7;
int vis[MAXN], isprime[MAXN];

int main()
{
	int n = 100;
	int cnt = 0;
	for (int i = 2; i <= n; i++)
	{
		if (!vis[i])
		{
			isprime[++cnt] = i;//存到质数表 
		}
		for (int j = 1; j <= cnt && isprime[j] * i <= n; j++)
		{
			vis[isprime[j] * i] = 1;
			if (i%isprime[j] == 0)
			{
				break;
			}
		}
	}
	for (int i = 1; i <= cnt; i++)
	{
		cout << isprime[i] << ' ';
	}

	return 0;
}
