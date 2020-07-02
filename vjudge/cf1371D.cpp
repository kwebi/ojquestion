#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[305][305];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        if (k % n == 0)
            printf("0\n");
        else
            printf("2\n");
        int i = 0, j = 0;
        memset(a, 0, sizeof(a));
        while (k--) {
            if (a[i][j]) {
                i += 1;
                i %= n;
            }
            a[i][j] = 1;
            i += 1;
            i %= n;
            j += 1;
            j %= n;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d", a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}