#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int N = 15;

int n, ans;

int vis[N][N]; // 禁区数组，表示被多少个皇后占用了

void dfs(int dep) 
{
    // 递归出口 
    if (dep == n + 1)
    {
        ans++;
        return;
    }
    // 开始搜索
    for (int i = 1; i <= n; i++) 
    {
        if (vis[dep][i]) 
        {
            continue;
        }
        
        // 修改状态,按照米字形标记对应元素 
        for (int x = 1; x <= n; x++) vis[x][i]++; // 竖列
        for (int x = dep, y = i; x >= 1 && y >= 1; x--, y--) vis[x][y]++; // 左上角斜线
        for (int x = dep, y = i; x <= n && y >= 1; x++, y--) vis[x][y]++; // 左下角斜线 
        for (int x = dep, y = i; x >= 1 && y <= n; x--, y++) vis[x][y]++; // 右上角斜线 
        for (int x = dep, y = i; x <= n && y <= n; x++, y++) vis[x][y]++; // 右下角斜线 
        
        // 递归搜索
        dfs(dep + 1);
        
        // 恢复现场 
        for (int x = 1; x <= n; x++) vis[x][i]--; // 竖列
        for (int x = dep, y = i; x >= 1 && y >= 1; x--, y--) vis[x][y]--; // 左上角斜线
        for (int x = dep, y = i; x <= n && y >= 1; x++, y--) vis[x][y]--; // 左下角斜线 
        for (int x = dep, y = i; x >= 1 && y <= n; x--, y++) vis[x][y]--; // 右上角斜线 
        for (int x = dep, y = i; x <= n && y <= n; x++, y++) vis[x][y]--; // 右下角斜线 
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n;
    dfs(1);
    cout << ans << "\n";
    
    return 0;
}
