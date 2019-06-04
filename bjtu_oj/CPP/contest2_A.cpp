#include <stdio.h>
#include <iostream>
using namespace std;

constexpr int maxn = 5e3+5;

int a[maxn][maxn];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%1d", &a[i][j]);
        }
    }
    for (int i = 1; i < maxn; ++i)
    {
        for (int j = 1; j < maxn; ++j)
        {
            a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }

    int ans = 0;
    for (int k = 2; k <= m || k <= n; ++k)
    {
        int tans = 0;
        int k2 = k * k;
        for (int i = k; i < n + k; i += k)
        {
            for (int j = k; j < m + k; j += k)
            {
                int t = a[i][j] - a[i - k][j] - a[i][j - k] + a[i - k][j - k];
                t = t < (k2 - t) ? t : (k2 - t);
                tans += t;
            }
        }
        if (k == 2)
            ans = tans;
        else
            ans = tans < ans ? tans : ans;
    }
    printf("%d", ans);
    return 0;
}
