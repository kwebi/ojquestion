#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

const int N = 5005;

typedef pair<int, int> pr;

int main()
{
    pr p[N];
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &p[i].first, &p[i].second);
    }
    sort(p, p + m, [](pr a, pr b) { return a.first < b.first; });
    long long ans = 0;
    int count = 0;
    for (int i = 0; i < m; ++i)
    {
        if (count + p[i].second <= n)
        {
            count += p[i].second;
            ans += p[i].second * p[i].first;
        }
        else
        {
            ans += p[i].first * (n - count);
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
