#include<bits/stdc++.h>
using namespace std;

//�鲢�����㷨ʵ��

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
	//ע������pl��l�����Ǽ򵥵�1�����渴�Ƶ�ʱ��Ҳ������ 
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
