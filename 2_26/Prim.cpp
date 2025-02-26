#include <bits/stdc++.h> 
using namespace std;
const int N = 1e5 + 9;
typedef long long ll; // ��� long long �ı���

struct Edge
{
    ll x, c;
    bool operator < (const Edge &u) const
    {
        return c == u.c ? x > u.x : c > u.c; // �� c �Ӵ�С������ c ��ͬ�� x �Ӵ�С����
    }
};

vector<Edge> g[N]; // �ڽӱ�洢ͼ
ll d[N]; // �洢ÿ���ڵ����С��Ȩ
int n, m;

int prim()
{
    priority_queue<Edge> pq;
    bitset<N> vis; 

    fill(d, d + N, LLONG_MAX); // ��ʼ�� d ����Ϊ���ֵ
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

        res = max(res, d[x]); // ��������Ȩ

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
    cin >> n >> m; // ����ڵ����ͱ���
    for (int i = 1; i <= m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w}); // ����ͼ��˫��ӱ�
        g[y].push_back({x, w});
    }
    cout << prim() << endl; // �������Ȩ
    return 0;
}
