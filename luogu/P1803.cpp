#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pr;

pr a[1000005];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    sort(a, a + n, [](pr a1, pr b) { return a1.second < b.second; });
    int ans = 0;
    int last;
    if (n > 0)
    {
        last = a[0].second;
        ++ans;
    }
    for (int i = 0; i < n; ++i)
    {
        if (a[i].first >= last)
        {
            last = a[i].second;
            ++ans;
        }
    }
    printf("%d\n",ans);
    return 0;
}
