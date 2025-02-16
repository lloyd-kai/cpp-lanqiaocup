//题目链接：https://www.lanqiao.cn/problems/356/learning/?page=1&first_category_id=1&name=%E6%84%A4%E6%80%92%E7%9A%84%E5%B0%8F%E9%B8%9F 
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int N = (1 << 18) + 10;
const double eps = 1e-8;
int dp[N];  //dp[i] : 二进制为 i 的数字，最少需要的小鸟数量
double x[20], y[20]; //用来记录小猪的位置
int line[20][20]; //表示下标分别为 i,j 的线可以打死的小猪位置 

void solve(double& a, double& b, double a1, double b1, double c1, double a2, double b2, double c2)
{
    b = (a1 * c2 - a2 * c1) / (a1 * b2 - b1 * a2);
    a = (c1 - b * b1) / a1;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];

        //预处理出来两点确定的线可以打死的小猪位置
        for (int i = 1; i <= n; ++i) {  //枚举第一个小猪
            line[i][i] |= (1 << (i - 1));
            for (int j = i + 1; j <= n; ++j) {  //枚举第二只小猪
                //如果两个点在垂直直线上
                if (abs(x[i] - x[j]) < eps) continue;
                //计算两个点确定的抛物线
                double a, b;
                solve(a, b, x[i] * x[i], x[i], y[i], x[j] * x[j], x[j], y[j]);
                //如果a > 0 ，则不是抛物线
                if (a > 0 || fabs(a) < eps) continue;
                //抛物线的话得到可以打死小猪的点
                for (int k = 1; k <= n; ++k) {
                    //表示点在线上
                    if (fabs(a * x[k] * x[k] + b * x[k] - y[k]) < eps) {
                        line[i][j] |= 1 << (k - 1);
                    }
                }
            }
        }

        memset(dp, 0x3f, sizeof dp);
        //预处理数据
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[line[i][i]] = 1;
            for (int j = i + 1; j <= n; ++j) {
                dp[line[i][j]] = 1;
            }//初始化其中的方案
        }

    /*    for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; ++j) {
                cout << line[i][j] << " ";
            }
        cout << endl;*/
        
        //开始状态dp
        for (int i = 1; i <= n; ++i) {  //枚举line[i][j] 中的 方案；
            for (int j = i; j <= n; ++j) {
                //枚举每一个状态
                for (int k = 0; k <= (1 << n) - 1; ++k) {
                    dp[k | line[i][j]] = min(dp[k | line[i][j]], dp[k] + 1);
                }
            }
        }

        cout << dp[(1 << n) - 1] << endl;

        //将之前用过的数组全部清空
        memset(dp, 0, sizeof dp);memset(x, 0, sizeof x);memset(y, 0, sizeof y); memset(line, 0, sizeof line);
    }
    return 0;
}
