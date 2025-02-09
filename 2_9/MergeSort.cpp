#include<bits/stdc++.h>
using namespace std;

//归并排序算法实现

//a为要排序的数组，l、r为 区间的左右端点 
void MergeSort(int a[],int l,int r) 
{
	//当递归到子数组大小为1时停止排序 
	if(l == r)return;
	
	int mid = (l+r)/2;
	//左右部分分别递归排序 
	MergeSort(a,l,mid);
	MergeSort(a,mid+1,r);
	
	//排序完后a[l,mid]和[mid+1,r]都是有序的
	
	//将两个排序后的数组合并放入b
	//pl是左半边指向要比较的数的下标，pr是右半边指向要比较的数的下标，pb是b中指向要插入位置的下标 
	//注意这里pl是l而不是简单的1，后面复制的时候也是这样 
	int pl = l,pr = mid+1,pb=l;
	while(pl <=mid || pr<=r) 
	{
		if(pl>mid)
		{
			//左边数组已经放完
			b[pb++] =a[pr++];
		}
		else if(pr > r) 
		{
			//右半边已经放完
			b[pb++] = a[pl++];
		}
		else
		{
			//两边都还有元素，就比较并将小的放在b数组
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
	//完成后复制回原数组
	for(int i = l;i<=r;i++) 
	{
		a[i] = b[i];
	}
}
