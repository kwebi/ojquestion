#include <stdio.h>
#include <algorithm>

using namespace std;

int a[13];

int C(int u, int d)
{
    if (u > d / 2)
        u = d - u;
    int a = 1, b = 1;
    for (int i = 0; i < u; ++i)
    {
        a *= (d - i);
        b *= (i + 1);
    }
    return a / b;
}

int main()
{
    int n, sum;
    scanf("%d%d", &n, &sum);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    do
    {
        int r = 0;
        for (int i = 0; i < n; i++)
        {
            r += a[i] * C(i, n - 1);
            if (r > sum)
                sort(a + i + 1, a + n, [](int x, int y) { return x > y; });
        }
        if (r == sum)
        {
            for (int i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }
            break;
        }
    } while (next_permutation(a, a + n));

    return 0;
}
