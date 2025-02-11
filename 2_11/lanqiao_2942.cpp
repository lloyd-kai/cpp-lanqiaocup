//题目链接：https://www.lanqiao.cn/problems/2942/learning/?page=1&first_category_id=1&problem_id=2942 
#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int a[N],n;

//存储每一队学生的二维数组
vector<int> v[N];

//cnt表示队伍的数量，dfs返回在cnt个队伍的情况下是否可以成功分组
bool dfs(int cnt,int dep)
{
  if(dep == n+1)
  {
    return true;
  }

  //枚举每个人所属的队伍
  for(int i = 1;i<=cnt;i++)
  {
    bool tag = true;

    //因为排序过，所以一个队伍里面后面的数要大于前面的数
    //这里就是剪枝部分，通过约束条件减少一定的时间复杂度
    for(const auto &j:v[i])
    {
      //是否存在倍数关系
      if(a[dep]%j == 0)
      {
        tag = false;
        break;
      }
    }

    if(!tag)
    {
      continue;
    }

    v[i].push_back(a[dep]);
    if(dfs(cnt,dep+1))
    {
      return true;
    }
    //恢复现场
    v[i].pop_back();
  }
  return false;
}


int main()
{
  cin>>n;
  //初始化数组
  for(int i = 1;i<=n;i++)
  {
    cin>>a[i];
  }
  //从小到大排序
  sort(a+1,a+n+1);

  //开始枚举可能的分队数量，第一个符合条件的就是最少的队伍数
  for(int i = 1;i<=10;i++)
  {
    if(dfs(i,1))
    {
      cout<<i;
      break;
    }
  }

  return 0;
}
