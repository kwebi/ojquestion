#include <bits/stdc++.h>
using namespace std;
char str[2010];
map<char, int> mcnt;
int n, k;
int solve()
{
    for (int len = n; len >= 1; len--) {
        int ax = __gcd(len, k);
        int need = len / ax;
        int all = 0;
        for (auto e : mcnt) {
            all += e.second / need;
        }
        if (all * need >= len) {
            return len;
        }
    }
    return 1;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        mcnt.clear();
        scanf("%d%d", &n, &k);
        scanf("%s", str);
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            mcnt[str[i]]++;
        }
        int ans = solve();

        printf("%d\n", ans);
    }
    return 0;
}