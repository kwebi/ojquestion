#include <bits/stdc++.h>
using namespace std;
int a[200010];
int w[200010];
int n, k;
typedef long long ll;

int cmp(int a, int b)
{
    return b < a;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < k; i++) {
            scanf("%d", &w[i]);
        }
        sort(a, a + n, cmp);
        sort(w, w + k);
        ll ans = 0;
        for (int i = 0; i < k; i++) {
            ans += a[i];
            //cout << ans << endl;
        }
        int j = k - 1;
        for (int i = 0; i < k; i++) {
            if (w[i] == 1) {
                ans += a[i];
                continue;
            }
            j += w[i] - 1;
            ans += a[j];
            // cout << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}