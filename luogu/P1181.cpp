#include <stdio.h>

int a[100005];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    int sum = 0;
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] + sum > m)
        {
            sum = 0;
            ++res;
        }
        sum += a[i];
    }
    if (sum)
        ++res;
    printf("%d\n", res);
    return 0;
}
