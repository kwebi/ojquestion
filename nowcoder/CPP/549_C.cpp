#include <math.h>
#include <stdio.h>
typedef long long LL;
typedef long double LD;
const int N = 35;
LL dp[N][4 * N];
LL fp(LL x, LL y)
{
    LL ans = 1;
    while (y)
    {
        if (y & 1)
            ans *= x;
        x *= x;
        y >>= 1;
    }
    return ans;
}
LL gcd(LL a, LL b) { return b == 0 ? a : gcd(b, a % b); }

int main()
{
    int n;
    LL res = 0;
    scanf("%d", &n);
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= 4 * i; ++j)
        {
            for (int k = 1; k <= 4; ++k)
            {
                if (j - k >= 0)
                    dp[i][j] += dp[i - 1][j - k];
            }
        }
    }
    for (int i = 3 * n; i <= 4 * n; ++i)
        res += dp[n][i];
    LL m = fp(4, n);
    LL d = gcd(m, res);
    printf("%lld/%lld\n", res / d, m / d);
    return 0;
}
