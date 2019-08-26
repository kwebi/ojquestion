#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1601;

char s1[N][20];
char s2[N][20];

map<ull, int> h;
const int seed = 31;

int main()
{
    int T;
    scanf("%d", &T);
    int cas = 0;
    while (T--) {
        h.clear();
        printf("Case %d: ", ++cas);
        int m, n;
        scanf("%d%d", &m, &n);
        getchar();
        for (int i = 0; i < m; i++) {
            gets(s1[i]);
        }
        for (int i = 0; i < n; i++) {
            gets(s2[i]);
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int l1 = strlen(s1[i]);
            ull tmp = 0;
            for (int k = 0; k < l1; k++) {
                tmp = tmp * seed + s1[i][k] - 'a' + 1;
            }
            for (int j = 0; j < n; j++) {
                int l2 = strlen(s2[j]);
                ull t = tmp;
                for (int k = 0; k < l2; k++) {
                    t = t * seed + s2[j][k] - 'a' + 1;
                }
                if (h[t] == 0) {
                    h[t]++;
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}