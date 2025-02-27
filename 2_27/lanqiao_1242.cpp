//ÌâÄ¿Á´½Ó£ºhttps://www.lanqiao.cn/problems/1242/learning/?page=1&first_category_id=1&problem_id=1242 
#include<bits/stdc++.h>
using namespace std;
double eps=1e-8;
void solve()
{
  double x1,y1,x2,y2,x3,y3;cin>>x1>>y1>>x2>>y2>>x3>>y3;
  double k=(y3-y2)/(x3-x2);
  double b=y2-k*x2;
  if(fabs(y1-k*x1-b)<eps)
  cout<<"Yes"<<'\n';
  else
  cout<<"No"<<'\n';
}
int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int num;cin>>num;
  while(num--)
  {
    solve();
  }
  return 0;
}
