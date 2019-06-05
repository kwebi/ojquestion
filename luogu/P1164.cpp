#include <stdio.h>

const int maxm = 1e4 + 5;

int a[105];
int dp[105][maxm];

inline int _max(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i])
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i]];
            }
        }
    }
    printf("%d", dp[n][m]);
    return 0;
}
