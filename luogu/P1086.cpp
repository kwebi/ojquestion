#include <cmath>
#include <stdio.h>

int a[30][30];

int main()
{
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int num = 0;
    int usedtime = 0;
    int curi = 0, curj;
    while (usedtime < k)
    {
        int nMax = 0, nMaxi, nMaxj;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (a[i][j] > nMax)
                {
                    nMax = a[i][j];
                    nMaxi = i;
                    nMaxj = j;
                }
            }
        }
        if (nMax == 0)
            break;
        if (curi == 0)
            curj = nMaxj;
        if (usedtime + nMaxi + 1 + abs(nMaxi - curi) + abs(nMaxj - curj) <= k)
        {
            usedtime += 1 + abs(nMaxi - curi) + abs(nMaxj - curj);
            curi = nMaxi;
            curj = nMaxj;
            num += a[nMaxi][nMaxj];
            a[nMaxi][nMaxj] = 0;
        }
        else
            break;
    }
    printf("%d\n", num);

    return 0;
}
