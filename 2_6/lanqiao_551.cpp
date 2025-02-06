//��Ŀ���ӣ�https://www.lanqiao.cn/problems/551/learning/?page=1&first_category_id=1&problem_id=551
#pragma once 
#include <iostream>
using namespace std;
const int N = 120;
//a�ǹ��ǰһ���ӵ����飬b�ǹ�Ⱥ�����飬ÿ�ι�ȵ�ʱ����b�滻aʵ�ָ���
bool a[N][N],b[N][N];


int main()
{
  //��ʼ������
  int n,m;
  cin>>n>>m;
 
 int t;
 cin>>t;
 //��¼ˮ�ܵ�λ��
 for(int i = 1;i<=t;i++)
 {
   int x,y;
   cin>>x>>y;
   a[x][y] =1;
 }

 //��ʼ���
 int k;
 cin>>k;
 while(k--)
 {
   for(int i = 1;i<=n;i++)
   {
     for(int j = 1;j<=m;j++) //��ʼ���
     {
       if(a[i][j])
       {
         b[i][j] = b[i - 1][j] = b[i + 1][j] = b[i][j - 1] =b[i][j + 1] = 1;
       }
     }
   }

   //���֮��b�滻a
   for(int i = 1;i<=n;i++)
   {
     for(int j = 1;j<=m;j++)
     {
       a[i][j] = b[i][j];
     }
   }
 }

 //������
 int ans = 0;
 for(int i =1;i<=n;i++)
 {
   for(int j = 1;j<=m;j++)
   {
     if(a[i][j])
     {
       ans++;
     }
   }
 }

 cout<<ans;


  return 0;
}
