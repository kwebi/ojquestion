#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];

int main()
{
    int q;
    scanf("%d", &q);
    for (int Q = 0; Q < q; Q++) {
        int n;
        scanf("%d", &n);
        unordered_map<int, int> ump;
        unordered_map<int, bool> vis;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            ump[a[i]]++;
        }
        int ans = 0;
        vector<int> v;
        for (auto& e : ump) {
            v.push_back(e.second);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            if (!vis[v[i]]) {
                ans += v[i];
                vis[v[i]] = 1;
            } else {
                while (v[i] >= 1 && vis[v[i]]) {
                    v[i]--;
                }
                if (v[i] > 0 && !vis[v[i]]) {
                    ans += v[i];
                    vis[v[i]] = 1;
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}