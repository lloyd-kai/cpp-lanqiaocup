//��Ŀ���ӣ�https://www.lanqiao.cn/problems/3226/learning/?page=1&first_category_id=1&problem_id=3226 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int a[N],b[N];

//aΪҪ��������飬l��rΪ ��������Ҷ˵� 
void MergeSort(int a[],int l,int r) 
{
	//���ݹ鵽�������СΪ1ʱֹͣ���� 
	if(l == r)return;
	
	int mid = (l+r)/2;
	//���Ҳ��ֱַ�ݹ����� 
	MergeSort(a,l,mid);
	MergeSort(a,mid+1,r);
	
	//�������a[l,mid]��[mid+1,r]���������
	
	//����������������ϲ�����b
	//pl������ָ��Ҫ�Ƚϵ������±꣬pr���Ұ��ָ��Ҫ�Ƚϵ������±꣬pb��b��ָ��Ҫ����λ�õ��±� 
	int pl = l,pr = mid+1,pb=l;
	while(pl <=mid || pr<=r) 
	{
		if(pl>mid)
		{
			//��������Ѿ�����
			b[pb++] =a[pr++];
		}
		else if(pr > r) 
		{
			//�Ұ���Ѿ�����
			b[pb++] = a[pl++];
		}
		else
		{
			//���߶�����Ԫ�أ��ͱȽϲ���С�ķ���b����
			if(a[pl]<a[pr]) 
			{
				b[pb++] = a[pl++];
			}
			else
			{
				b[pb++] = a[pr++];
			}
		}
		
	}
	//��ɺ��ƻ�ԭ����
	for(int i = l;i<=r;i++) 
	{
		a[i] = b[i];
	}
}



int main()
{
  // ���ڴ��������Ĵ���
  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  int n;
  cin>>n;
  for(int i = 1;i<=n;i++)
  {
    cin>>a[i];
  }

  MergeSort(a,1,n);
  for(int i = 1;i<=n;i++)
  {
    cout<<a[i]<<" \n"[i == n];
  }

  return 0;
}
