//题目链接：https://www.lanqiao.cn/problems/3225/learning/?page=1&first_category_id=1&problem_id=3225 
#include <bits/stdc++.h>
using namespace std;
const int N = 1009;
int a[N];

int main()
{
  // 请在此输入您的代码
  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  int n;
  cin>>n;
  for(int i = 1;i<=n;i++)
  {
    cin>>a[i];
  }
  //i表示当前要确定的位置
	for(int i = n;i>=1;i--) 
	{
		//j从左往右扫
		for(int j = 1;j<i;j++) 
		{
			if(a[j] > a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
	
	//输出打印
	for(int i = 1;i<=n;i++) 
	{
		cout<<a[i]<<" \n"[i == n];
	}



  return 0;
}
