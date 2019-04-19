#include <stdio.h>

const int N = 3e5;

int a[N];
char s[N][15];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %s", &a[i], s[i]);
    }
    int p = 0;
    for (int i = 0; i < m; ++i)
    {
        int ai, si;
        scanf("%d%d", &ai, &si);
        if ((a[p] == 0 && ai == 1) || (a[p] == 1 && ai == 0))
        {
            p += si % n;
            p %= n;
        }
        else
        {
            p += n;
            p -= si % n;
            p %= n;
        }
    }
    printf("%s", s[p]);
    return 0;
}
