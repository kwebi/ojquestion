#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

const int maxr = 5e4 + 5;

struct edge
{
    int u, v, cost;
};

int par[maxr];
int mrank[maxr];
edge es[maxr];

void init(int n)
{
    for (int i = 0; i < n; ++i)
    {
        par[i] = i;
        mrank[i] = 0;
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
    if (mrank[x] < mrank[y])
    {
        par[x] = y;
    }
    else
    {
        par[y] = x;
        if (mrank[x] == mrank[y])
            ++mrank[x];
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

bool comp(const edge &e1, const edge &e2)
{
    return e1.cost < e2.cost;
}

int kruskal(int V, int E)
{
    int ans = 0;
    sort(es, es + E, comp);
    init(V);
    for (int i = 0; i < E; ++i)
    {
        edge e = es[i];
        if (!same(e.u, e.v))
        {
            ans += e.cost;
            unite(e.u, e.v);
        }
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t)
    {
        int n, m, r;
        scanf("%d%d%d", &n, &m, &r);
        int V = n + m;
        for (int i = 0; i < r; ++i)
        {
            scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].cost);
            es[i].v += n;
            es[i].cost *= -1;
        }
        printf("%d\n", 10000 * (n + m) + kruskal(V, r));
    }
    return 0;
}
