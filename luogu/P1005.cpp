#include<bits/stdc++.h>

using namespace std;


const int Mod = 10000, MAXN = 85;

struct HP
{
	int p[505], len;
	HP() {
		memset(p, 0, sizeof(p));
		len = 0;
	}
	void print() {
		printf("%d", p[len]);
		for (int i = len - 1; i > 0; i--) {
			if (p[i] == 0) {
				printf("0000");
				continue;
			}
			for (int k = 10; k * p[i] < Mod; k *= 10)
				printf("0");
			printf("%d", p[i]);
		}
	}
} f[MAXN][MAXN], base[MAXN], ans;

int a[MAXN][MAXN];
int n, m;

HP operator+(const HP&a, const HP&b) {
	HP c; c.len = max(a.len, b.len);
	int x = 0;
	for (int i = 1; i <= c.len; i++) {
		c.p[i] = a.p[i] + b.p[i] + x;
		x = c.p[i] / Mod;
		c.p[i] %= Mod;
	}
	if (x > 0) {
		c.p[++c.len] = x;
	}
	return c;
}

HP operator*(const HP&a, const int&b) {
	HP c; c.len = a.len; int x = 0;
	for (int i = 1; i <= c.len; i++) {
		c.p[i] = a.p[i] * b + x;
		x = c.p[i] / Mod;
		c.p[i] %= Mod;
	}
	while (x > 0) {
		c.p[++c.len] = x % Mod, x /= Mod;
	}
	return c;
}


HP max(const HP &a, const HP &b) {
	if (a.len > b.len)
		return a;
	else if (a.len < b.len)
		return b;
	for (int i = a.len; i > 0; i--)
		if (a.p[i] > b.p[i])
			return a;
		else if (a.p[i] < b.p[i])
			return b;
	return a;
}

void InitBase() {
	base[0].p[1] = 1;
	base[0].len = 1;
	for (int i = 1; i <= m; i++) {
		base[i] = base[i - 1] * 2;
	}
}



int main() {
	scanf("%d%d", &n, &m);
	InitBase();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(f, 0, sizeof(f));
		for (int k = 1; k <= m; k++) {
			for (int t = m; t >= k; t--) {
				f[k][t] = max(f[k][t], f[k - 1][t] + base[m - (t-k + 1)] * a[i][k - 1]);
				f[k][t] = max(f[k][t], f[k][t + 1] + base[m - (t-k + 1)] * a[i][t + 1]);
				//f[k][t].print();
				//cout << endl;
			}
		}
		HP amax;
		for (int k = 1; k <= m; k++) amax = max(amax, f[k][k] + base[m] * a[i][k]);
		ans = ans + amax;
	}
	ans.print();

	return 0;
}