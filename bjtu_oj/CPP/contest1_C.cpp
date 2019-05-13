#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

const int maxn = 1005;

using ll = long long;

int a[maxn];
vector<int> ans;

int main()
{
    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;
    long long sum = 0;
    int low = 0;
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &a[i]);
        if (a[i] < y)
            ++low;

        sum += a[i];
    }
    if (low > n / 2)
    {
        cout << -1 << endl;
        return 0;
    }
    int n1 = min(n / 2 - low, n - k);
    int n2 = (n - k - n1);
    if (n1 + n2 * y + sum > x)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n1; ++i)
    {
        cout << 1 << ' ';
    }
    for (int i = 0; i < n2; ++i)
    {
        cout << y << ' ';
    }
    cout << endl;

    return 0;
}
