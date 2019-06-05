#include <stdio.h>

const int maxn = 3e4 + 5;

int v[30]; //重要程度*价格
int w[30]; //价格
int f[maxn];

inline int _max(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &w[i], &v[i]);
        v[i] *= w[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int c = n; c >= w[i]; --c)
        {
            f[c] = _max(f[c], f[c - w[i]] + v[i]);
        }
    }
    printf("%d", f[n]);

    return 0;
}
