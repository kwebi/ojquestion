#include <stdio.h>
#include <algorithm>

using ll = long long;
using namespace std;

struct Line
{
    long long y1;
    long long y2;
};

const int maxn = 1e5 + 5;
ll k[maxn];
ll b[maxn];
Line line[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    ll x1, x2;
    scanf("%lld%lld", &x1, &x2);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld%lld", &k[i], &b[i]);
        line[i].y1 = x1 * k[i] + b[i];
        line[i].y2 = x2 * k[i] + b[i];
    }
    bool ans = false;
    stable_sort(line, line + n, [&ans](Line a, Line b) -> bool {
        if (a.y1 < b.y1 && a.y2 > b.y2 || a.y1 > b.y1 && a.y2 < b.y2)
        {
            ans = 1;
        }
        return a.y1 == b.y1 ? a.y2 < b.y2 : a.y1 < b.y1;
    });

    if (ans)
        puts("YES");
    else
        puts("NO");
    return 0;
}
