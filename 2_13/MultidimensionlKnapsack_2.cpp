#include <iostream> 
#include <vector>
using namespace std;
#define maxn 110
int n, m, v[maxn], w[maxn],s[maxn];
int f[maxn];

//������Ʒ�Ľṹ��(������Ҳ����)
struct Goods
{
	int w, v;
};
vector<Goods>goods;

// �ڶ��ֶ��ر������㷨ʵ��
//���ö����Ƶķ���ʵ���Ż�(���罫7������110,����4��i��3��i ��Ҳ����7�� 
int main()
{
	//��ʼ������ 
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &v[i], &w[i], &s[i]);
		for (int k = 1; k <= s[i]; k++)
		{
			s[i] = k;
			goods.push_back({ w[i] * k, v[i] * k });
		}
		if (s[i] > 0)
		{
			goods.push_back({ s[i] * w[i],s[i] * v[i] });
		}
	}
	for (int i = 0; i < goods.size(); i++)
	{
		for (int j = m; j >= goods[i].w; j--)
		{
			f[j] = max(f[j], f[j - goods[i].w] + goods[i].v);
		}
	}

	cout << f[n] << endl;
	return 0;
}
