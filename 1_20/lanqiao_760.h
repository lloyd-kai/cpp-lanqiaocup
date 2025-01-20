#pragma once
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//这里的N是树的节点数
const int N = 20;
int a[N];

//这里实现的思路和深度优先遍历非常相似
int dfs(int dep)
{
  int res = 1;//返回结果至少是一个
  for(int i = 1;i<=a[dep-1]/2;i++)
  {
    a[dep] = i;//从1开始遍历到n的一半并将其作为树的节点值
    res+= dfs(dep+1);//对树的节点值递归找到其子树的个数
  }
  return res;//返回总数
}

void Test_760(void)
{
  int n = 0;
  cin>>n;
  a[1] = n;//先初始化树的根节点值
  cout<<dfs(2)<<endl;//然后递归后面的节点并求出值
}

