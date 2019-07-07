#include <bits/stdc++.h>
using namespace std;

int a[105];
int cnt = 0;

int ans = -1;
int _sum = 0;
int _max = 0;
bool vis[105];
int nexti[105];

void dfs(int idx, int now, int step, int beg) {
	if (ans != -1) return ;
	if (step == _sum / idx) {
		ans = idx;
		return ;
	}
	if (now == idx) {
		dfs(idx, 0, step + 1, 0);
		return;
	}
	if (idx - now < a[cnt - 1]) return;
	for (int i = beg; i < cnt;) {
		if (!vis[i] && now + a[i] <= idx) {
			vis[i] = 1;
			dfs(idx, now + a[i], step, i + 1);
			vis[i] = 0;
			if (now == 0 || a[i] + now == idx || ans != -1)break;
			i = nexti[i];
		} else {
			i++;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		if (t <= 50) {
			a[cnt++] = t;
			_sum += t;
			_max = max(_max, t);
		}
	}

	sort(a, a + cnt, greater<int>());

	for (int i = 0; i < cnt; i++) {
		int j = i + 1;
		while (j < cnt && a[i] == a[j]) {
			j++;
		}
		for (int t = i; t < j; t++)
			nexti[t] = j;
	}

	for (int i = _max; i <= _sum; i++) {
		if (_sum % i == 0) {
			dfs(i, 0, 0, 0);
			if (ans != -1) {
				break;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
