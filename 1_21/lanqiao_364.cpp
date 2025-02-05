//例题链接https://www.lanqiao.cn/problems/364/learning/?page=1&first_category_id=1&problem_id=364
#pragma once

#include<bits/stdc++.h>
using namespace std;
int l, n, m;  // l: 路程的长度，n: 石块的数量，m: 可移走的石块数量
const int N = 5e4+10;  
int a[N];  // 存储石块的位置

// check 函数用来判断能否实现至少为 mid 的最短跳跃距离
bool check(int mid) {
    int pos = 0;  // 记录当前跳跃的起点位置
    int temp = m;  // 剩余可以移走的石块数量
    // 遍历所有石块位置
    for (int i = 1; i <= n + 1; i++) {
        if (temp < 0) break;  // 如果移走的石块数量已超过限制，结束循环
        // 判断当前石块与起点的距离是否小于 mid
        if (a[i] - pos < mid) {
            temp--;  // 如果当前石块位置与上一个石块之间的距离小于 mid，移走一个石块
        } else {
            pos = a[i];  // 如果满足最短距离，更新跳跃的起点
        }
    }
    // 如果可以移走足够多的石块，返回 true
    if (temp < 0) return true;
    return false;  // 否则返回 false
}

int main() {
    cin >> l >> n >> m;  // 输入路程的长度 l，石块数量 n，以及可以移走的石块数量 m
    for (int i = 1; i <= n; i++) {
        cin >> a[i];  // 输入石块的位置
    }
    a[n + 1] = l;  // 在最后加入终点位置，即路程的总长度

    // 设置二分查找的范围
    int L = 1, R = 1e9 + 10;
    // 二分查找最短的跳跃距离
    while (L < R) {
        int mid = (L + R + 1) / 2;  // 取中间值
        if (check(mid)) R = mid - 1;  // 如果可以满足跳跃距离为 mid，则缩小范围
        else L = mid;  // 否则增大范围
    }
    cout << R << endl;  // 输出最终的最短跳跃距离
    return 0;
}

