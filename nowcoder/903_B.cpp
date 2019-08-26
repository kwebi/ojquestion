#include <stdio.h>

const int maxn = 1e5;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t)
    {
        int q, n, p;
        scanf("%d%d%d", &q, &n, &p);

        long long x = q;
        long long s1 = 1, s2 = 0;
        long long ans = 0;
        while (n > 0)
        {
            s1 = s1 * x % p;
            ans = (ans + s1) % p;
            ans = (ans + s2) % p;
            x = x * x % p;
            s2 = x;
            n >>= 1;
        }

        printf("%lld\n", ans);
    }
    return 0;
}
