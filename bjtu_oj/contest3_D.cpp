#include <stdio.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int maxn = 505 * 505;

int a[maxn];
unordered_map<int, int> um;
int pre[505];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n * n; ++i)
    {
        scanf("%d", &a[i]);
        um[a[i]] += 1;
    }
    stable_sort(a, a + n * n, [](int x, int y) { return x > y; });

    int cnt = 0;
    for (int i = 0; i < n * n; ++i)
    {
        if (um[a[i]] > 0)
        {
            printf("%d ", a[i]);
            um[a[i]] -= 1;
            for (int j = 0; j < cnt; ++j)
            {
                um[gcd(a[i], pre[j])] -= 2;
            }
            pre[cnt++] = a[i];
        }
    }
    puts("\n");

    return 0;
}
