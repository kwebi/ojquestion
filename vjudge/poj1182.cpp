#include <stdio.h>

const int maxn = 3e5 + 5;
int par[maxn];
int rank[maxn];

void init(int n)
{
    for (int i = 0; i < n; ++i)
    {
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
    if (rank[x] < rank[y])
    {
        par[x] = y;
    }
    else
    {
        par[y] = x;
        if (rank[x] == rank[y])
            ++rank[x];
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

struct Word
{
    int d;
    int x;
    int y;
} w[maxn];

int main()
{
    int n, k;
    scanf("%d%d",&n,&k);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d%d%d", &w[i].d, &w[i].x, &w[i].y);
    }
    init(n * 3);
    int ans = 0;
    for (int i = 0; i < k; ++i)
    {
        int x = w[i].x - 1;
        int y = w[i].y - 1;
        if (x < 0 || x >= n || y < 0 || y >= n)
        {
            ++ans;
            continue;
        }
        if (w[i].d == 1)
        {
            if (same(x, y + n) || same(x, y + n * 2))
                ++ans;
            else
            {
                unite(x, y);
                unite(x + n, y + n);
                unite(x + n * 2, y + n * 2);
            }
        }
        else
        {
            if (same(x, y) || same(x, y + n * 2))
            {
                ++ans;
            }
            else
            {
                unite(x, y + n);
                unite(x + n, y + n * 2);
                unite(x + n * 2, y);
            }
        }
    }
    printf("%d",ans);
    return 0;
}
