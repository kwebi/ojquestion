#include <bits/stdc++.h>

typedef long long ll;
const int mod = 1e9 + 7;
ll a[2000010];

int main()
{
    int T;
    scanf("%d", &T);

    a[1] = 0;
    a[2] = 0;
    a[3] = 4;
    for (int i = 4; i < 2000001; i++) {
        if (i % 3 == 0) {
            a[i] = (a[i - 1] + a[i - 2] * 2 % mod + 4) % mod;
        } else
            a[i] = (a[i - 1] + a[i - 2] * 2 % mod) % mod;
    }

    while (T--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", a[n]);
    }
    return 0;
}