#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

ll a[410];
ll Mx[410][410];
ll Mi[410][410];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]),a[i+n]=a[i];
    for (int i = 1; i <=2*n; i++)
        a[i] += a[i - 1];
    for (int l = 1; l < n; l++) {
        for (int i = 1; i+l <= 2*n; i++) {
            int j = i + l;
            ll t = a[j]-a[i-1];
            Mi[i][j]=1e9;
            for (int k = i; k < j; k++) {
                Mi[i][j] = min(Mi[i][k] + Mi[k + 1][j] + t, Mi[i][j]);
                //printf("%d %d %d\n",i,j,Mi[i][j]);
                Mx[i][j] = max(Mx[i][k] + Mx[k + 1][j] + t, Mx[i][j]);
            }
        }
    }
    ll ans1 = 1e9;
    ll ans2 = 0;
    for (int i = 1; i <= n; i++) {
        ans1 = min(ans1, Mi[i][i + n - 1]);
        //printf("%d %d %d\n",i,i+n-1,Mi[i][i+n-1]);
        ans2 = max(ans2, Mx[i][i + n - 1]);
    }
    printf("%lld\n", ans1);
    printf("%lld\n", ans2);
    return 0;
}
