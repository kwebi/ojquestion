#include <bits/stdc++.h>
using namespace std;

int a[1005];
int f[1005][5];
vector<int> G[1005];
const int INF = 1e9 + 7;

void dfs(int i, int pre) {
	if (G[i].size() == 1 && G[i][0] == pre) {
		f[i][0] = f[i][1] = f[i][2] = 1;
		return;
	}
	for (int j = 0; j < G[i].size(); j++) {
		int t = G[i][j];
		if (t != pre) {
			dfs(t, i);
		}
	}
	int s = 0;
	int s1m = INF;
	int s2m = INF;
	for (int j = 0; j < G[i].size(); j++) {
		int t = G[i][j];
		if (t == pre) continue;
		s += f[t][4];
		f[i][3] += f[t][2];
		f[i][4] += f[t][3];
		s1m = min(s1m, f[t][0] - f[t][3]);
		s2m = min(s2m, f[t][1] - f[t][2]);
	}
	f[i][0] = 1 + s;
	int s1 = f[i][4];
	f[i][1] = min(s1 + s1m, f[i][0]);
	int s2 = f[i][3];
	f[i][2] = min(f[i][1], s2 + s2m);
	f[i][3] = min(f[i][2], f[i][3]);
	f[i][4] = min(f[i][3], f[i][4]);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &a[i]);
		G[a[i]].push_back(i);
	}
	dfs(1, 0);
	printf("%d\n", f[1][2]);
	return 0;
}
