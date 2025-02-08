//题目链接：https://www.lanqiao.cn/problems/545/learning/?page=1&first_category_id=1&problem_id=545 
#include <bits/stdc++.h>
using namespace std;
//思路很简单，就是每次合并最小的两个部落
//这里使用优先级队列实现，当然用栈或者数组多次遍历也是可以的,不过要先排序
typedef long long ll;

priority_queue<ll,vector<ll>,greater<ll>> pq;


int main()
{
  int n;
  cin>>n;
  //初始化优先级队列
  for(int i = 1;i<=n;i++)
  {
    ll x;
    cin>>x;
    pq.push(x);
  }

  //开始合并
  ll ans = 0;
  while(pq.size()>1)
  {
    //每次取出最小的两个数，然后合并后放回
    ll x = pq.top();
    pq.pop();
    ll y = pq.top();
    pq.pop();
    ans+=x+y;
    pq.push(x+y);
  }
  cout<<ans;

  return 0;
}
