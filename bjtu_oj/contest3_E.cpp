#include <stdio.h>
#include <math.h>
#include<stdlib.h>

const int maxn = 1e5 + 5;

int a[maxn];

int main()
{
    int x;
    scanf("%d", &x);
    x = abs(x);
    int t = 0;
    a[0] = 0;
    for (t = 0; a[t] < x; ++t)
    {
        a[t + 1] = (t + 1) * (t + 2) / 2;
    }
    if (a[t] == x)
        return printf("%d", t), 0;
    int d = a[t] - x;
    int p = t;
    while (d & 1)
    {
        ++p;
        a[p] = p * (p + 1) / 2;
        d = a[p] - x;
    }
    printf("%d",p);

    return 0;
}
