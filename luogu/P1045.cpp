#include <stdio.h>
#include <cmath>
#include <cstring>

int f[550], res[550], sav[550]; //中间存储
inline void cheng(int f[], int res[])
{
    memset(sav, 0, sizeof(sav));
    sav[0] = f[0] + res[0];
    if (sav[0] > 500)
        sav[0] = 500;
    for (int i = 1; i <= f[0]; ++i)
    {
        for (int j = 1; j <= res[0]; ++j)
        {
            if (i + j - 1 > 505)
                break;
            sav[i + j - 1] += f[i] * res[j];
            if (sav[i + j - 1] >= 10)
            {
                sav[i + j] += sav[i + j - 1] / 10;
                sav[i + j - 1] %= 10;
            }
        }
    }
    memcpy(res, sav, sizeof(sav));
}

int main()
{
    memset(f, 0, sizeof(f));
    memset(res, 0, sizeof(res));
    int p;
    scanf("%d", &p);
    int bitnum;
    bitnum = p * log10(2) + 1;
    printf("%d\n", bitnum);
    f[0] = 1;
    res[0] = 1;
    res[1] = 1;
    f[1] = 2;
    while (p > 0)
    {
        if (p & 1)
        {
            cheng(f, res);
        }
        cheng(f, f);
        p >>= 1;
    }
    --res[1];
    for (int i = 500; i >= 1; --i)
    {
        if (i % 50 == 0 && i < 500)
            printf("\n");
        printf("%d", res[i]);
    }
    return 0;
}
