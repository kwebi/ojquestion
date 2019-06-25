#include <cstring>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;

const int maxm = 2e5 + 5;
const int maxn = 2e5 + 5;
const int INF = 2147483647;

struct edge {
    int w, to, next;
} es[maxm];

int n, m;

long long dis[maxn];//到各个点的距离
long long num[maxn];//进入队列次数
bool vis[maxn];//是否在队列中
int head[maxn];//每个点连接的一条边，通过next遍历连接该点每一条边
int cnt = 0;//边的序号

void init()
{
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v, int w)//链式向前星式建图
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
            if (dis[u] < INF && dis[u] + es[i].w < dis[to]) {//是否松弛
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
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        init();
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++) {
            int u, v, cost;
            scanf("%d%d%d", &u, &v, &cost);
            if (cost < 0) {
                addEdge(u, v, cost);
            } else {
                addEdge(u, v, cost);
                addEdge(v, u, cost);
            }
        }

        int ans = spfa(1);
        if (ans) {
            printf("YE5\n");
        } else {
            printf("N0\n");
        }
    }
    return 0;
}
