#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

const int N = 1005;

typedef pair<int, int> pr;

pr a[N];

int s[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        a[i].first = i + 1;
        scanf("%d", &a[i].second);
        s[i] = a[i].second;
    }
    for (int i = 1; i < n; ++i)
    {
        s[i] += s[i - 1];
    }
    sort(a, a + n, [](pr a, pr b) { return a.second < b.second; });
    double ans = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        ans += a[i].second * (n - i - 1);
    }
    if(n>0)
        printf("%d",a[0].first);
    for(int i=1;i<n;++i)
    {
        printf(" %d",a[i].first);
    }
    printf("\n");
    printf("%.2lf\n", ans / double(n));
    return 0;
}
