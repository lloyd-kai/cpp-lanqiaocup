//题目链接：https://www.lanqiao.cn/problems/1142/learning/?page=1&first_category_id=1&problem_id=1142 
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

  //先处理depl
  for(int i = 1;i<=n;i++)
  {
    //判断栈顶元素是否更差
    while(top && a[stk[top]]<=a[i])
    {
      top--;
    }
    dpl[i] = top?stk[top]:-1;
    stk[++top] = i;//存入下标
  }
  top = 0;

  //再处理dpr;
  for(int i = n;i>=1;i--)
  {
    //判断栈顶元素是否更差
    while(top && a[stk[top]] <=a[i])
    {
      top--;
    }
    dpr[i] = top?stk[top]:-1;
    stk[++top] = i;//存入下标
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
