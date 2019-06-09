#include <algorithm>
#include <stdio.h>
using namespace std;

const int maxn = 105;
const int maxt = 1005;

int w[maxn];
int v[maxn];
int dp[maxn][maxt];

int main()
{
    int t, m;
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &w[i], &v[i]);
    }
    dp[0][0] = 0;

    for (int j = 0; j <= t; ++j)
    {
        for (int i = 1; i <= m; ++i)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    printf("%d", dp[m][t]);
    return 0;
}
