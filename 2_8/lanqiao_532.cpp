// ��Ŀ���ӣ�https://www.lanqiao.cn/problems/532/learning/?page=1&first_category_id=1&problem_id=532 
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+9;
int a[N];


int main()
{
  int w,n;
  cin>>w>>n;
  //��ʼ������
  for(int i = 1;i<=n;i++)
  {
    cin>>a[i];
  }

  //����
  sort(a+1,a+n+1);

  //����˫ָ��ʵ��̰��
  int ans = 0;
  int l = 1,r = n;
  while(l<=r)
  {
    if(a[l]+a[r]>w)
    {
      ans++;
      r--;
    }
    else
    {
      ans++;
      l++;
      r--;
    }
  }

  cout<<ans;
  return 0;
}
