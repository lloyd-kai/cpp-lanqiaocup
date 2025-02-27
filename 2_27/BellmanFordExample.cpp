#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const long long INF = 1e9;

struct Edge {
    int v;
    long long w;
    Edge(int v, long long w) : v(v), w(w) {}
};

vector<vector<Edge>> adj;
vector<long long> h;
vector<vector<long long>> dist;

bool bellmanFord(int n) {
    h.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int u = 1; u <= n; ++u) {
            for (const Edge& e : adj[u]) {
                if (h[e.v] > h[u] + e.w) {
                    h[e.v] = h[u] + e.w;
                    if (i == n) return true; // Negative cycle detected
                }
            }
        }
    }
    return false;
}

void dijkstra(int s, int n) {
    dist[s].assign(n + 1, INF);
    dist[s][s] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[s][u]) continue;
        for (const Edge& e : adj[u]) {
            if (dist[s][e.v] > dist[s][u] + e.w + h[u] - h[e.v]) {
                dist[s][e.v] = dist[s][u] + e.w + h[u] - h[e.v];
                pq.push({dist[s][e.v], e.v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    dist.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    if (bellmanFord(n)) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        dijkstra(i, n);
    }

    for (int i = 1; i <= n; ++i) {
        long long sum = 0;
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] == INF) {
                sum += INF;
            } else {
                sum += dist[i][j] - h[i] + h[j];
            }
        }
        cout << sum << endl;
    }

    return 0;
}
