//题目链接：https://www.lanqiao.cn/problems/1181/learning/?page=1&first_category_id=1&problem_id=1181
#include <iostream>
using namespace std;
typedef long long ll;

ll qmi(ll a,ll b,ll p)//对p求模
{
    ll res = 1;
    while(b)
    {
        if(b&1)
        {
            res = res*a%p;//b为奇数时，乘以一个a到答案里面
        }
        a=a*a%p;
        b>>=1;//底数平方，指数除以2

    }
    return res;
}

int main()
{
  int t;
  cin>>t;
  for(int i = 1;i<=t;i++)
  {
    ll n,m,p;
    cin>>n>>m>>p;
    cout<<qmi(n,m,p)<<'\n';
  }
  return 0;
} 
