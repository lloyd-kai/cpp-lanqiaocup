#include <iostream>
const int N = 1e5, M = 1e5;

int main()
{
	char s[N], p[M];
	int nex[M];
	int n = strlen(s + 1), m = strlen(p + 1);
	nex[0] = nex[1] = 0;
	for (int i = 2, j = 0; i <= m; i++)
	{
		//不断匹配p[i]和p[j+1]
		while (j && p[i] != p[j + 1])
		{
			j = nex[j];
		}
		if (p[i] == p[j + 1])
		{
			j++;
		}//从while出来后要么j=0,要么p==plj+1,如果匹配成功，则j后移
		nex[i] = j;//i如果匹配失败就回到j,因为此时p1~j=pi-j+1~i或j0(回到最初的地方重新开始匹配
	}
	int ans = 0;
	for (int i = 1, j = 0; i <= n; i++)
	{
		while (j && s[i] != p[j + 1])
		{
			j = nex[j];
		}
		if (s[i] == p[j + 1])
		{
			j++;
		}
		if (j == m)
		{
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}
