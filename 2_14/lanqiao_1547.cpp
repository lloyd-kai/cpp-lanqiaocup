#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int dp[N][N],w1[30],w2[30];
int main()
{
  int n,m;cin>>m>>n;//������m�����࣬n�ǳ���
  string s;cin>>s;
  for(int i = 1;i <= m; i++){
    char ch;cin >> ch;
    cin>> w1[ch-'a'] >> w2[ch-'a'];//������ɾ��ĸ����Ҫ�Ļ���
  }

  for(int len = 2 ;len <= n; len++){//ö������
    for(int i = 0;i + len - 1 <n; i++){//ö����˵�
      int j = i + len - 1;//������˵��Ƴ��Ҷ˵�
      if(s[i] == s[j]){
        if(len==2) dp[i][j]=0;
        else dp[i][j]=dp[i + 1][j - 1];
      }else {
      dp[i][j]=min(dp[i + 1][j] + min(w1[s[i] - 'a'],w2[s[i] - 'a']),
      dp[i][j - 1] + min(w1[s[j] - 'a'],w2[s[j] - 'a']));
    }
    }
  }
  cout<<dp[0][n-1]<<'\n';
  return 0;
}
