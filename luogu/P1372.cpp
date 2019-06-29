#include <bits/stdc++.h>
using namespace std;

int n, k;
int ans = 0;

int gcd(int a, int b)
{
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d", &n, &k);
	printf("%d\n", ans);
	return 0;
}
