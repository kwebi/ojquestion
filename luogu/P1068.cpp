#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>

using namespace std;

const int N = 5005;

int main()
{
    vector<pair<int, int>> k;
    int n, m;
    scanf("%d%d", &n, &m);
    k.resize(n);
    int num = floor(m * 1.5);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &k[i].first, &k[i].second);
    }
    sort(k.begin(), k.end(), [](pair<int, int> a, pair<int, int> b) -> bool { return a.second == b.second ? a.first < b.first : a.second > b.second; });
    int line = k[num - 1].second;
    int count = 0;
    for (int i = 0; k[i].second >= line; ++i)
    {
        ++count;
    }
    printf("%d %d\n", line, count);
    for (int i = 0; k[i].second >= line; ++i)
    {
        printf("%d %d\n", k[i].first, k[i].second);
    }
    return 0;
}
