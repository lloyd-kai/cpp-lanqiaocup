//题目链接：https://www.lanqiao.cn/problems/3412/learning/?page=1&first_category_id=1&problem_id=3412 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int a[N];


int main()
{
  int n;
  cin>>n;

  //初始化数组
  for(int i = 1;i<=n;i++)
  {
    cin>>a[i];
  }

  //开始贪心
  //先按照战力进行升序排序
  sort(a+1,a+1+n);
  //然后从中间切一刀，左边的给a，右边的给b，这样战力差距就是中间位置两侧战力的差值
  //再使用枚举的算法思想，找到最小值即可
  int ans = a[2]-a[1];
  for(int i = 1;i<n;i++)
  {
    ans = min(ans,a[i+1]-a[i]);//注意不要包括a[0],因为其没有初始化
  }
  cout<<ans;


  return 0;
}
