//��Ŀ���ӣ�https://www.lanqiao.cn/problems/1331/learning/?page=1&first_category_id=1&problem_id=1331 
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int x;
  cin>>x;
  int ans = 0;
  while(x)
  {
  	//�ж����λ�Ƿ���1 
    if(x &1)
    {
      ans++;
    }
    //�ж��������һλ 
    x>>=1;
  }
  cout<<ans;
  return 0;
}
