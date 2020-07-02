#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        ll a, b, n, m;
        scanf("%lld%lld%lld%lld", &a, &b, &n, &m);
        if (a + b < n + m) {
            printf("No\n");
            continue;
        }
        ll mi = min(a, b);
        if (m <= mi) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}