#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

char s[N][20];
int Trie[N][13];
bool v[N];
int cnt = 1;

bool _insert(char s[])
{
    int root = 0;
    int len = strlen(s);
    bool f=1;
    for (int i = 0; i < len; i++) {
        int next = s[i] - '0';
        if (!Trie[root][next]){
            f=0;
            Trie[root][next] = ++cnt;
        }
        if(v[root])return true;
        root = Trie[root][next];
    }
    v[root] = 1;
    return f;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(Trie, 0, sizeof(Trie));
        memset(v, 0, sizeof(v));
        cnt = 1;
        int n;
        scanf("%d", &n);
        bool f = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", s[i]);
            if (f)
                continue;
            bool tmp = _insert(s[i]);
            if (tmp)
                f = 1;
        }
        if (f)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
