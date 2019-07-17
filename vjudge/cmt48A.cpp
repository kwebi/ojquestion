#include <stdio.h>

const int maxn = 305;
int par[maxn];
int rank[maxn];

void init(int n)
{
    for (int i = 0; i < n; ++i) {
        par[i] = i;
        rank[i] = 0;
    }
}

int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (rank[x] < rank[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rank[x] == rank[y])
            ++rank[x];
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
        int u, v;
        scanf("%d%d", &u, &v);
        unite(u, v);
    }
    int t = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!same(i, j)) {
                unite(i, j);
                t++;
            }
        }
    }

    if (t & 1) {
        printf("Illyasviel\n");
    } else {
        printf("Star-dust\n");
    }
    return 0;
}
