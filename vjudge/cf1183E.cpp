#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

const int maxn = 105;
typedef long long LL;

map<string, bool> mp;
vector<string> vs;
bool vis[maxn];
string str;
int n;
LL k;
LL ans = 0;
LL cnt = 0;

string pushin()
{
    string s;
    for (LL i = 0; i < vs[cnt].size(); i++) {
        if (!vis[i]) {
            s.push_back(vs[cnt][i]);
        }
    }
    return s;
}

void dfs()
{
    memset(vis, 0, sizeof(vis));
    for (LL i = 0; i < vs[cnt].size(); i++) {
        if (vs.size() == k)
            return;
        if (!vis[i]) {
            vis[i] = 1;
            string s = pushin();
            if (mp.count(s) == 0) {
                mp[s] = 1;
                vs.push_back(s);
            }
            vis[i] = 0;
        }
    }
    cnt++;
    if (cnt < vs.size()) {
        dfs();
    }
}

int main()
{
    scanf("%d%I64d", &n, &k);
    cin >> str;
    mp[str] = 1;
    vs.push_back(str);
    dfs();
    if (vs.size() < k) {
        printf("-1\n");
    } else {
        LL i = 0;
        for (auto& e : vs) {
            ans += n - e.size();
            i++;
            if (i == k)
                break;
        }
        printf("%I64d\n", ans);
    }

    return 0;
}