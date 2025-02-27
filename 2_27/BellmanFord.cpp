#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;

ll h[N];//h[N]表示点0到x的最短距离

bool Bellman_Ford()
{
    //初始化h[]为无穷
    for(int i = 1;i<=n;i++)
    {
        h[i] = inf;
    }
    //h[0] = 0;可以忽略
    
    //一共n个点，所以松弛n-1次，i用于计数
    for(int i = 1;i<n;i++)
    {
        //枚举所有的边,尝试用这条边去松弛点x
        for(const auto &[x,y,w]:es)
        {
            if(h[x] == inf)
            {
                continue;
            }
            //如果可以通过这条边可以松弛
            if(h[x]+w<h[y])
            {
                h[y] = h[x]+w;
            }
        }
    }
    
    //判断是否存在负权环
    for(const auto &[x,y,z]:es)
    {
        if(h[x] == inf)
        {
            continue;
        }
        //如果还有边可以松弛，那么说明存在负环返回false
        if(h[x] + w<h[y])
        {
            return false;
        }
    }
    
    //不存在负环
    return true;
}
