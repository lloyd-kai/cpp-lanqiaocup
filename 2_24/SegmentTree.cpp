#include <bits/stdc++.h> 
using namespace std;
const int MAXN = 1e5+7;
const int INF = 1e9+7;

int n;

struct Tree
{
    int l, r, v, num, ls, rs; 
};

int root, cnt;
Tree tre[MAXN << 4];

void update(int &t, int l, int r, int k)
{
    if (!t)
    {
        t = ++cnt;
        tre[t].l = l;
        tre[t].r = r;
        tre[t].num = 0; // 初始化 num
    }
    if (l == r)
    {
        tre[t].v = k;
        tre[t].num++;
        return;
    }
    int mid = (l + r) >> 1;
    if (k <= mid)
    {
        if (!tre[t].ls) tre[t].ls = ++cnt;
        update(tre[t].ls, l, mid, k);
    }
    else
    {
        if (!tre[t].rs) tre[t].rs = ++cnt;
        update(tre[t].rs, mid + 1, r, k);
    }
    tre[t].num = (tre[t].ls ? tre[tre[t].ls].num : 0) + (tre[t].rs ? tre[tre[t].rs].num : 0);
}

// 找中位数函数 
// t表示当前节点 k剩余排名 
int _rank(int t, int k)
{
    if (tre[t].l == tre[t].r)
    {
        return tre[t].v;
    }
    if (tre[tre[t].ls].num >= k)
    {
        return _rank(tre[t].ls, k);
    }
    else
    {
        return _rank(tre[t].rs, k - tre[tre[t].ls].num);
    }
}

int main()
{
    // 初始化
    int x, y;
    cin >> n >> x;
    update(root, 0, INF, x);
    cout << x << endl;

    for (int i = 3; i <= n; i += 2)
    {
        cin >> x >> y;
        update(root, 0, INF, x);
        update(root, 0, INF, y);
        cout << _rank(root, i / 2 + 1) << endl;
    }
    return 0;
}
