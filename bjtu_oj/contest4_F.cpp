#include <algorithm>
#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

typedef long long ll;

int a[25];
int b[25];
int n;
unordered_map<int, int> ump;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b, b + n);
    for (int i = 0; i < n; ++i)
    {
        ump[b[i]] = i;
    }
    for (int i = 0; i < n; ++i)
    {
        int p =(ump[a[i]] + 1) % n;
        printf("%d ", b[p]);
    }

    return 0;
}
