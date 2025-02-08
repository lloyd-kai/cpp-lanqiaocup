//题目链接：https://www.lanqiao.cn/problems/3225/learning/?page=1&first_category_id=1&problem_id=3225 
#include <bits/stdc++.h>
using namespace std;
const int N = 1009;
int a[N];
int main()
{
  int n;
  cin>>n;
  for(int i = 1;i<=n;i++)
  {
    cin>>a[i];
  }
  //这里使用插入排序的方法实现
  //i表示当前要确定的位置
  for(int i = 2;i<=n;i++)
  {
    //此时[1,i-1]已经为有序的数组
    int val = a[i],j;
    //将val与a[j-1]比较,如果小于的话就将a[j-1]后移动一格,给val提供位置
    for(j = i;j>1 && val <a[j-1];j--)
    {
      a[j] = a[j-1];
    }
    //当循环跳出时，j=1或者val>=a[j]，此时a[j]已经往后移动,j为给val空出来的位置
    a[j] = val;
  }

  for(int i  =1;i<=n;i++)
  {
    //这里当i!=n时为0，此时输出的是空格，当i==n时输出换行，这样就减少了代码量
    cout<<a[i]<<" \n"[i==n];
  }
  
  return 0;
}
