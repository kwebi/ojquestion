#include <stdio.h>

const int N = 2e4;
int a[N];
int b[N];

int score(int a, int b)
{
    if (a == b)
        return 0;
    else if (a == 0)
    {
        if (b == 2 || b == 3)
            return 1;
    }
    else if (a == 1)
    {
        if (b == 3 || b == 0)
            return 1;
    }
    else if (a == 2)
    {
        if (b == 4 || b == 1)
            return 1;
    }
    else if (a == 3)
    {
        if (b == 4 || b == 2)
            return 1;
    }
    else if (a == 4)
    {
        if (b == 0 || b == 1)
            return 1;
    }
    return 0;
}

int main()
{
    int n, na, nb;
    scanf("%d%d%d", &n, &na, &nb);
    for (int i = 0; i < na; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < nb; ++i)
    {
        scanf("%d", &b[i]);
    }
    int sa = 0;
    int sb = 0;
    for (int i = 0; i < n; ++i)
    {
        sa += score(a[i % na], b[i % nb]);
        sb += score(b[i % nb], a[i % na]);
    }
    printf("%d %d\n", sa, sb);
    return 0;
}
