#include <iostream>
#include <vector>

using namespace std;

// ŷ��ɸѡ�������� [a, b] �ڵ���������
int countPrimesInRange(int a, int b) {
    if (b < 2) return 0; // ��� b С�� 2��û������

    // ��ʼ��������飬isPrime[i] Ϊ true ��ʾ i ������
    vector<bool> isPrime(b + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 �� 1 ��������

    // ŷ��ɸѡ��
    for (int i = 2; i <= b; ++i) {
        if (isPrime[i]) {
            // �� i �ı������Ϊ������
            for (int j = 2 * i; j <= b; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // ͳ������ [a, b] �ڵ���������
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
    cout << "�������������ʼֵ a �ͽ���ֵ b: ";
    cin >> a >> b;

    int primeCount = countPrimesInRange(a, b);
    cout << "���� [" << a << ", " << b << "] �ڵ���������Ϊ: " << primeCount << endl;

    return 0;
}
