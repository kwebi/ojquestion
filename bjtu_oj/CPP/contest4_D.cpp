#include <cstring>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 1e5 + 5;

struct Node
{
    int v;
    int d;
};

vector<int> a;
vector<vector<int>> G;
bool vis[maxn];
bool vis_n[maxn];

int main()
{
    int n, m, k, s;
    scanf("%d%d%d%d", &n, &m, &k, &s);
    a.resize(n + 1);
    G.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        int cnt = 0;
        memset(vis, 0, sizeof(vis));
        memset(vis_n, 0, sizeof(vis_n));
        queue<Node> q;
        q.push(Node{i, 0});
        vis[a[i]] = 1;
        vis_n[i] = 1;
        cnt++;
        int w = 0;
        while (cnt < s)
        {
            Node t = q.front();
            q.pop();
            for (int j = 0; j < G[t.v].size(); ++j)
            {
                if (cnt == s)
                    break;
                int od = G[t.v][j];
                if (vis_n[od])
                    continue;
                q.push(Node{od, t.d + 1});
                vis_n[od] = 1;
                if (vis[a[od]])
                    continue;
                vis[a[od]] = 1;
                cnt += 1;
                w += t.d + 1;
                if (cnt == s)
                    break;
            }
        }
        printf("%d ", w);
    }
    return 0;
}
