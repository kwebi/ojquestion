#include <stdio.h>

const int maxm = 5e5 + 5;
const int maxn = 1e4 + 5;
const int INF = 2147483647;

struct edge {
    int cost, u, v;
};

edge es[maxm];
int n, m, s;

int d[maxn];

void BF(int s)
{
    d[s] = 0;

    while (true) {
        bool up = 0;
        for (int j = 1; j <= m; j++) {
            edge e = es[j];
            if (d[e.u] != INF && d[e.v] > d[e.u] + e.cost) {
                d[e.v] = d[e.u] + e.cost;
                up = 1;
            }
        }
        if (up == 0)
            break;
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].cost);
    }
    for (int i = 0; i <= n; i++) {
        d[i] = INF;
    }
    BF(s);
    for (int i = 1; i <= n; i++) {
        printf("%d ", d[i]);
    }

    return 0;
}
