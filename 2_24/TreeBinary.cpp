#include <bits/stdc++.h> 
using namespace std;
const int MAXN = 110000;
int tree[MAXN];
int q;

int lowbit(int x)
{
    return x & -x;
}

void add(int pos,int x)
{
    while(pos<MAXN)
    {
        tree[pos]+=x;
        pos+=lowbit(pos);
    }
}

int query(int pos)
{
    int ans = 0;
    while(pos)
    {
        ans+=tree[pos];
        pos-=lowbit(pos);
    }
    return ans;
}

int find(int a,int k) 
{
    int l = a+1,r = MAXN-1;
    int ans = 1;
    while(l<=r)
    {
        int mid = (l+r)>>1;
        if(query(mid)-query(a) == k)
        {
            ans = mid;
        }
        if(query(mid)-query(a)>=k)
        {
            r = mid-1;
        } 
        else
        {
            l = mid+1;
        }
    }
    return ans;
}

int main()
{
    scanf("%d",&q);
    for(int i = 1;i<=q;i++)
    {
        int x,y,z;
        scanf("%d",&x);
        if(x == 0)
        {
            scanf("%d",&y);
            add(y,1);
        }
        else if(x == 1)
        {
            scanf("%d",&y);
            if(query(y)-query(y-1) == 0)
            {
                continue;
            }
            add(y,-1);
        }
        else
        {
            scanf("%d%d",&y,&z);
            printf("%d\n",find(y,z)) ;
        }
    }
    return 0;
}
