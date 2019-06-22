#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

const int maxn = 105;
int a[maxn];
int dpl[maxn];
int dpr[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        fill(dpl, dpl + n, 0);
        int la = 1;
        for (int j = 0; j <= i; j++) {
            dpl[j] = 1;
            if (a[j] >= a[i] && i != j) {
                continue;
            }
            for (int k = j - 1; k >= 0; k--) {
                if (a[j] > a[k]) {
                    dpl[j] = max(dpl[j], dpl[k] + 1);
                }
            }
            la = max(la, dpl[j]);
        }
        fill(dpr, dpr + n, 0);
        int ra = 1;
        for (int j = i; j < n; j++) {
            dpr[j] = 1;
            if (a[j] >= a[i] && i != j)
                continue;
            for (int k = j - 1; k >= i; k--) {
                if (a[j] < a[k]) {
                    dpr[j] = max(dpr[j], dpr[k] + 1);
                }
            }
            ra = max(ra, dpr[j]);
        }
        ans = max(ans, la + ra - 1);
    }
    printf("%d", n - ans);

    return 0;
}
