#include <bits/stdc++.h>
using namespace std;

const int MAXN = 803;
const int Mod = 1e9 + 7;

int a[MAXN][MAXN];
int f[MAXN][MAXN][17][2];

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			a[i][j] %= (k + 1);
			f[i][j][a[i][j]][0] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int s = 0; s <= k; s++) {
				int t = (s - a[i][j] + k + 1) % (k + 1);
				f[i][j][s][0] = (f[i][j][s][0] + f[i - 1][j][t][1]) % Mod;
				f[i][j][s][0] = (f[i][j][s][0] + f[i][j - 1][t][1]) % Mod;
				f[i][j][s][1] = (f[i][j][s][1] + f[i - 1][j][(s + a[i][j]) % (k + 1)][0]) % Mod;
				f[i][j][s][1] = (f[i][j][s][1] + f[i][j - 1][(s + a[i][j]) % (k + 1)][0]) % Mod;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans += f[i][j][0][1];
			ans %= Mod;
		}
	}

	printf("%d\n", ans);

	return 0;
}