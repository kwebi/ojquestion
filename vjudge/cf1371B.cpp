#include <bits/stdc++.h>

typedef long long ll;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, r;
        scanf("%d%d", &n, &r);
        ll ans;
        if (r >= n) {
            r = n;
            ans = 1LL * (r - 1LL) * r / 2 + 1;
        } else {
            ans = 1LL * (r + 1LL) * r / 2;
        }
        printf("%lld\n", ans);
    }

    return 0;
}