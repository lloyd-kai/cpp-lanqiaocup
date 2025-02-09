#include<bits/stdc++.h>
using namespace std;

//快速排序算法实现

//分区函数
//将比pivot小的放在左边，大的放在右边 
int Partition(int a[],int l,int r) 
{
	//设a[r]为基准，这一次partition会将a[r]放到正确的位置上
	int pivot = a[r] ;
	//设两个下标i，j分别从l，r开始往中间走
	int i = l,j = r;
	while(i<j) 
	{
		while(i < j && a[i] <= pivot)
		{
			i++;
		}
		//从上面循环出来后有i>=j ,或者a[i]>pivot(说明找到了需要交换的位置)
		
		while(i < j && a[j] >= pivot) 
		{
			j--;
		}
		//从上面循环出来后有i>=j ,或者a[i]<pivot(说明找到了需要交换的位置)
		 
		//如果i<j说明存在a[j]<pivot 否则就是a[r]<=pivot ,a[i]>=pivot
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


//和归并排序不同的是只需要将两个排完序的数组直接前后拼接即可 
//不过要求左边的数组所有元素均小于右边的最小的元素 
void QuickSort(int a[],int l,int r)
{
	if(l<r)
	{
		int mid = Partition(a,l,r);
		QuickSort(a,l,mid-1);
		QuickSort(a,mid+1,r);
	}
}


