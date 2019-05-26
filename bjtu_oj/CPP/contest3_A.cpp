//http://citel.bjtu.edu.cn/vjudge/contest/view.action?cid=329#rank
#include <cmath>
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[105];
int b[105];

int main()
{
    int n, x0;
    scanf("%d%d", &n, &x0);
    int max_d = -1;
    int min_d = 1005;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &a[i], &b[i]);
        if (a[i] > b[i])
            swap(a[i], b[i]);
        if (a[i] > max_d)
            max_d = a[i];
        if (b[i] < min_d)
            min_d = b[i];
    }
    if (min_d < max_d)
        return puts("-1"), 0;
    if (x0 >= max_d && x0 <= min_d)
        return puts("0"), 0;
    int d = min(abs(x0 - min_d), abs(x0 - max_d));
    printf("%d", d);
    return 0;
}
