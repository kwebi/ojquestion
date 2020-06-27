#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll maxSum(vector<int>& v)
{
    ll last = 0;
    ll ret = 0;
    for (int i = 0; i < v.size(); i++) {
        last = last < 0 ? 0 : last;
        ret = max(ret, last + v[i]);
        last += v[i];
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector<int> a(n + 10);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        vector<int> v1;
        vector<int> v2;
        for (int i = 1; i < n; i += 2) {
            v1.push_back(a[i] - a[i - 1]);
        }
        ll ans = maxSum(v1);
        for (int i = 1; i < n - 1; i += 2) {
            v2.push_back(a[i] - a[i + 1]);
        }
        ans = max(ans, maxSum(v2));
        for (int i = 0; i < n; i += 2) {
            ans += a[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
