#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;

ll h[N];//h[N]��ʾ��0��x����̾���

bool Bellman_Ford()
{
    //��ʼ��h[]Ϊ����
    for(int i = 1;i<=n;i++)
    {
        h[i] = inf;
    }
    //h[0] = 0;���Ժ���
    
    //һ��n���㣬�����ɳ�n-1�Σ�i���ڼ���
    for(int i = 1;i<n;i++)
    {
        //ö�����еı�,������������ȥ�ɳڵ�x
        for(const auto &[x,y,w]:es)
        {
            if(h[x] == inf)
            {
                continue;
            }
            //�������ͨ�������߿����ɳ�
            if(h[x]+w<h[y])
            {
                h[y] = h[x]+w;
            }
        }
    }
    
    //�ж��Ƿ���ڸ�Ȩ��
    for(const auto &[x,y,z]:es)
    {
        if(h[x] == inf)
        {
            continue;
        }
        //������б߿����ɳڣ���ô˵�����ڸ�������false
        if(h[x] + w<h[y])
        {
            return false;
        }
    }
    
    //�����ڸ���
    return true;
}
