#include <stdio.h>

typedef long long ll;

const int maxn = 65005;

bool is_prime[maxn];

void sieve(int n)
{
    for (int i = 0; i <= n; ++i)
        is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= n; ++i)
    {
        if (is_prime[i])
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }
}

ll pow_mod(int a, int n, int mod)
{
    ll x = a;
    ll ans = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            ans = (ans % mod) * (x % mod) % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return ans % mod;
}

int main()
{
    int n;
    sieve(maxn);
    do
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        if (is_prime[n])
        {
            printf("%d is normal.\n", n);
            continue;
        }
        bool f = 1;
        for (int i = 2; i <= n - 1; ++i)
        {
            if (pow_mod(i, n, n) != i)
            {
                f = 0;
                break;
            }
        }
        if (f)
            printf("The number %d is a Carmichael number.\n", n);
        else
            printf("%d is normal.\n", n);
    } while (true);
    return 0;
}
