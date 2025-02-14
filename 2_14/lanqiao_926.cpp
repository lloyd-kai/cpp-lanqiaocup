//��Ŀ���ӣ�https://www.lanqiao.cn/problems/926/learning/?page=1&first_category_id=1&sort=difficulty&asc=1&problem_id=926
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 57;

int main()
{
  string s;
  int f[MAXN][MAXN];
  cin>>s;
  int n = s.size();
  memset(f,127,sizeof(f));//��f��ʼ��Ϊ����ֵ
  for(int i = 0;i<n;i++)
  {
    f[i][i] = 1;//����l=r
  }
  for(int len = 2;len<=n;len++)
  {
    for(int i = 0;i+len-1<n;i++)
    {
      int j = i+len-1;
      if(s[i] == s[j])//����˵���ɫ��ͬ
      {
        f[i][j] = min(f[i+1][j],f[i][j-1]);
      }
      else //����˵���ɫ��ͬ
      {
        for(int k = i;k<i+len-1;k++)
        {
          f[i][j] = min(f[i][j],f[i][k]+f[k+1][j]);
        }
      }
    }
  }
  cout<<f[0][n-1];
  return 0;
}
 
