#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int N = 15;

int n, ans;

int vis[N][N]; // �������飬��ʾ�����ٸ��ʺ�ռ����

void dfs(int dep) 
{
    // �ݹ���� 
    if (dep == n + 1)
    {
        ans++;
        return;
    }
    // ��ʼ����
    for (int i = 1; i <= n; i++) 
    {
        if (vis[dep][i]) 
        {
            continue;
        }
        
        // �޸�״̬,���������α�Ƕ�ӦԪ�� 
        for (int x = 1; x <= n; x++) vis[x][i]++; // ����
        for (int x = dep, y = i; x >= 1 && y >= 1; x--, y--) vis[x][y]++; // ���Ͻ�б��
        for (int x = dep, y = i; x <= n && y >= 1; x++, y--) vis[x][y]++; // ���½�б�� 
        for (int x = dep, y = i; x >= 1 && y <= n; x--, y++) vis[x][y]++; // ���Ͻ�б�� 
        for (int x = dep, y = i; x <= n && y <= n; x++, y++) vis[x][y]++; // ���½�б�� 
        
        // �ݹ�����
        dfs(dep + 1);
        
        // �ָ��ֳ� 
        for (int x = 1; x <= n; x++) vis[x][i]--; // ����
        for (int x = dep, y = i; x >= 1 && y >= 1; x--, y--) vis[x][y]--; // ���Ͻ�б��
        for (int x = dep, y = i; x <= n && y >= 1; x++, y--) vis[x][y]--; // ���½�б�� 
        for (int x = dep, y = i; x >= 1 && y <= n; x--, y++) vis[x][y]--; // ���Ͻ�б�� 
        for (int x = dep, y = i; x <= n && y <= n; x++, y++) vis[x][y]--; // ���½�б�� 
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
