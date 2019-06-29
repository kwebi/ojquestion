#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn];
int f[maxn];
int n, m;


void _prime() {
	for (int i = 2; i <= m; i++) {
		if (a[i]) {
			for (int j = i * 2; j <= m; j += i) {
				a[j] = 0;
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= m; i++)a[i] = 1;
	_prime();
	for (int i = 1; i <= m; i++) {
		f[i] = a[i];
		f[i] += f[i - 1];
	}
	for (int i = 0; i < n; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		if(l>r) swap(l,r);
		if (l<1||l>m||r<1||r>m) {
			printf("Crossing the line\n");
			continue;
		}
		printf("%d\n", f[r]-f[l-1]);
	}
	return 0;
}
