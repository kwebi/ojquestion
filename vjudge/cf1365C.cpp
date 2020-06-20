#include <algorithm>
#include <map>
#include <stdio.h>
using namespace std;
int a[400100];
int ar[400100];
int b[400100];
int br[400100];

map<int, int> mp;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        ar[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        br[b[i]] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        mp[ar[i] - br[i]]++;
        mp[ar[i] + n - br[i]]++;
        ans = max(ans, mp[ar[i] - br[i]]);
        ans = max(ans, mp[ar[i] + n - br[i]]);
    }
    printf("%d", ans);
    return 0;
}
