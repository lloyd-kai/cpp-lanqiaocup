#include <iostream>
#include <vector>

using namespace std;

// 欧拉筛选法求区间 [a, b] 内的质数个数
int countPrimesInRange(int a, int b) {
    if (b < 2) return 0; // 如果 b 小于 2，没有质数

    // 初始化标记数组，isPrime[i] 为 true 表示 i 是质数
    vector<bool> isPrime(b + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 和 1 不是质数

    // 欧拉筛选法
    for (int i = 2; i <= b; ++i) {
        if (isPrime[i]) {
            // 将 i 的倍数标记为非质数
            for (int j = 2 * i; j <= b; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // 统计区间 [a, b] 内的质数个数
    int count = 0;
    for (int i = a; i <= b; ++i) {
        if (isPrime[i]) {
            ++count;
        }
    }

    return count;
}

int main() {
    int a, b;
    cout << "请输入区间的起始值 a 和结束值 b: ";
    cin >> a >> b;

    int primeCount = countPrimesInRange(a, b);
    cout << "区间 [" << a << ", " << b << "] 内的质数个数为: " << primeCount << endl;

    return 0;
}
