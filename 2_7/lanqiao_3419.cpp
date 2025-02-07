//题目链接：https://www.lanqiao.cn/problems/3419/learning/?page=1&first_category_id=1&problem_id=3419 
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char s[N];
//用L映射为1，Q映射为-1，这样当区间和为0时，符合平衡串的要求
int prefix[N];

int main()
{
  cin>>s;
  int n = strlen(s+1);
  //初始化前缀和数组
  for(int i = 1;i<=n;i++)
  {
    prefix[i] = prefix[i-1]+(s[i] == 'L'?1:-1);
  }

  int ans = 0;
  //遍历所有的区间，看哪一部分符合条件的长度最大
  for(int i = 1;i<=n;i++)
  {
    for(int j = 1;j<=n;j++)
    {
      if(prefix[j]-prefix[i-1] == 0)
      {
        ans = max(ans,j-i+1);
      }
    }
  }
  cout<<ans;
  
  return 0;
}
