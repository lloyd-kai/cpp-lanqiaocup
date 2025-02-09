//��Ŀ���ӣ�https://www.lanqiao.cn/problems/3226/learning/?page=1&first_category_id=1&problem_id=3226 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int a[N];

//��������
//����pivotС�ķ�����ߣ���ķ����ұ� 
int Partition(int a[],int l,int r) 
{
	//��a[r]Ϊ��׼����һ��partition�Ὣa[r]�ŵ���ȷ��λ����
	int pivot = a[r] ;
	//�������±�i��j�ֱ��l��r��ʼ���м���
	int i = l,j = r;
	while(i<j) 
	{
		while(i < j && a[i] <= pivot)
		{
			i++;
		}
		//������ѭ����������i>=j ,����a[i]>pivot(˵���ҵ�����Ҫ������λ��)
		
		while(i < j && a[j] >= pivot) 
		{
			j--;
		}
		//������ѭ����������i>=j ,����a[i]<pivot(˵���ҵ�����Ҫ������λ��)
		 
		//���i<j˵������a[j]<pivot �������a[r]<=pivot ,a[i]>=pivot
		if(i<j) 
		{
			swap(a[i],a[j]);
		}
		else
		{
			swap(a[i],a[r]);
		}
		
	}
	return i;
}


//�͹鲢����ͬ����ֻ��Ҫ�����������������ֱ��ǰ��ƴ�Ӽ��� 
//����Ҫ����ߵ���������Ԫ�ؾ�С���ұߵ���С��Ԫ�� 
void QuickSort(int a[],int l,int r)
{
	if(l<r)
	{
		int mid = Partition(a,l,r);
		QuickSort(a,l,mid-1);
		QuickSort(a,mid+1,r);
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

  QuickSort(a,1,n);
  for(int i = 1;i<=n;i++)
  {
    cout<<a[i]<<" \n"[i == n];
  }



  return 0;
}
