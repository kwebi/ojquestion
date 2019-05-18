#include <cstring>
#include <stdio.h>

int dp[40][40];

int main()
{
    memset(dp, 0, sizeof(dp));
    int n, m;
    dp[1][0] = 1;
    scanf("%d%d", &n, &m);
    for (int j = 1; j <= m; ++j)
    {
        dp[1][j] = dp[2][j - 1] + dp[n][j - 1];
        for (int i = 2; i <= n; ++i)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i + 1][j - 1];
        }
        dp[n][j] = dp[n - 1][j - 1] + dp[1][j - 1];
    }
    printf("%d\n",dp[1][m]);
    return 0;
}
