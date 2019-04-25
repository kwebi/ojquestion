#include <algorithm>
#include <stdio.h>

using namespace std;
const int N = 105;

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
    int count = 0;
    if (n > 0)
    {
        count++;
    }
    for (int i = 1; i < n; ++i)
    {
        while (a[i] == a[i - 1])
        {
            ++i;
        }
        count++;
    }
    printf("%d\n", count);
    if (n > 0)
    {
        printf("%d", a[0]);
    }
    for (int i = 1; i < n; ++i)
    {
        while (a[i] == a[i - 1])
        {
            ++i;
        }
        printf(" %d", a[i]);
    }
    return 0;
}
