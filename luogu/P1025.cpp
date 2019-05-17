#include <stdio.h>
#include <string.h>

int a[300][10];

int main()
{
    memset(a, 0, sizeof(a));
    int n, k;
    scanf("%d%d", &n, &k);
    a[1][1] = 1;
    a[2][2] = 1;
    for (int i = 1; i <= n; ++i)
        a[i][1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 2; j <= i && j <= 6; ++j)
            a[i][j] = a[i - 1][j - 1] + a[i - j][j];
    }
    printf("%d\n",a[n][k]);
    return 0;
}
