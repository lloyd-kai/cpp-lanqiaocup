//题目链接：https://www.lanqiao.cn/problems/3226/learning/?page=1&first_category_id=1&problem_id=3226 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int a[N];

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

  QuickSort(a,1,n);
  for(int i = 1;i<=n;i++)
  {
    cout<<a[i]<<" \n"[i == n];
  }



  return 0;
}
