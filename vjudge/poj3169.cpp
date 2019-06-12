#include <cstring>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 1e4 + 5;
const int INF = 0x7fffffff;
int d[maxn];
int n, ml, md;

struct edge
{
    int from, to, cost;
    edge() {}
    edge(int f, int t, int c) : from(f), to(t), cost(c) {}
};

edge es[maxn * 2];

bool shortest_path(int s, int V, int E)
{
    fill(d, d + n, INF);
    d[s] = 0;
    for (int j = 0; j < V; ++j)
    {
        for (int i = 0; i < E; ++i)
        {
            edge e = es[i];
            if (d[e.from] < INF && d[e.from] + e.cost < d[e.to])
            {
                d[e.to] = d[e.from] + e.cost;
            }
        }
    }
    for (int j = 0; j < E; ++j) //检测负环
    {
        edge e = es[j];
        if (d[e.from] < INF && d[e.from] + e.cost < d[e.to])
            return 0;
    }
    return 1;
}

int main()
{
    scanf("%d%d%d",&n,&ml,&md);
    for (int i = 0; i < ml; ++i)
    {
        int a, b, d;
        scanf("%d%d%d", &a, &b, &d);
        if (a > b)
            swap(a, b);
        es[i] = edge(a - 1, b - 1, d);
    }
    for (int i = ml; i < md + ml; ++i)
    {
        int a, b, d;
        scanf("%d%d%d", &a, &b, &d);
        if (a > b)
            swap(a, b);
        es[i] = edge(b - 1, a - 1, -d);
    }
    if (shortest_path(0, n, ml + md) == 0)
        return puts("-1"), 0;
    if (d[n - 1] == INF)
        puts("-2");
    else
        printf("%d\n", d[n - 1]);

    return 0;
}
