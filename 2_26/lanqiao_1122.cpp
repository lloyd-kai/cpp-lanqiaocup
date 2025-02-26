//��Ŀ���ӣ�https://www.lanqiao.cn/problems/1122/learning/?page=1&first_category_id=1&problem_id=1122
#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
const ll N = 3e5+5,inf = 2e18;
struct Node
{
    ll x, w; // x ��ʾ���ţ�w ��ʾԴ�㵽 x ����̾���
    bool operator < (const Node &u) const
    {
        return w == u.w ? x < u.x : w > u.w; // ���������� w ���������ȼ������� w ��С����Ϊ�Ѷ�
    }
};


vector<Node> g[N];
ll d[N];
int n,m;

// �Ͻ�˹�����㷨�Ķ��Ż�
void Dijkstra(int st)
{
    for(int i = 1;i<=n;i++) // ��ʼ�� d ����Ϊ���ֵ
    {
      d[i] = inf;
    }
    bitset<N>vis;
    priority_queue<Node> pq;
    pq.push({st, d[st] =0}); // ��Դ��������ȶ���
    while (pq.size()) // ֻҪ���в�Ϊ��
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
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m; // ����ڵ�����������Դ��
    while(m--)
    {
      int x,y,w;
      cin>>x>>y>>w;
      g[x].push_back({y,w});
    }
    Dijkstra(1); // ���� Dijkstra �㷨
    for (int i = 1; i <= n; i++)
    {
      cout<<(d[i]>=inf?-1:d[i])<<' ';
    }
    return 0;
}
