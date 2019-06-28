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
        int n;
        LL k;
        scanf("%d%I64d", &n, &k);
        int _min = 1e8 + 1, _max = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            _min = min(_min, a[i]);
            _max = max(_max, a[i]);
        }
        if ((_max - _min) > 2 * k) {
            printf("-1\n");
            continue;
        }
        printf("%I64d\n", _min + k);
    }
    return 0;
}
