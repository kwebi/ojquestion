#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main() {
    int t;
    cin >> t;
    int i;
    for (i = 0; i < t; i++) {
        int n;
        int v[380];
        int dp[380];
        memset(v, 0, sizeof(v));
        memset(dp, 0, sizeof(dp));
        cin >> n;
        int j;
        for (j = 0; j < n; j++) {
            scanf("%d", &v[j]);
        }
        int ans = 0;
        int k;
        for (j = 0; j < n; j++) {
            for (k = 180; k >= v[j]; k--) {
                dp[k] = max(dp[k], dp[k-v[j]] + v[j]);
                ans = max(ans, dp[k]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
