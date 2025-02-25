#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110000;
int n, a[MAXN];
int blo, bl[MAXN], v[MAXN], add[MAXN];

void add1(int l, int r, int c) {
    for (int i = l; i <= min(bl[l] * blo, r); i++) {
        v[i] += c;
    }
    if (bl[l] != bl[r]) {
        for (int i = bl[l] + 1; i <= bl[r] - 1; i++) {
            add[i] += c;
        }
    }
    for (int i = (bl[r] - 1) * blo + 1; i <= r; i++) {
        v[i] += c;
    }
}

int main() {
    scanf("%d", &n);
    blo = sqrt(n); // 当成块的大小
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        v[i] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        bl[i] = (i - 1) / blo + 1;
    }
    for (int i = 1; i <= n; i++) {
        int op;
        scanf("%d", &op);
        if (op == 0) {
            int l, r, c;
            scanf("%d%d%d", &l, &r, &c);
            add1(l, r, c);
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", v[x] + add[bl[x]]);
        }
    }
    return 0;
}
