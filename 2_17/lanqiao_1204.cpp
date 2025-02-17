//��Ŀ���ӣ�https://www.lanqiao.cn/problems/1204/learning/?page=1&first_category_id=1&problem_id=1204
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+9;

int nex[N][26];
int cnt[N];
int idx = 2;

void insert(char s[])
{
  int x = 1;
  for(int i = 0;s[i];i++)
  {
    //�ж�x�Ƿ����s[i]������
    if(!nex[x][s[i]-'a'])
    {
      nex[x][s[i]-'a'] = idx++;
    }
    x=  nex[x][s[i]-'a'];
  }
  cnt[x]++;
}

int check(char s[])
{
  int x = 1;
  for(int i = 0;s[i];i++)
  {
    x = nex[x][s[i]-'a'];
  }
  return x;
}


int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n,m;
  cin>>n>>m;
  //��ʼ���ֵ���
  for(int i = 1;i<=n;i++)
  {
    char s[N];
    cin>>s;
    insert(s);
  }
  for(int i = 1;i<=m;i++)
  {
    char s[N];
    cin>>s;
    cout<<(check(s)?"Y":"N")<<'\n';
  }
  return 0;
}

