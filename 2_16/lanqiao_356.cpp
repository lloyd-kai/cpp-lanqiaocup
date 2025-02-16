//��Ŀ���ӣ�https://www.lanqiao.cn/problems/356/learning/?page=1&first_category_id=1&name=%E6%84%A4%E6%80%92%E7%9A%84%E5%B0%8F%E9%B8%9F 
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int N = (1 << 18) + 10;
const double eps = 1e-8;
int dp[N];  //dp[i] : ������Ϊ i �����֣�������Ҫ��С������
double x[20], y[20]; //������¼С���λ��
int line[20][20]; //��ʾ�±�ֱ�Ϊ i,j ���߿��Դ�����С��λ�� 

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

        //Ԥ�����������ȷ�����߿��Դ�����С��λ��
        for (int i = 1; i <= n; ++i) {  //ö�ٵ�һ��С��
            line[i][i] |= (1 << (i - 1));
            for (int j = i + 1; j <= n; ++j) {  //ö�ٵڶ�ֻС��
                //����������ڴ�ֱֱ����
                if (abs(x[i] - x[j]) < eps) continue;
                //����������ȷ����������
                double a, b;
                solve(a, b, x[i] * x[i], x[i], y[i], x[j] * x[j], x[j], y[j]);
                //���a > 0 ������������
                if (a > 0 || fabs(a) < eps) continue;
                //�����ߵĻ��õ����Դ���С��ĵ�
                for (int k = 1; k <= n; ++k) {
                    //��ʾ��������
                    if (fabs(a * x[k] * x[k] + b * x[k] - y[k]) < eps) {
                        line[i][j] |= 1 << (k - 1);
                    }
                }
            }
        }

        memset(dp, 0x3f, sizeof dp);
        //Ԥ��������
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[line[i][i]] = 1;
            for (int j = i + 1; j <= n; ++j) {
                dp[line[i][j]] = 1;
            }//��ʼ�����еķ���
        }

    /*    for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; ++j) {
                cout << line[i][j] << " ";
            }
        cout << endl;*/
        
        //��ʼ״̬dp
        for (int i = 1; i <= n; ++i) {  //ö��line[i][j] �е� ������
            for (int j = i; j <= n; ++j) {
                //ö��ÿһ��״̬
                for (int k = 0; k <= (1 << n) - 1; ++k) {
                    dp[k | line[i][j]] = min(dp[k | line[i][j]], dp[k] + 1);
                }
            }
        }

        cout << dp[(1 << n) - 1] << endl;

        //��֮ǰ�ù�������ȫ�����
        memset(dp, 0, sizeof dp);memset(x, 0, sizeof x);memset(y, 0, sizeof y); memset(line, 0, sizeof line);
    }
    return 0;
}
