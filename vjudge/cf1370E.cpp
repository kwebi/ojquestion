#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 11;
char s1[N];
char s2[N];
set<int> st[2];
int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", s1);
    scanf("%s", s2);
    int cnt[2] = { 0, 0 };
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            if (s1[i] == '0')
                cnt[0]++;
            if (s2[i] == '0')
                cnt[1]++;
            st[s1[i] == '0'].insert(i);
        }
    }
    if (cnt[0] != cnt[1]) {
        printf("-1");
        return 0;
    }

    int nw = 0;
    int ans = 0;
    while (!st[0].empty()) {
        int x = *st[0].begin();
        int y = *st[1].begin();
        if (x < y) {
            nw = 0;
        } else {
            nw = 1;
            x = y;
        }
        ans++;
        while (true) {
            auto it = st[nw].lower_bound(x);
            if (it == st[nw].end())
                break;
            x = *it;
            nw ^= 1;
            auto it2 = st[nw].lower_bound(x);
            if (it2 == st[nw].end())
                break;
            x = *it2;
            st[nw].erase(it2);
            st[nw ^ 1].erase(it);
            nw ^= 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}