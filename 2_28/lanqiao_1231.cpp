//ÌâÄ¿Á´½Ó£ºhttps://www.lanqiao.cn/problems/1231/learning/?page=1&first_category_id=1&problem_id=1231 
#include <bits/stdc++.h>
using namespace std;

double dist(double x1,double y1,double x2,double y2)
{
  double dx = x1-x2,dy = y1-y2;
  return sqrt(dx*dx+dy*dy);
}

void solve()
{
  double x1,y1,x2,y2,x3,y3;
  cin>>x1>>y1>>x2>>y2>>x3>>y3;

  long double a = dist(x1,y1,x2,y2);
  long double b = dist(x1,y1,x3,y3);
  long double c = dist(x2,y2,x3,y3);
  long double p = (a+b+c)/2;

  long double ans = sqrt(p*(p-a)*(p-b)*(p-c));
  cout<<fixed<<setprecision(2)<<ans<<'\n';
}

int main()
{
  int num;
  cin>>num;
  while(num--)
  {
    solve();
  }
  return 0;
}
