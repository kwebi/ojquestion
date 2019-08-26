#include <stdio.h>

const int maxn = 1e5 + 5;

int a[maxn];

int main()
{
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    int _min = 0, _max = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        _min += a[i];
        _max += a[i];

        if (a[i] == 0)
        {
            if (_min < 0)
                _min = 0;
            if (_max < 0)
            {
                _max = d;
                ++ans;
            }
        }
        else
        {
            if (_min > d)
                return puts("-1"), 0;
            if (_max > d)
                _max = d;
        }
    }
    printf("%d", ans);
    return 0;
}
