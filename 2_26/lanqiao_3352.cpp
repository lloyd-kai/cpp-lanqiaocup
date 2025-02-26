//题目链接：https://www.lanqiao.cn/problems/3352/learning/?page=1&first_category_id=1&problem_id=3352 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 9, p = 1e9 + 7;
ll d[N], dp[N]; // d[]表示从索引值城市到城市1的距离；dp[]表示从索引值城市到城市1最近的路径数
vector<int> g[N]; // g[]是邻接表

void bfs(int x)
{
    bitset<N> vis;

    queue<int> q; // 所有城市的集合
    q.push(1); // 先将城市1入队

    memset(d, 0x3f, sizeof d); // 初始化d[]

    d[1] = 0; // 初始状态下，城市1到城市1的距离是0
    dp[1] = 1; // 初始状态下，城市1到城市1的路径数为1

    while(q.size())
    {
        int x = q.front(); q.pop(); // 取当前队头城市
        if(vis[x]) continue; // 判断一下这个城市是不是已经来过了，如果已经来过就不去了
        vis[x] = true; // 这个城市没来过，现在来了，标记来过了

        for(const auto& y : g[x]) // g[x]是邻接表，表示“（已走过的）从城市1到城市x的下一个城市”此处记为“城市y”
        { // PS:这道题中，城市间的距离默认为1；dp[x]和dp[y]走的不是同一条路径
            if(d[x] + 1 > d[y]) continue;
            // 如果从城市1到城市y的距离比之前走过的远
            // 说明这条路径不理想，不是最近的路径，不考虑，直接跳过

            else if(d[x] + 1 == d[y]) dp[y] = (dp[x] + dp[y]) % p;
            // 如果从城市1到城市y的距离跟之前走过的一样远
            // 那么从城市1到城市y的路径数就等于这两种方案的路径数之和

            else d[y] = d[x] + 1, dp[y] = dp[x];
            // 如果从城市1到城市x的下一个城市的距离比过去的近
            // 说明这条路径是城市1到城市n最短路径上的一条边，是当前到城市y的最近距离，更新数据

            q.push(y); // 下一个遍历对象是城市y，入队
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    while(m --)
    {
        int x, y;
        cin >> x >> y;

        // 由于是双向路径，所以彼此都要进入容器
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bfs(1); // 从城市1开始进行宽搜

    cout << dp[n] << endl; // 输出从城市1到城市n的最短路径数

    return 0;
}
