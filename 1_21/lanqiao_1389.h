#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void Test_1389(void)
{
  //初始化
  int data[200];
  for(int i = 0;i<200;i++)
  {
    data[i] = 4*i+6;
  }

  // 用函数实现
  // 因为这里是找第一个数，可以直接用lower_bound函数找到最小值的下标 
  // int target = 0;
  // scanf("%d",&target);
  // cout<<(lower_bound(data,data+200,target)-data);

  //用二分法查找
  int left = 0;
  int right = 199;
  int target = 0;
  cin>>target;

  while(left<right)//这样表示是前开后闭 如果要全闭合就是left+1!=right 
  {
    int mid = left+(right-left)/2;//这样做的好处在于不会出现数组越界访问的问题
    
    /*
	这里就涉及到mid的选取和端点的移动，如果我将right作为答案，那么答案区间就是(left+1,right] ，返回的结果也要是right
	同理如果我让left作为答案，那么答案区间就是 (left,right-1],对吗？不对！
	因为我一开始就设置区间为前开后闭，相当于我默认了答案为right，如果用left作为答案会得不到正确结果 
	如果你用的区间是全闭合的，那么left作为答案，区间就是[left,right-1]，这就是对的 
	总而言之，就是你要选谁作为答案，以及使用哪一种区间，然后根据你的选择完善mid的选取，循环的终止条件，端点的移动等细节问题。 
	*/ 
    if(data[mid]>=target)
    {
      right = mid;
    }
    else 
    {
      left = mid+1; 
    }
  }
  cout<<right;
}
