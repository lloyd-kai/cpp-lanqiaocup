//ÌâÄ¿Á´½Ó£»https://www.lanqiao.cn/problems/1240/learning/?page=1&first_category_id=1&problem_id=1240 
#include<bits/stdc++.h>
using namespace std;
double eps=1e-8;
void solve()
{
  double x1,y1,x2,y2,x3,y3;
  cin>>x1>>y1>>x2>>y2>>x3>>y3;
  double a=x2-x1,a1=y2-y1;
  double b=x3-x1,b1=y3-y1;
  double ans=a1*b-a*b1;
  if(ans==0)
  cout<<"IN"<<'\n';
  if(ans>0)
  cout<<"R"<<'\n';
  if(ans<0)
  cout<<"L"<<'\n';
}
int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int _;cin>>_;
  while(_--)
  {
    solve();
  }
  return 0;
}
