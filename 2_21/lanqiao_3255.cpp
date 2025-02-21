//��Ŀ���ӣ�https://www.lanqiao.cn/problems/3255/learning/?page=1&first_category_id=1&problem_id=3255 
#include <iostream>
using namespace std;
const int N = 2e5+9;
// e[i]��ʾ��ַΪi�Ľ���ϵ���һ�����ĵ�ַ���������±꣩��
//headһ����0,tailһ��������ĳ��ȣ�����һ���ڵ�ĵ�ַһ����-1 
int e[N],p[N];

void del(int x)
{
  if(e[x] == -1)
  {
    e[p[x]] = -1;
  }
  else
  {
    e[p[x]] = e[x];
    p[e[x]] = p[x];
  }
}

void insert_front(int y,int x)
{
  e[x] = y;
  p[x] = p[y];
  p[e[x]] = x;
  e[p[x]] = x;

}

void insert_back(int y,int x)
{
  if(e[y] == -1)
  {
    e[y] = x;
    p[x] = y;
    e[x] = -1;
  }
  else
  {
    e[x] = e[y];
    p[x] = y;
    e[y] = x;
    p[e[x]] = x;
  }
}


int main()
{
  int n,m;
  cin>>n>>m;
  for(int i = 1;i<=n;i++)
  {
    e[i] = i+1;
    p[i] = i-1;
  }
  e[0] = 1,e[n] = -1;

  for(int i = 1;i<=m;i++)
  {
    int x,y,z;
    cin>>x>>y>>z;
    if(z)
    {
      del(x);
      insert_front(y,x);
    }
    else
    {
      del(x);
      insert_back(y,x);
    }
  }
  
  for(int i = e[0];i!=-1;i =e[i])
  {
    cout<<i<<' ';
  }


  return 0;
}
