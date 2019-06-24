#include <algorithm>
#include <stdio.h>
using namespace std;

int a[55][55];
int b[55][55];
int f[110][55][55];

int max(int a, int b, int c, int d)
{
    return max(max(a, b), max(c, d));
}

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            b[i][j] = a[i][j];
        }
    }
    for (int k = 2; k <= m + n - 1; k++) {
        for (int i = 1; i <= m && i < k; i++) {
            for (int j = 1; j <= m && j < k; j++) {
                if (i <= j)
                    continue;
                f[k][i][j] = a[i][k - i] + a[j][k - j] + max(f[k - 1][i][j], f[k - 1][i - 1][j], f[k - 1][i - 1][j - 1], f[k - 1][i][j - 1]);
            }
        }
    }
    printf("%d", f[m + n - 1][m][m - 1]);

    return 0;
}
