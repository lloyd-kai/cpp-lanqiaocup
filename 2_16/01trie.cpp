#include <iostream>
using namespace std;
const int MAXN = 210000;
int a[MAXN], ch[MAXN][2], val[MAXN], n, ans, tot;

void insert(int x)
{
	int now = 0;
	for (int j = 31; j >= 0; j--)
	{
		int pos = ((x >> j) & 1);
		if (!ch[now][pos])
		{
			ch[now][pos] = ++tot;
		}
		now = ch[now][pos];
	}
	val[now];
}

int query(int x)
{
	int now = 0;
	for (int j = 31; j >= 0; j--)
	{
		int pos = ((x >> j) & 1);
		if (ch[now][pos ^ 1])
		{
			now = ch[now][pos ^ 1];
		}
		else
		{
			now = ch[now][pos];
		}
	}
	return val[now];
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = x;
		insert(x);
	}

	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, query(a[i]));
	}
	cout << ans;
	return 0;
}
