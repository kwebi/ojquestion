#include<string.h>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;

const int maxm = 5e5 + 5;
const int maxn = 1e4 + 5;
const int INF = 2147483647;


struct edge {
    int w, to, next;
} es[maxm];

int n, m, s;

long long dis[maxn];
long long num[maxn];
bool vis[maxn];
int head[maxn];
int cnt = 0;

void init()
{
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v, int w)
{
    es[cnt].to = v;
    es[cnt].w = w;
    es[cnt].next = head[u];
    head[u] = cnt++;
}

int spfa(int pos)
{
    memset(vis, 0, sizeof(vis)); //标记是否在队列
    memset(num, 0, sizeof(num)); //记录各顶点松弛次数(即进队列的次数)
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[pos] = 0;
    queue<int> q;
    q.push(pos);
    vis[pos] = true;
    num[pos]++;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = head[u]; i != -1; i = es[i].next) {
            int to = es[i].to;
            if (dis[u] < INF && dis[u] + es[i].w < dis[to]) {
                dis[to] = dis[u] + es[i].w;
                if (!vis[to]) {
                    q.push(to);
                    vis[to] = true;
                    num[to]++;
                    if (num[to] >= n) //当某顶点松弛次数大于或等于 n 时，存在负权回路
                        return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d%d", &n, &m, &s);
    init();
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
    }
    spfa(s);
    for (int i = 1; i <= n; i++) {
        printf("%d ", dis[i]);
    }

    return 0;
}
