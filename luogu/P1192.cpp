#include <stdio.h>

const int MAXN = 1e5 + 5;
const int MOD = 100003;

int a[MAXN];
int sum[MAXN];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    a[n - 1] = 1;
    sum[n - 1] = 1;
    for (int i = n - 2; i >= n - k; --i)
    {
        a[i] = a[i + 1] * 2 % MOD;
        sum[i] = (sum[i + 1] + a[i]) % MOD;
    }
    for (int i = n - k - 1; i >= 0; --i)
    {
        a[i] = (sum[i + 1] - sum[k + 1 + i] + MOD * 2) % MOD;
        sum[i] = (sum[i + 1] + a[i]) % MOD;
    }
    printf("%d", a[0] % MOD);
    return 0;
}
