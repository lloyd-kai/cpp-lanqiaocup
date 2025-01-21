#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void Test_1389(void)
{
  //��ʼ��
  int data[200];
  for(int i = 0;i<200;i++)
  {
    data[i] = 4*i+6;
  }

  // �ú���ʵ��
  // ��Ϊ�������ҵ�һ����������ֱ����lower_bound�����ҵ���Сֵ���±� 
  // int target = 0;
  // scanf("%d",&target);
  // cout<<(lower_bound(data,data+200,target)-data);

  //�ö��ַ�����
  int left = 0;
  int right = 199;
  int target = 0;
  cin>>target;

  while(left<right)//������ʾ��ǰ����� ���Ҫȫ�պϾ���left+1!=right 
  {
    int mid = left+(right-left)/2;//�������ĺô����ڲ����������Խ����ʵ�����
    
    /*
	������漰��mid��ѡȡ�Ͷ˵���ƶ�������ҽ�right��Ϊ�𰸣���ô���������(left+1,right] �����صĽ��ҲҪ��right
	ͬ���������left��Ϊ�𰸣���ô��������� (left,right-1],���𣿲��ԣ�
	��Ϊ��һ��ʼ����������Ϊǰ����գ��൱����Ĭ���˴�Ϊright�������left��Ϊ�𰸻�ò�����ȷ��� 
	������õ�������ȫ�պϵģ���ôleft��Ϊ�𰸣��������[left,right-1]������ǶԵ� 
	�ܶ���֮��������Ҫѡ˭��Ϊ�𰸣��Լ�ʹ����һ�����䣬Ȼ��������ѡ������mid��ѡȡ��ѭ������ֹ�������˵���ƶ���ϸ�����⡣ 
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
