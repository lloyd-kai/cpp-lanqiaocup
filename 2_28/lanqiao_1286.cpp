//ÌâÄ¿Á´½Ó£ºhttps://www.lanqiao.cn/problems/1286/learning/?page=1&first_category_id=1&problem_id=1286
#include <bits/stdc++.h>
using namespace std;

double dist(double x1,double y1,double x2,double y2)
{
  double dx =x1-x2, dy = y1-y2;
  return sqrt(dx*dx+dy*dy);
}

void solve()
{
  double xa,ya,xb,yb,xc,yc;
  cin>>xa>>ya>>xb>>yb>>xc>>yc;
  double xCA = xa-xc,yCA = ya-yc;
  double xCB = xb-xc,yCB = yb-yc;

  double ans = (xCA * yCB-xCB*yCA)/dist(xa,ya,xb,yb);
  cout<<fixed<<setprecision(2)<<ans<<'\n';
}


int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int num;
  cin>>num;
  while(num--)
  {
    solve();
  }
  return 0;
} 
