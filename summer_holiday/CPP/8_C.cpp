//
// Created by 弱冠 on 2018/7/20.
//

#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> v[100011];
int vis[100011];
void dfs(int node)
{
    if (vis[node])
        return;
    vis[node] = 1;
    for (int i = 0; i < v[node].size(); i++)
        dfs(v[node][i]);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    int l, r;
    cin >> l >> r;
    dfs(l);
    if (vis[r])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
