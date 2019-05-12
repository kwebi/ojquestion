#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1005;

bool a[maxn][maxn];

int main()
{
    memset(a, 1, sizeof(a));
    int n, k;
    cin >> n >> k;
    int count = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (count == k)
            break;
        for (int j = 1; j <= n; ++j)
        {
            if (count == k)
                break;
            a[i][j] = (i + j) & 1;
            count += a[i][j] == 0 ? 1 : 0;
        }
    }
    if (count == k)
    {
        cout << "YES" << endl;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (a[i][j] == 0)
                {
                    cout << 'L';
                }
                else
                {
                    cout << 'S';
                }
            }
            cout << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
