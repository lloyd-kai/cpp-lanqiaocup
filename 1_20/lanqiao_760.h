#pragma once
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//�����N�����Ľڵ���
const int N = 20;
int a[N];

//����ʵ�ֵ�˼·��������ȱ����ǳ�����
int dfs(int dep)
{
  int res = 1;//���ؽ��������һ��
  for(int i = 1;i<=a[dep-1]/2;i++)
  {
    a[dep] = i;//��1��ʼ������n��һ�벢������Ϊ���Ľڵ�ֵ
    res+= dfs(dep+1);//�����Ľڵ�ֵ�ݹ��ҵ��������ĸ���
  }
  return res;//��������
}

void Test_760(void)
{
  int n = 0;
  cin>>n;
  a[1] = n;//�ȳ�ʼ�����ĸ��ڵ�ֵ
  cout<<dfs(2)<<endl;//Ȼ��ݹ����Ľڵ㲢���ֵ
}

