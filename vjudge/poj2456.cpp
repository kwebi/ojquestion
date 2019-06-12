#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn];
int n, c;

bool Jg(int d)
{
    int crt = 0;
    int i = 1;
    int num = 1;
    for (int j = 1; j < c; ++j)
    {
        while (i < n && a[i] - a[crt] < d)
        {
            ++i;
        }
        crt = i;
        if (i == n)
            return 0;
    }
    return 1;
}

int main()
{

    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int l = 0;
    int r = 1e9;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (Jg(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%d", l);
    return 0;
}
