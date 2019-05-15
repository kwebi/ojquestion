#include <stdio.h>
#include <iostream>

using namespace std;
using ll = long long;

ll pow_mod(ll b, ll p, ll k)
{
    ll res = 1;
    while (p > 0)
    {
        if (p & 1)
        {
            res = (res * b) % k;
        }
        b = (b * b) % k;
        p >>= 1;
    }
    return res % k;
}

int main()
{
    ll b, p, k;
    scanf("%lld%lld%lld", &b, &p, &k);
    ll res = pow_mod(b, p, k);
    printf("%lld^%lld mod %lld=%lld", b, p, k, res);
    return 0;
}
