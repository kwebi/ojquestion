#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 2e5 + 5;
typedef pair<int, int> pii;
pii a[maxn];

inline bool solve(int d, int last, int l, int n, int skip)
{
    bool ok = 1;
    for (int i = l; i <= n; i++) {
        int t = a[i].first - a[last].first;
        if (t != d) {
            if (skip == -1) {
                skip = i;
            } else {
                ok = false;
            }
        } else {
            last = i;
        }
    }
    if (ok) {
        int ans;
        if (skip != -1)
            ans = a[skip].second;
        else
            ans = a[1].second;
        printf("%d\n", ans);
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    int last = 1;

    int d = a[2].first - a[1].first;
    bool ok = solve(d, last, 2, n, -1);
    if (!ok) {
        d = a[3].first - a[1].first;
        last = 3;
        ok = solve(d, last, 4, n, 2);
    }
    if (!ok) {
        if (n >= 3) {
            d = a[3].first - a[2].first;
            last = 3;
            ok = solve(d, last, 4, n, 1);
        }
        if (!ok) {
            printf("-1\n");
        }
    }

    return 0;
}
