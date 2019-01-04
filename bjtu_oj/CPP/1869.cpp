#include <stdio.h>

int main()
{
    long long x, y, k;
    scanf("%lld %lld %lld", &x, &y, &k);
    long long res = x * k;
    for (long long i = 0; i <= k / 3 + 1; i++)
    {
        long long tmp;
        if (k - i * 3 > 0)
            tmp = (k - i * 3) * x + i * y;
        else
            tmp = i * y;
        res = res < tmp ? res : tmp;
    }
    printf("%lld\n", res);
    return 0;
}