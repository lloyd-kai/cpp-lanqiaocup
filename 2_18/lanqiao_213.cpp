//题目链接：https://www.lanqiao.cn/problems/213/learning/?page=1&first_category_id=1&problem_id=213 
#include <iostream>
using namespace std;
int main()
{
  //对于互质(最大公约为1)的两个数p，q，px+py 不能表示的最大数为pq-p-q.
  int a,b;
  cin>>a;
  cin>>b;
  cout<<a * b - a - b; 
  return 0;
}
