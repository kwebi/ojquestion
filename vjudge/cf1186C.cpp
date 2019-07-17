#include <cstring>
#include <stdio.h>
#include <bits/stdc++.h>

typedef long long LL;
const int maxn = 1e6 + 5;

char ac[maxn];
char bc[maxn];
int Next[maxn];
int a[maxn];
int b[maxn];
LL res[maxn];
int an;
int bn;


int calc(int x)
{
	int ans = 0;
	for (; x; x >>= 1)ans ^= (x & 1);
	return ans;
}

int main()
{
	scanf("%s", ac);
	scanf("%s", bc);
	an = strlen(ac);
	bn = strlen(bc);
	for (int i = 0; i < an; i++) {
		a[i] = ac[i] - '0';
	}
	for (int i = 0; i < bn; i++) {
		b[i] = bc[i] - '0';
	}
	long long cnta = 0;
	long long cntb = 0;
	long long ans = 0;
	for (int i = 0; i < bn; i++) {
		if (b[i])cntb++;
		if (a[i])cnta++;
	}
	if((cnta+cntb)%2==0)ans++;
	for (int i = bn; i < an; i++) {
		cnta-=a[i-bn];
		cnta+=a[i];
		if((cnta+cntb)%2==0)ans++;
	}

	printf("%lld", ans);

	return 0;
}
