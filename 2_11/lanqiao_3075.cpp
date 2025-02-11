//��Ŀ���ӣ�https://www.lanqiao.cn/problems/3075/learning/?page=1&first_category_id=1&problem_id=3075
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+9;

//�����cnt�����źϷ��������θ�������ǰ׺���ҵ���Ӧ����Ϸ��������δ���
int n,cnt[N],prefix[N];

//mul�Ǳ߳˻���sum�ǳ�ȥ���һ����֮��
void dfs(int dep,int st,int mul,int sum)
{
  //��֦
  if(mul >1e5)
  {
    return;
  }

  if(dep == n+1)
  {
    cnt[mul]++;
    return;
  }

  //����ߵ�����
  int up = pow(1e5/mul,1.0/(n+1-dep))+3;

  //ö�����еı�
  for(int i = st+1;i<(dep == n?min(sum,up):up);i++)
  {
    dfs(dep+1,i,mul*i,sum+i);
  }
}


int main()
{
  int q;
  cin>>q>>n;
  dfs(1,0,1,0);
  for(int i = 1;i<=1e5;i++)
  {
    prefix[i] = prefix[i-1]+cnt[i];
  }

  
  while(q--)
  {
    int l,r;
    cin>>l>>r;
    cout<<prefix[r]-prefix[l-1]<<"\n";
  }
  return 0;
}
