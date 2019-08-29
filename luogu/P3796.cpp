#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N = 1e6 + 5;
char s[N];
char p[160][80];
int n;

struct ACauto {
    int ch[N][26], val[N], fail[N], cnt, ans[160];
    void init()
    {
        memset(ch, 0, sizeof(ch));
        memset(val, 0, sizeof(val));
        memset(fail, 0, sizeof(fail));
        memset(ans, 0, sizeof(ans));
        cnt = 0;
    }
    void ins(char* s, int v)
    {
        int len = strlen(s), u = 0;
        for (int i = 0; i < len; i++) {
            int v = s[i] - 'a';
            if (!ch[u][v])
                ch[u][v] = ++cnt;
            u = ch[u][v];
        }
        val[u] = v;
    }
    void getFail()
    {
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (ch[0][i]) {
                fail[ch[0][i]] = 0;
                q.push(ch[0][i]);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (ch[u][i]) {
                    fail[ch[u][i]] = ch[fail[u]][i];
                    q.push(ch[u][i]);
                } else
                    ch[u][i] = ch[fail[u]][i];
            }
        }
    }
    void query(char* s)
    {
        int len = strlen(s);
        int u = 0;
        for (int i = 0; i < len; i++) {
            u = ch[u][s[i] - 'a'];
            for (int t = u; t; t = fail[t]) {
                ans[val[t]]++;
            }
        }
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            if (ans[i] > mx)
                mx = ans[i];
        }
        printf("%d\n", mx);
        for (int i = 1; i <= n; i++) {
            if (ans[i] == mx)
                printf("%s\n", p[i]);
        }
    }
} AC;

int main()
{

    while (~scanf("%d", &n)&&n) {
        AC.init();
        for (int i = 1; i <= n; i++) {
            scanf("%s", p[i]);
            AC.ins(p[i], i);
        }
        AC.getFail();
        scanf("%s", s);
        AC.query(s);
    }
    return 0;
}
