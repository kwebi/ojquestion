#include <bits/stdc++.h>
using namespace std;
int a[2010];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= 2 * n; i++) {
            scanf("%d", &a[i]);
        }
        vector<int> vo, ve;
        for (int i = 1; i <= 2 * n; i++) {
            if (a[i] % 2 == 0)
                ve.push_back(i);
            else
                vo.push_back(i);
        }
        if (ve.size() % 2 == 1 && vo.size() % 2 == 1) {
            ve.pop_back();
            vo.pop_back();

        } else if (ve.size() >= 2) {
            ve.pop_back();
            ve.pop_back();

        } else if (vo.size() >= 2) {
            vo.pop_back();
            vo.pop_back();
        }
        vector<int> ans;
        for (auto e : vo) {
            ans.push_back(e);
        }
        for (auto e : ve) {
            ans.push_back(e);
        }
        for (int i = 0; i < ans.size(); i += 2) {
            cout << ans[i] << ' ' << ans[i + 1] << '\n';
        }
        // cout << ve.size() << ' ' << vo.size() << endl;
    }

    return 0;
}