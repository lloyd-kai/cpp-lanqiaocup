#include <bits/stdc++.h> 
using namespace std;
const int N = 1e7 + 9;

int d[N]; // d[i] ��ʾ�� i ����Դ�����̾���
bitset<N> vis; // ��ʾĳ�����Ƿ��߹������յϽ�˹������̰��˼�룬��һ���ߵ���ʱ��õ��ľ���һ������̾��룬����һ���㲻���ߵڶ���
vector<pair<int, int>> g[N]; // �ڽӱ�洢ͼ��g[x] �洢�� x �����ıߣ�pair<y, dw> ��ʾ x->y �ı�ȨΪ dw

struct Node
{
    int x, w; // x ��ʾ���ţ�w ��ʾԴ�㵽 x ����̾���
    bool operator < (const Node &u) const
    {
        return w == u.w ? x < u.x : w > u.w; // ���������� w ���������ȼ������� w ��С����Ϊ�Ѷ�
    }
};

priority_queue<Node> pq;

// �Ͻ�˹�����㷨�Ķ��Ż�
void Dijkstra(int st)
{
    fill(d, d + N, INT_MAX); // ��ʼ�� d ����Ϊ���ֵ
    d[st] = 0; // Դ�㵽Դ��ľ���Ϊ 0
    pq.push({st, d[st]}); // ��Դ��������ȶ���
    while (!pq.empty()) // ֻҪ���в�Ϊ��
    {
        auto [x, w] = pq.top();
        pq.pop(); // ȡ����ͷԪ��
        if (vis[x])
        {
            continue; // ����߹�ֱ������
        }
        vis[x] = true;
        for (const auto &[y, dw] : g[x]) // ������ x �����ıߣ�x->y ��ȨΪ dw
        {
            if (d[x] + dw < d[y]) // ���ͨ�� x �� y �ľ������
            {
                d[y] = d[x] + dw; // ���� y ����̾���
                pq.push({y, d[y]}); // �� y �������ȶ���
            }
        }
    }
}

int main()
{
    int n, m, st;
    cin >> n >> m >> st; // ����ڵ�����������Դ��
    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w}); // �������� x->y����ȨΪ w
    }
    Dijkstra(st); // ���� Dijkstra �㷨
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == INT_MAX)
            cout << "INF "; // ������ɴ��� INF
        else
            cout << d[i] << " "; // ���Դ�㵽ÿ�������̾���
    }
    return 0;
}
