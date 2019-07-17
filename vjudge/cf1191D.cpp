#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

typedef long long ll;

int a[MAXN];
map<int, int> b;

int main() {
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i=1;i<=n;i++){
		b[a[i]]++;
		if (b[a[i]] >= 2) {
			cnt++;
			if (a[i] == 0)cnt++;
			else if(b.count(a[i]-1)!=0)cnt++;
		}
	}
	if (cnt >= 2) {
		printf("cslnb\n");
		return 0;
	}
	
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += a[i] - (i - 1);
	}
	if (ans % 2 != 0) {
		printf("sjfnb\n");
	} else {
		printf("cslnb\n");
	}
	return 0;
}
