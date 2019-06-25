#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;

const int maxm = 5e5 + 5;
const int maxn = 1e4 + 5;
const int INF = 2147483647;

struct edge {
    int cost, v;
};

typedef pair<int, int> pii;

vector<edge> G[maxn];
int n, m, s;

int dis[maxn];

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> que;
    fill(dis, dis + n + 1, INF);
    dis[s] = 0;
    que.push(pii(0, s));
    while (!que.empty()) {
        pii p = que.top();
        que.pop();
        int v = p.second;
        if (dis[v] < p.first)
            continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            if (dis[v] < INF && dis[e.v] > dis[v] + e.cost) {
                dis[e.v] = dis[v] + e.cost;
                que.push(pii(dis[e.v], e.v));
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; i++) {
        edge e;
        int u;
        scanf("%d%d%d", &u, &e.v, &e.cost);
        G[u].push_back(e);
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        printf("%d ", dis[i]);
    }

    return 0;
}
