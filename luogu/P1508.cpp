#include <algorithm>
#include <stdio.h>
using namespace std;

const int maxn = 205;
const int INF = 2e9 + 7;

long long dp[maxn][maxn];

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &dp[i][j]);
        }
    }

    int pos = (n + 1) / 2;
    for (int i = 2; i <= m + 1; i++) {
        for (int j = 1; j <= n; j++) {
            long long t = 0;
            t = dp[i - 1][j];
            if (j - 1 >= 1) {
                t = max(t, dp[i - 1][j - 1]);
            }
            if (j + 1 <= n) {
                t = max(t, dp[i - 1][j + 1]);
            }
            dp[i][j] += t;
        }
    }
    printf("%lld\n", dp[m + 1][pos]);
    return 0;
}
