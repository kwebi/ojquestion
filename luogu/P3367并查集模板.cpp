#include <stdio.h>

const int maxn = 1e4 + 5;

int par[maxn];

void init(int n)
{
    for (int i = 0; i <= n; i++)
        par[i] = i;
}

int find(int x)
{
    if (x == par[x])
        return x;
    else
        return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y) {
        par[x] = y;
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &z, &x, &y);
        if (z == 1) {
            unite(x, y);
        } else if (z == 2) {
            if (same(x, y))
                printf("Y\n");
            else
                printf("N\n");
        }
    }
    return 0;
}
