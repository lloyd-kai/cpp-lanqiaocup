#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll base = 233, mod = 998244353;
const int MAXN = 2000005;
ll bs[MAXN] = {1};
string a;
int n, q;

struct asdf {
    int len;
    ll h;
    asdf operator + (const asdf &c) const {
        return {len + c.len, (h * bs[c.len] + c.h) % mod};
    }
    bool operator == (const asdf &c) const {
        return len == c.len && h == c.h;
    }
};

asdf s[MAXN * 4];

asdf build(int l, int r, int rt) {
    if (l == r) {
        return s[rt] = {1, a[l] - 'a'};
    }
    int mid = (l + r) / 2;
    return s[rt] = build(l, mid, rt * 2) + build(mid + 1, r, rt * 2 + 1);
}

asdf modify(int l, int r, int rt, int ad, char ch) {
    if (l == r) {
        return s[rt] = {1, ch - 'a'};
    }
    int mid = (l + r) / 2;
    if (ad <= mid) {
        return s[rt] = modify(l, mid, rt * 2, ad, ch) + s[rt * 2 + 1];
    } else {
        return s[rt] = s[rt * 2] + modify(mid + 1, r, rt * 2 + 1, ad, ch);
    }
}

asdf query(int l, int r, int rt, int x, int y) {
    if (x <= l && r <= y) {
        return s[rt];
    }
    int mid = (l + r) / 2;
    if (y <= mid) {
        return query(l, mid, rt * 2, x, y);
    }
    if (x > mid) {
        return query(mid + 1, r, rt * 2 + 1, x, y);
    }
    return query(l, mid, rt * 2, x, y) + query(mid + 1, r, rt * 2 + 1, x, y);
}

int main() {
    cin >> n >> a;
    for (int i = 1; i <= n; i++) {
        bs[i] = bs[i - 1] * base % mod;
    }
    a = "!" + a;
    build(1, n, 1);
    for (cin >> q; q--;) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int ad;
            char ch;
            cin >> ad >> ch;
            modify(1, n, 1, ad, ch);
        } else {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            asdf x = query(1, n, 1, l1, r1);
            asdf y = query(1, n, 1, l2, r2);
            if (x == y) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
