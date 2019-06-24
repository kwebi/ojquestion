#include <algorithm>
#include <stdio.h>
using namespace std;

const int maxm = 2e5 + 5;
const int maxn = 5e3 + 5;
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

struct edge {
    int cost, u, v;
};

edge es[maxm];
int n, m;

bool cmp(const edge& a, const edge& b)
{
    return a.cost < b.cost;
}

int Kruskal()
{
    init(n);
    sort(es, es + m, cmp);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            ans += e.cost;
            unite(e.u, e.v);
        }
    }
    return ans;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].cost);
    }
    int ans = Kruskal();
    bool ok = 1;
    for (int i = 1; i <= n; i++) {
        if (!same(i, 1))
            ok = 0;
    }
    if (!ok)
        printf("orz\n");
    else
        printf("%d\n", ans);

    return 0;
}
