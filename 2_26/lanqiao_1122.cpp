//题目链接：https://www.lanqiao.cn/problems/1122/learning/?page=1&first_category_id=1&problem_id=1122
#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
const ll N = 3e5+5,inf = 2e18;
struct Node
{
    ll x, w; // x 表示点编号，w 表示源点到 x 的最短距离
    bool operator < (const Node &u) const
    {
        return w == u.w ? x < u.x : w > u.w; // 修正：按照 w 升序，在优先级队列中 w 最小的作为堆顶
    }
};


vector<Node> g[N];
ll d[N];
int n,m;

// 迪杰斯特拉算法的堆优化
void Dijkstra(int st)
{
    for(int i = 1;i<=n;i++) // 初始化 d 数组为最大值
    {
      d[i] = inf;
    }
    bitset<N>vis;
    priority_queue<Node> pq;
    pq.push({st, d[st] =0}); // 将源点加入优先队列
    while (pq.size()) // 只要队列不为空
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
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m; // 输入节点数、边数和源点
    while(m--)
    {
      int x,y,w;
      cin>>x>>y>>w;
      g[x].push_back({y,w});
    }
    Dijkstra(1); // 调用 Dijkstra 算法
    for (int i = 1; i <= n; i++)
    {
      cout<<(d[i]>=inf?-1:d[i])<<' ';
    }
    return 0;
}
