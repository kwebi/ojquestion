#include <bits/stdc++.h>
const int N = 1e5;
int a[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    int jug = 0;
    if (sum % (4 * m) == 0)
    {
        jug = sum / (4 * m);
    }
    else
    {
        jug = sum / (4 * m) + 1;
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= jug)
        {
            count++;
        }
    }
    if (count < m)
    {
        printf("No");
    }
    else
    {
        printf("Yes");
    }
    return 0;
}