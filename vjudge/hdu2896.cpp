#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

queue<int> q;
vector<int> ans[1010];
struct ACauto {
    int ch[N][130], val[N], fail[N], cnt;
    unordered_map<int, bool> vis;
    void ins(char* s, int v)
    {
        int len = strlen(s), u = 0;
        for (int i = 0; i < len; i++) {
            int v = s[i];
            if (!ch[u][v])
                ch[u][v] = ++cnt;
            u = ch[u][v];
        }
        val[u] = v;
    }
    void getFail()
    {
        for (int i = 0; i < 130; i++) {
            if (ch[0][i]) {
                fail[ch[0][i]] = 0;
                q.push(ch[0][i]);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 130; i++) {
                if (ch[u][i]) {
                    fail[ch[u][i]] = ch[fail[u]][i];
                    q.push(ch[u][i]);
                } else
                    ch[u][i] = ch[fail[u]][i];
            }
        }
    }
    void query(char* s, int v)
    {
        vis.clear();
        int len = strlen(s);
        int u = 0;
        for (int i = 0; i < len; i++) {
            u = ch[u][s[i]];
            for (int t = u; t; t = fail[t]) {
                if (val[t]&&!vis[val[t]]){
                    ans[v].push_back(val[t]);
                    vis[val[t]]=1;
                }
            }
        }
        sort(ans[v].begin(),ans[v].end());
    }
} AC;

char s[10010];

int main()
{
    int n;
    scanf("%d", &n);
    char st[210];
    for (int i = 1; i <= n; i++) {
        scanf("%s", st);
        AC.ins(st, i);
    }
    AC.getFail();
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%s", s);
        AC.query(s, i);
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (ans[i].size()) {
            cnt++;
            printf("web %d:", i);
            for (int j = 0; j < ans[i].size(); j++) {
                printf(" %d", ans[i][j]);
            }
            printf("\n");
        }
    }
    printf("total: %d\n", cnt);
    return 0;
}
