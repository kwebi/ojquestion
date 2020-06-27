#include <bits/stdc++.h>
char s[1000010];
using namespace std;
typedef long long ll;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        int bg = 0;
        int ed = 2e9;
        ll ans = 0;
        int len = strlen(s);
        vector<int> v(len + 10);
        vector<int> vpos(len + 10);
        for (int i = 0; i < len; i++) {
            if (s[i] == '+')
                v[i] = 1;
            else
                v[i] = -1;
        }
        for (int i = 1; i < len; i++) {
            v[i] += v[i - 1];
        }
        for (int i = len - 1; i >= 0; i--) {
            if (v[i] < 0) {
                vpos[-v[i]] = i + 1;
            }
        }
        for (int i = 0; i <= len; i++) {
            ans += vpos[i];
            //cout << ans << endl;
        }

        ans += len;

        printf("%lld\n", ans);
    }
    return 0;
}