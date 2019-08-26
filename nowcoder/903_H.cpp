#include <stdio.h>

long long add_num(long long x)
{
    long long ans = 0;
    while (x > 0)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t)
    {
        long long n, k;
        scanf("%lld%lld", &n, &k);
        long long x = (k == 1 ? n : n * n);
        while (x >= 10)
        {
            x = add_num(x);
        }
        printf("%lld\n",x);
    }
    return 0;
}
