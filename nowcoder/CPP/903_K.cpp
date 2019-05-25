#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <map>
#include <string>

using namespace std;
const int maxn = 1e3 + 5;

map<string, pair<int, int>> hm;
using cai = pair<string, pair<int, int>>;

string s[maxn];
int a[maxn];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        string s;
        int a;
        cin >> s >> a;
        hm[s].first = a;
        hm[s].second = i;
    }
    for (int i = 0; i < m; ++i)
    {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; ++j)
        {
            string s;
            int a;
            cin >> s >> a;
            hm[s].first -= a;
            if (hm[s].first < 0)
            {
                return puts("NO"), 0;
            }
        }
    }
    puts("YES");
    for (auto &e : hm)
    {
        s[e.second.second] = e.first;
        a[e.second.second] = e.second.first;
    }
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0)
            continue;
        cout << s[i] << " " << a[i] << endl;
    }

    return 0;
}
