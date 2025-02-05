//��������https://www.lanqiao.cn/problems/364/learning/?page=1&first_category_id=1&problem_id=364
#pragma once

#include<bits/stdc++.h>
using namespace std;
int l, n, m;  // l: ·�̵ĳ��ȣ�n: ʯ���������m: �����ߵ�ʯ������
const int N = 5e4+10;  
int a[N];  // �洢ʯ���λ��

// check ���������ж��ܷ�ʵ������Ϊ mid �������Ծ����
bool check(int mid) {
    int pos = 0;  // ��¼��ǰ��Ծ�����λ��
    int temp = m;  // ʣ��������ߵ�ʯ������
    // ��������ʯ��λ��
    for (int i = 1; i <= n + 1; i++) {
        if (temp < 0) break;  // ������ߵ�ʯ�������ѳ������ƣ�����ѭ��
        // �жϵ�ǰʯ�������ľ����Ƿ�С�� mid
        if (a[i] - pos < mid) {
            temp--;  // �����ǰʯ��λ������һ��ʯ��֮��ľ���С�� mid������һ��ʯ��
        } else {
            pos = a[i];  // ���������̾��룬������Ծ�����
        }
    }
    // ������������㹻���ʯ�飬���� true
    if (temp < 0) return true;
    return false;  // ���򷵻� false
}

int main() {
    cin >> l >> n >> m;  // ����·�̵ĳ��� l��ʯ������ n���Լ��������ߵ�ʯ������ m
    for (int i = 1; i <= n; i++) {
        cin >> a[i];  // ����ʯ���λ��
    }
    a[n + 1] = l;  // ���������յ�λ�ã���·�̵��ܳ���

    // ���ö��ֲ��ҵķ�Χ
    int L = 1, R = 1e9 + 10;
    // ���ֲ�����̵���Ծ����
    while (L < R) {
        int mid = (L + R + 1) / 2;  // ȡ�м�ֵ
        if (check(mid)) R = mid - 1;  // �������������Ծ����Ϊ mid������С��Χ
        else L = mid;  // ��������Χ
    }
    cout << R << endl;  // ������յ������Ծ����
    return 0;
}

