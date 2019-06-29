#include <stdio.h>

int a[35];

int main()
{
    int v, n;
    scanf("%d%d", &v, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    return 0;
}