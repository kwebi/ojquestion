#include <algorithm>
#include <stdio.h>
using namespace std;

int a[105][105];
int Down[105][105];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            Down[i][j] = a[i][j];
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (Down[i][j] != 0 && Down[i - 1][j] != 0) {
                Down[i][j] = Down[i - 1][j] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            int len = Down[i][j];
            if (len == 0)
                continue;
            ans = max(1, ans);
            for (int k = j + 1; k <= m && len >= k - j + 1; k++) {
                if (Down[i][k] >= k - j + 1) {
                    ans = max(ans, k - j + 1);
                } else {
                    break;
                }
            }
        }
    }
    printf("%d", ans);

    return 0;
}
