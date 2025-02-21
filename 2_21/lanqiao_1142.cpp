//��Ŀ���ӣ�https://www.lanqiao.cn/problems/1142/learning/?page=1&first_category_id=1&problem_id=1142 
#include <iostream>
using namespace std;

const int N = 7e5+9;
int a[N],dpl[N],dpr[N];
int stk[N],top;

int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin>>n;
  for(int i = 1;i<=n;i++)
  {
    cin>>a[i];
  }

  //�ȴ���depl
  for(int i = 1;i<=n;i++)
  {
    //�ж�ջ��Ԫ���Ƿ����
    while(top && a[stk[top]]<=a[i])
    {
      top--;
    }
    dpl[i] = top?stk[top]:-1;
    stk[++top] = i;//�����±�
  }
  top = 0;

  //�ٴ���dpr;
  for(int i = n;i>=1;i--)
  {
    //�ж�ջ��Ԫ���Ƿ����
    while(top && a[stk[top]] <=a[i])
    {
      top--;
    }
    dpr[i] = top?stk[top]:-1;
    stk[++top] = i;//�����±�
  }

  for(int i = 1;i<=n;i++)
  {
    cout<<dpl[i]<<' ';
  }

  cout<<"\n";

  for(int i = 1;i<=n;i++)
  {
    cout<<dpr[i]<<' ';
  }
  return 0;
}
