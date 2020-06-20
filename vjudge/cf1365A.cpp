#include <stdio.h>
#include <string.h>
int a[100][100];
int row[100];
int col[100];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        int n, m;

        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
                if (a[i][j] == 1) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        int now = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] || col[j])
                    continue;
                now++;
                row[i] = 1;
                col[j] = 1;
            }
        }
        if (now % 2 == 1) {
            printf("Ashish\n");
        } else {
            printf("Vivek\n");
        }
    }
}