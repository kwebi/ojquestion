#include <bits/stdc++.h>

bool cc[105];

int len(int x) {
	int ans = 0;
	while (x > 0) {
		x >>= 1;
		ans++;
	}
	return ans;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int ln = len(n);

	int tn = n;
	int cnt = 0;
	int hc = 0;

	while (tn > 0) {
		if (tn & 1) {
			cc[cnt] = 1;
			hc++;
		}
		cnt++;
		tn >>= 1;
	}
	if (k >= hc) return printf("0\n"), 0;
	int up = 0;
	int down=0;
	for (int i=ln-1;i>=0;i--){
		if(cc[i]) {
			down++;
			if(down==k){
				up=ln-down+1;
			}
		}
	}

	int ans = 0;
	int need = 1 << (up - 1);
	for (int i = 0; i < up - 1; i++) {
		if (cc[i]) ans += (1 << i);
	}
	ans = need - ans;
	printf("%d\n", ans);

	return 0;
}
