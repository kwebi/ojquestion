#include <queue>
#include <stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 5e3 + 5;

const int INF = 0x7fffffff;

typedef pair<int, int> P;

struct edge
{
    int cost, to;
    edge(int c, int t) : to(t), cost(c) {}
};

vector<edge> G[maxn];

int dist[maxn];
int dist2[maxn];

int main()
{
    int n, r;
    scanf("%d%d", &n, &r);
    for (int i = 0; i < r; ++i)
    {
        int u, v, cost;
        scanf("%d%d%d", &u, &v, &cost);
        --u;
        --v;
        G[u].push_back(edge(cost, v));
        G[v].push_back(edge(cost, u));
    }
    priority_queue<P, vector<P>, greater<P>> pque;
    fill(dist, dist + n, INF);
    fill(dist2, dist2 + n, INF);
    dist[0] = 0;
    pque.push(P(0, 0));
    while (!pque.empty())
    {
        P p = pque.top();
        pque.pop();
        int v = p.second, d = p.first;
        if (dist2[v] < d)
            continue;
        for (int i = 0; i < G[v].size(); ++i)
        {
            edge e = G[v][i];
            int d2 = d + e.cost;
            if (dist[e.to] > d2)
            {
                swap(dist[e.to], d2);//交换
                pque.push(P(dist[e.to], e.to));
            }
            if (dist2[e.to] > d2 && dist[e.to] < d2)
            {
                dist2[e.to] = d2;
                pque.push(P(d2, e.to));
            }
        }
    }
    printf("%d", dist2[n - 1]);
    return 0;
}
