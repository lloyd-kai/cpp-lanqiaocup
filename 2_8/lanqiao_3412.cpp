//��Ŀ���ӣ�https://www.lanqiao.cn/problems/3412/learning/?page=1&first_category_id=1&problem_id=3412 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int a[N];


int main()
{
  int n;
  cin>>n;

  //��ʼ������
  for(int i = 1;i<=n;i++)
  {
    cin>>a[i];
  }

  //��ʼ̰��
  //�Ȱ���ս��������������
  sort(a+1,a+1+n);
  //Ȼ����м���һ������ߵĸ�a���ұߵĸ�b������ս���������м�λ������ս���Ĳ�ֵ
  //��ʹ��ö�ٵ��㷨˼�룬�ҵ���Сֵ����
  int ans = a[2]-a[1];
  for(int i = 1;i<n;i++)
  {
    ans = min(ans,a[i+1]-a[i]);//ע�ⲻҪ����a[0],��Ϊ��û�г�ʼ��
  }
  cout<<ans;


  return 0;
}
