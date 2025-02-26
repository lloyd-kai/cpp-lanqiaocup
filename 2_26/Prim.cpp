#include <bits/stdc++.h> 
using namespace std;
const int N = 1e5 + 9;
typedef long long ll; // 添加 long long 的别名

struct Edge
{
    ll x, c;
    bool operator < (const Edge &u) const
    {
        return c == u.c ? x > u.x : c > u.c; // 按 c 从大到小排序，若 c 相同则按 x 从大到小排序
    }
};

vector<Edge> g[N]; // 邻接表存储图
ll d[N]; // 存储每个节点的最小边权
int n, m;

int prim()
{
    priority_queue<Edge> pq;
    bitset<N> vis; 

    fill(d, d + N, LLONG_MAX); // 初始化 d 数组为最大值
    d[1] = 0;
    pq.push({1, d[1]});

    ll res = 0;
    while (!pq.empty())
    {
        int x = pq.top().x;
        pq.pop();
        if (vis[x]) 
        {
            continue;
        }
        vis[x] = true;

        res = max(res, d[x]); // 更新最大边权

        for (const auto &e : g[x]) 
        {
            int y = e.x;
            ll w = e.c;
            if (vis[y])
            {
                continue;
            }
            if (w < d[y])
            {
                d[y] = w;
                pq.push({y, d[y]});
            }
        }
    }
    return res;
}

int main()
{
    cin >> n >> m; // 输入节点数和边数
    for (int i = 1; i <= m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w}); // 无向图，双向加边
        g[y].push_back({x, w});
    }
    cout << prim() << endl; // 输出最大边权
    return 0;
}
