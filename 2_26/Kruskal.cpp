#include <bits/stdc++.h> 
using namespace std;
const int N = 1e5+9;

struct Edge
{
    int x, y, c;
    bool operator < (const Edge &u) const
    {
        return c < u.c; 
    } 
};

int pre[N];
int root(int x)
{
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> es;
    for(int i = 1; i <= m; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        es.push_back({x, y, c}); 
    }
    
    sort(es.begin(), es.end());
    for(int i = 1; i <= n; i++)
    {
        pre[i] = i;  
    }
    int ans = 0;
    for(const auto& e : es)  
    {
        int x = e.x;
        int y = e.y;
        int c = e.c;
        if(root(x) == root(y))
        {
            continue;
        }
        ans = max(ans, c);
        pre[root(x)] = root(y);
    }
    cout << ans << "\n";
}

int main()
{
    solve();
    return 0;
}
