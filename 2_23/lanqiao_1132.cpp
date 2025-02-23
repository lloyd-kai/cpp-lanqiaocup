//题目链接：https://www.lanqiao.cn/problems/1132/learning/?page=1&first_category_id=1&name=%E5%8C%BA%E9%97%B4%E7%AC%ACk%E5%B0%8F
#include<bits/stdc++.h>
using namespace std;
#define lc(x) tr[x].l
#define rc(x) tr[x].r
const int N=2e5+6;
int n,m,a[N],b[N];
struct Node {
 int l,r,s;//左右儿子，该节点在值域中的个数
}tr[N*20];
int idx,root[N];
void build(int &x,int l,int r)
{
    x=++idx;
    if(l==r)return ;
    int mid=(l+r)>>1;
    build(lc(x),l,mid);
    build(rc(x),mid+1,r);
}
void update(int x,int &y,int l,int r,int v)
{
    y=++idx;
    tr[y]=tr[x];
    tr[y].s++;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(v<=mid)
        update(lc(x),lc(y),l,mid,v);
    else
        update(rc(x),rc(y),mid+1,r,v);
}
int query(int x,int y,int l,int r,int k)
{
    if(l==r)return l;
    int mid=(l+r)>>1;
    int s=tr[lc(y)].s-tr[lc(x)].s;
    if(k<=s)
        return query(lc(x),lc(y),l,mid,k);
    else 
        return query(rc(x),rc(y),mid+1,r,k-s);
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int bn=unique(b+1,b+1+n)-b-1;
    build(root[0],1,bn);
    for(int i=1;i<=n;i++)
    {
        int id=lower_bound(b+1,b+1+bn,a[i])-b;
        update(root[i-1],root[i],1,bn,id);
    }
    while(m--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        int id=query(root[l-1],root[r],1,bn,k);
        cout<<b[id]<<'\n';
    }
    return 0;
}
