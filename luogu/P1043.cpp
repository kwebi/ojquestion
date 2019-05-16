#include <stdio.h>

const int MAXN = 1e6 + 5;

int f[MAXN];
int a[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    long long res = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; j += i)
            a[j]++;
        res += a[i];
    }
    printf("%lld", res);
    return 0;
}
