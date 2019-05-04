#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

typedef pair<int, int> Pr;

Pr W[20005];

Pr D[20005];

int D1[20005];

int C[20005];

int main()
{
    int n, k;
    int E[11];
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= 10; i++)
    {
        scanf("%d", &E[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &W[i].first);
        D[i].first = W[i].first;
        D[i].second = i;
        W[i].second = i;
    }
    sort(D + 1, D + n + 1, [](Pr a, Pr b) { return a.first == b.first ? a.second < b.second : a.first > b.first; });

    for (int i = 1; i <= n; ++i)
    {
        D1[D[i].second] = i;
    }

    for (int i = 1; i <= n; ++i)
    {
        C[i] = (D1[i] - 1) % 10 + 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        W[i].first += E[C[i]];
    }
    sort(W + 1, W + n + 1, [](Pr a, Pr b) { return a.first == b.first ? a.second < b.second : a.first > b.first; });

    if (k > 0)
        printf("%d", W[1].second);
    for (int i = 2; i <= k; i++)
        printf(" %d", W[i].second);
    return 0;
}
