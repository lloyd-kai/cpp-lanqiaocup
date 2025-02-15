//题目链接：https://www.lanqiao.cn/problems/836/learning/?page=1&first_category_id=1&name=windy 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, dig[20], cnt;
ll f[20][20];//表示长度为i的数字，最高位为j的windy数数量
ll solve(ll x)
{
    memset(dig, 0, sizeof(dig));
    cnt = 0;
    while (x)
    {
        dig[++cnt] = x % 10;
        x /= 10;
    }//最基本的拆分数字 123->1 2 3
    //要求长度<=cnt的windy
    ll ans = 0;
    for (int i = 1; i < cnt; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            ans += f[i][j];
        }
    }//表示长度小雨等于右边界长度的数字
    //长度跟我们右边界x的长度一样的
    for (int i = 1; i < dig[cnt]; i++)
    {
        ans += f[cnt][i];
    }
    for (int i = cnt - 1; i >= 1; i--)//枚举当前是哪一位
    {
        for (int j = 0; j <= dig[i] - 1; j++)
        {
            if (abs(j - dig[i + 1]) >= 2)
            {
                ans += f[i][j];
            }
        }
        //我们要填写的那个数字次高位小于右边界的次高位，那么我们后面随便编一个
        if (abs(dig[i + 1] - dig[i]) < 2)
        {
            break;
        }
    }
    return ans;
}


int main()
{
    scanf("%lld%lld", &a, &b);//输入参数
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
