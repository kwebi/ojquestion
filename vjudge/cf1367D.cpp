#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

char st[2001];
int a[2010];
vector<vector<int>> vpos;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        vpos.clear();
        scanf("%s", st);
        int len = strlen(st);
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &a[i]);
        }
        while (true) {
            vector<int> v;
            for (int i = 0; i < m; i++) {
                if (a[i] == 0) {
                    v.push_back(i);
                }
            }
            if (v.empty())
                break;
            vpos.push_back(v);
            for (int p : v) {
                for (int i = 0; i < m; i++) {
                    a[i] -= abs(p - i);
                }
            }
            for (int p : v) {
                a[p] = 1e9;
            }
            // for (int i = 0; i < v.size(); i++) { //
            //     cout << v[i] << ' ';
            // }
            // cout << endl;
        }
        map<char, int> cmap;
        for (int i = 0; i < len; i++) {
            cmap[st[i]]++;
        }

        string ans(m, ' ');
        auto jter = cmap.rbegin();
        for (auto g : vpos) {
            while (jter != cmap.rend() && jter->second < g.size()) {
                jter++;
            }
            for (int p : g) {
                ans[p] = jter->first;
            }
            jter++;
        }
        cout << ans << '\n';
    }
    return 0;
}