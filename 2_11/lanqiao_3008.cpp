//��Ŀ���ӣ�https://www.lanqiao.cn/problems/3008/learning/?page=1&first_category_id=1&problem_id=3008 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+9;

//�����cnt�����źϷ��������θ�������ǰ׺���ҵ���Ӧ����Ϸ��������δ���
int cnt[N],prefix[N];

//mul�����߳˻���sum������֮��
void dfs(int dep,int st,int mul,int sum)
{
  //��֦
  if(mul >1e6)
  {
    return;
  }

  if(dep == 4)
  {
    cnt[mul]++;
    return;
  }

  //����ߵ�����
  int up = pow(1e6/mul,1.0/(4-dep))+3;

  //ö�����еı�
  for(int i = st+1;i<(dep == 3?sum:up);i++)
  {
    dfs(dep+1,i,mul*i,sum+i);
  }
}


int main()
{
  dfs(1,0,1,0);
  for(int i = 1;i<=1e6;i++)
  {
    prefix[i] = prefix[i-1]+cnt[i];
  }

  int q;
  cin>>q;
  while(q--)
  {
    int l,r;
    cin>>l>>r;
    cout<<prefix[r]-prefix[l-1]<<"\n";
  }
  return 0;
}
