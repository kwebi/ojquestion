#include <cmath>
#include <deque>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];
int sum[maxn];
int cnt[105];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum[i] = a[i];
        sum[i] += sum[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        int ans = 0;
        if (sum[i] > m) {
            int d = sum[i];
            for (int j = 100; j > 0; j--) {
                if (d - cnt[j] * j > m) {
                    ans += cnt[j];
                    d -= cnt[j] * j;
                } else {
                    ans += ceil((d - m) / double(j));
                    break;
                }
            }
        }
        cnt[a[i]]++;
        printf("%d ",ans);
    }

    return 0;
}
