//��Ŀ���ӣ�https://www.lanqiao.cn/problems/836/learning/?page=1&first_category_id=1&name=windy 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, dig[20], cnt;
ll f[20][20];//��ʾ����Ϊi�����֣����λΪj��windy������
ll solve(ll x)
{
    memset(dig, 0, sizeof(dig));
    cnt = 0;
    while (x)
    {
        dig[++cnt] = x % 10;
        x /= 10;
    }//������Ĳ������ 123->1 2 3
    //Ҫ�󳤶�<=cnt��windy
    ll ans = 0;
    for (int i = 1; i < cnt; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            ans += f[i][j];
        }
    }//��ʾ����С������ұ߽糤�ȵ�����
    //���ȸ������ұ߽�x�ĳ���һ����
    for (int i = 1; i < dig[cnt]; i++)
    {
        ans += f[cnt][i];
    }
    for (int i = cnt - 1; i >= 1; i--)//ö�ٵ�ǰ����һλ
    {
        for (int j = 0; j <= dig[i] - 1; j++)
        {
            if (abs(j - dig[i + 1]) >= 2)
            {
                ans += f[i][j];
            }
        }
        //����Ҫ��д���Ǹ����ִθ�λС���ұ߽�Ĵθ�λ����ô���Ǻ�������һ��
        if (abs(dig[i + 1] - dig[i]) < 2)
        {
            break;
        }
    }
    return ans;
}


int main()
{
    scanf("%lld%lld", &a, &b);//�������
    for (int i = 0; i <= 9; i++)
    {
        f[1][i] = 1;
    }
    for (int i = 2; i <= 10; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                if (abs(j - k) >= 2)
                {
                    f[i][j] += f[i - 1][k];
                }
            }
        }
    }
    printf("%lld\n", solve(b) - solve(a - 1));
    return 0;
}
