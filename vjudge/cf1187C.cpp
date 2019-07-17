#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxm = 1e3 + 5;

struct Pos {
	int l, r;
};

int t[maxm];
Pos pos[maxm];
bool cc[maxm];
int ans[maxm];
int d[maxm];

const int INIT = 2000;


int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	memset(d, -1, sizeof(d));
	map<int, int> unp;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &t[i], &pos[i].l, &pos[i].r);
		if (t[i]) {
			for (int j = pos[i].l + 1; j <= pos[i].r; j++) {
				d[j] = 0;
			}
		}
		else unp[pos[i].l] = pos[i].r;
	}
	d[0]=2000;
	for (int i = 1; i <= n; i++) {
		d[i] += d[i-1];
		//cout << ans[i] << endl;
	}
	for (auto e : unp) {
		if (is_sorted(d + e.first, d + e.second + 1)) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");

	for (int i = 1; i <= n; i++) printf("%d\n", d[i]);

	return 0;
}
