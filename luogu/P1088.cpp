#include <algorithm>
#include <stdio.h>
using namespace std;

const int MAXN = 1e4 + 5;

int a[MAXN];

int main()
{
    int n, m;

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    int cnt = 0;
    while (cnt < m)
    {
        for (int i = n; i > 1; --i)
        {
            if (a[i] > a[i - 1])
            {
                int j;
                for (int k = n; k >= i; --k)
                {
                    if (a[i - 1] < a[k])
                    {
                        j = k;
                        break;
                    }
                }
                swap(a[i - 1], a[j]);
                sort(a + i, a + 1 + n);
                cnt++;
                break;
            }
        }
    }
    printf("%d", a[1]);
    for (int i = 2; i <= n; ++i)
        printf(" %d", a[i]);
    return 0;
}
