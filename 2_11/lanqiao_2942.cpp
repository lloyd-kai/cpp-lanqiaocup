//��Ŀ���ӣ�https://www.lanqiao.cn/problems/2942/learning/?page=1&first_category_id=1&problem_id=2942 
#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int a[N],n;

//�洢ÿһ��ѧ���Ķ�ά����
vector<int> v[N];

//cnt��ʾ�����������dfs������cnt�������������Ƿ���Գɹ�����
bool dfs(int cnt,int dep)
{
  if(dep == n+1)
  {
    return true;
  }

  //ö��ÿ���������Ķ���
  for(int i = 1;i<=cnt;i++)
  {
    bool tag = true;

    //��Ϊ�����������һ����������������Ҫ����ǰ�����
    //������Ǽ�֦���֣�ͨ��Լ����������һ����ʱ�临�Ӷ�
    for(const auto &j:v[i])
    {
      //�Ƿ���ڱ�����ϵ
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
    //�ָ��ֳ�
    v[i].pop_back();
  }
  return false;
}


int main()
{
  cin>>n;
  //��ʼ������
  for(int i = 1;i<=n;i++)
  {
    cin>>a[i];
  }
  //��С��������
  sort(a+1,a+n+1);

  //��ʼö�ٿ��ܵķֶ���������һ�����������ľ������ٵĶ�����
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
