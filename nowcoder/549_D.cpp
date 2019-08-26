#include <algorithm>
#include <stdio.h>
using namespace std;

typedef long long LL;
const int N = 1e6 + 10;
LL a[N];
LL l[N];
LL r[N];
int main()
{
    int n;
    long long res = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        l[i] = l[i - 1] | a[i];
    }
    for (int i = n; i >= 1; --i)
    {
        r[i] = r[i + 1] | a[i];
    }
    LL ans=0;
    for(int i=1;i<=n;++i)
    {
        LL tmp = l[i-1]|r[i+1];
        ans = ans>tmp?ans:tmp;
    }
    printf("%lld\n", ans);
    return 0;
}
