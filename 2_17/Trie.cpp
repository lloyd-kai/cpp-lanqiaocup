#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+9;

void insert(char s[]) //����Ϊn���ַ���s���뵽trie�� 
{
	int n = strlen(s+1);
	int x = 1;//��1��ʼ��������
	for(int i = 1;i<=n;i++) 
	{
		//�ȼ��x�Ƿ����s[i]�ı�
		if(!nex[x][s[i]-'a']]) 
		{
			nex[x][s[i]-'a']] = idx++;
		}
		x = nex[s][s[i]-'a']];//x�ƶ����µ��� 
	}
	cnt[x]++;
}

int check(char s[]) 
{
	int n = strlen(s+1);
	int x = 1;
	for(int i = 1;i<=n;i++)
	{
		x = nex[x][s[i]-'a'];
	} 
	return cnt[x];
} 



int main()
{
	int nex[N][27];//nex[i][0]��ʾ�ӽڵ��������Ϊa����һ���ڵ��ַ
	int cnt[N] ;//cnt[i]��ʾ�Խڵ�i��β���ַ�������
	int idx = 2;//�ڴ�أ����ﶯ̬����
	//��ʼʱ��ֻ��һ���ڵ�1��Ϊ���ڵ� 
}
