#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int M = 5e5 + 5;
char s[M * 2];

struct ACauto {
    int val[M], ch[M][26], sz, fail[M];
    void init()
    {
        sz = 0, memset(ch[0], 0, sizeof(ch[0])), memset(val, 0, sizeof(val));
        memset(fail, 0, sizeof(fail));
    }
    void ins(char* s)
    {
        int len = strlen(s), u = 0;
        for (int i = 0; i < len; i++) {
            int v=s[i]-'a';
            if (!ch[u][v]) {
                ++sz;
                memset(ch[sz], 0, sizeof(ch[sz]));
                ch[u][v] = sz;
            }
            u = ch[u][v];
        }
        val[u]++;
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
                int v = ch[u][i];
                if (v)
                    fail[v] = ch[fail[u]][i], q.push(v);
                else
                    ch[u][i] = ch[fail[u]][i];
            }
        }
    }
    int query(char* s){
        int len=strlen(s),u=0,ans=0;
        for(int i=0;i<len;i++){
            int v=s[i]-'a';
            u=ch[u][v];
            for(int t=u;t&&~val[t];t=fail[t])ans+=val[t],val[t]=-1;
        }
        return ans;
    }
} AC;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        AC.init();
        int n;
        scanf("%d", &n);
        char ts[60];
        for (int i = 1; i <= n; i++) {
            scanf("%s", ts);
            AC.ins(ts);
        }
        scanf("%s", s);
        AC.getFail();
        printf("%d\n",AC.query(s));
    }
    return 0;
}
