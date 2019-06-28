#include <algorithm>
#include <stdio.h>
using namespace std;

const int maxn = 105;
typedef long long LL;
int a[maxn];

int main()
{
    int q;
    scanf("%d", &q);
    for (int Q = 0; Q < q; Q++) {
        LL k, a, b;
        LL n;
        scanf("%I64d%I64d%I64d%I64d", &k, &n, &a, &b);
        LL ans = 0;
        if (k <= n * b) {
            printf("-1\n");
            continue;
        }
        if ((k - b * n) % (a - b) == 0) {
            ans = (k - b * n) / (a - b) - 1;
        } else {
            ans = (k - b * n) / (a - b);
        }

        printf("%I64d\n", min(n, ans));
    }
    return 0;
}
