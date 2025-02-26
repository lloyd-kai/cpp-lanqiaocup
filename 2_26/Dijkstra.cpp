#include <bits/stdc++.h> 
using namespace std;
const int N = 1e7 + 9;

int d[N]; // d[i] 表示点 i 距离源点的最短距离
bitset<N> vis; // 表示某个点是否走过，按照迪杰斯特拉的贪心思想，第一次走到的时候得到的距离一定是最短距离，所以一个点不能走第二次
vector<pair<int, int>> g[N]; // 邻接表存储图，g[x] 存储从 x 出发的边，pair<y, dw> 表示 x->y 的边权为 dw

struct Node
{
    int x, w; // x 表示点编号，w 表示源点到 x 的最短距离
    bool operator < (const Node &u) const
    {
        return w == u.w ? x < u.x : w > u.w; // 修正：按照 w 升序，在优先级队列中 w 最小的作为堆顶
    }
};

priority_queue<Node> pq;

// 迪杰斯特拉算法的堆优化
void Dijkstra(int st)
{
    fill(d, d + N, INT_MAX); // 初始化 d 数组为最大值
    d[st] = 0; // 源点到源点的距离为 0
    pq.push({st, d[st]}); // 将源点加入优先队列
    while (!pq.empty()) // 只要队列不为空
    {
        auto [x, w] = pq.top();
        pq.pop(); // 取出队头元素
        if (vis[x])
        {
            continue; // 如果走过直接跳过
        }
        vis[x] = true;
        for (const auto &[y, dw] : g[x]) // 遍历从 x 出发的边，x->y 边权为 dw
        {
            if (d[x] + dw < d[y]) // 如果通过 x 到 y 的距离更短
            {
                d[y] = d[x] + dw; // 更新 y 的最短距离
                pq.push({y, d[y]}); // 将 y 加入优先队列
            }
        }
    }
}

int main()
{
    int n, m, st;
    cin >> n >> m >> st; // 输入节点数、边数和源点
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w}); // 添加有向边 x->y，边权为 w
    }
    Dijkstra(st); // 调用 Dijkstra 算法
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == INT_MAX)
            cout << "INF "; // 如果不可达，输出 INF
        else
            cout << d[i] << " "; // 输出源点到每个点的最短距离
    }
    return 0;
}
