//��Ŀ���ӣ�https://www.lanqiao.cn/problems/3225/learning/?page=1&first_category_id=1&problem_id=3225 
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
  //����ʹ�ò�������ķ���ʵ��
  //i��ʾ��ǰҪȷ����λ��
  for(int i = 2;i<=n;i++)
  {
    //��ʱ[1,i-1]�Ѿ�Ϊ���������
    int val = a[i],j;
    //��val��a[j-1]�Ƚ�,���С�ڵĻ��ͽ�a[j-1]���ƶ�һ��,��val�ṩλ��
    for(j = i;j>1 && val <a[j-1];j--)
    {
      a[j] = a[j-1];
    }
    //��ѭ������ʱ��j=1����val>=a[j]����ʱa[j]�Ѿ������ƶ�,jΪ��val�ճ�����λ��
    a[j] = val;
  }

  for(int i  =1;i<=n;i++)
  {
    //���ﵱi!=nʱΪ0����ʱ������ǿո񣬵�i==nʱ������У������ͼ����˴�����
    cout<<a[i]<<" \n"[i==n];
  }
  
  return 0;
}
