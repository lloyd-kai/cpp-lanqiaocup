//��Ŀ���ӣ�https://www.lanqiao.cn/problems/827/learning/?page=1&first_category_id=1&name=%E7%90%83%E5%BD%A2%E7%A9%BA%E9%97%B4
#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 510;
int n; // n�����̾���n��δ֪��
double a[MAXN][MAXN], ans[MAXN], c[MAXN][MAXN];

// ��˹��Ԫ��������Է�����
int solve(int n) {
    for (int i = 0; i < n; i++) {
        int r = i; // ��¼���ֵ���±�
        for (int j = i + 1; j < n; j++) {
            if (fabs(a[j][i]) > fabs(a[r][i])) {
                r = j; // ��¼���ֵ���±�
            }
        }
        if (fabs(a[r][i]) < 1e-8) {
            // ��ԪΪ0���������죬�޷�������Ԫ
            return -1; // ���ش�����
        }
        if (r != i) {
            for (int j = 0; j <= n; j++) {
                swap(a[i][j], a[r][j]);
            }
        }
        double div = a[i][i];
        for (int j = i; j <= n; j++) {
            a[i][j] /= div;
        }
        for (int j = i + 1; j < n; j++) {
            double factor = a[j][i];
            for (int k = i; k <= n; k++) {
                a[j][k] -= a[i][k] * factor;
            }
        }
    }
    ans[n - 1] = a[n - 1][n];
    for (int i = n - 2; i >= 0; i--) {
        ans[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            ans[i] -= a[i][j] * ans[j];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%.3lf ", ans[i]);
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 2 * (a[i][j] - a[i + 1][j]);
        }
        c[i][n] = 0;
        for (int j = 0; j < n; j++) {
            c[i][n] += a[i][j] * a[i][j] - a[i + 1][j] * a[i + 1][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            a[i][j] = c[i][j];
        }
    }
    int result = solve(n);
    if (result == -1) {
        printf("No unique solution exists.\n");
    }
    return 0;
} 
