//ÌâÄ¿Á´½Ó£ºhttps://www.lanqiao.cn/problems/2490/learning/?page=1&first_category_id=1&problem_id=2490
#include <iostream>
using namespace std;
const int N = 105;
char stk[N];
int top;
char s[N];

int main()
{
  int n;
  cin>>n;
  cin>>s+1;
  for(int i = 1;i<=n;i++)
  {
    if(s[i] == ')')
    {
      if(top && stk[top] == '(')
      {
        top --;
        continue;
      }
    }
    stk[++top] = s[i];
  }
  if(top)
  {
    cout<<"No"<<'\n';
  }
  else
  {
    cout<<"Yes"<<'\n';
  }
}
