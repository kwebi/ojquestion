#include <algorithm>
#include <stdio.h>

using namespace std;

const int N = 10005;

int a[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int res = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        a[i + 1] += a[i];
        res += a[i + 1];
        int j = i + 1;
        while (j < n - 1 && a[j] > a[j + 1])
        {
            swap(a[j], a[j + 1]);
            ++j;
        }
    }
    printf("%d\n", res);
    return 0;
}
