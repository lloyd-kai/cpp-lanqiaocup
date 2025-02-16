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
		//����ƥ��p[i]��p[j+1]
		while (j && p[i] != p[j + 1])
		{
			j = nex[j];
		}
		if (p[i] == p[j + 1])
		{
			j++;
		}//��while������Ҫôj=0,Ҫôp==plj+1,���ƥ��ɹ�����j����
		nex[i] = j;//i���ƥ��ʧ�ܾͻص�j,��Ϊ��ʱp1~j=pi-j+1~i��j0(�ص�����ĵط����¿�ʼƥ��
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
