#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1100000;
int n, m, a[MAXN], cnt[MAXN], ans[MAXN], bel[MAXN], l = 1, r;

struct Node {
    int l, r, id;
} q[MAXN];

bool cmp(Node a, Node b) {
    if (bel[a.l] != bel[b.l]) {
        return bel[a.l] < bel[b.l];
    } else {
        return a.r < b.r;
    }
}

int res;
void add(int x) {
    cnt[a[x]]++;
    if (cnt[a[x]] == 1) {
        ++res;
    }
}

void del(int x) {
    --cnt[a[x]];
    if (cnt[a[x]] == 0) {
        --res;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int blockSize = sqrt(n);
    for (int i = 1; i <= ceil((double)n / blockSize); i++) {
        for (int j = (i - 1) * blockSize + 1; j <= min(n, i * blockSize); j++) {
            bel[j] = i;
        }
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    sort(q + 1, q + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        while (l < q[i].l) {
            del(l++);
        }
        while (l > q[i].l) {
            add(--l);
        }
        while (r < q[i].r) {
            add(++r);
        }
        while (r > q[i].r) {
            del(r--);
        }
        ans[q[i].id] = res;
    }
    for (int i = 1; i <= m; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
