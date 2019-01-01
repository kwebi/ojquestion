#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	int i;
	for (i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		int j;
		int T = 0;
		for (j = 2; j <= sqrt(n); j++) {
			T = 0;
			int flag = 0;
			int k;
			for (k = 2; k <= sqrt(j); k++) {
				if (j % k == 0) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				if (n % j == 0) {
					int s = n / j;
					int m;
					int f = 0;
					for (m = 2; m <= sqrt(s); m++) {
						if (s % m == 0) {
							f = 1;
							break;
						}
					}
					if (f == 0) {
						printf("YES\n");
						break;
					}
					else T = 1;
				}
				else T = 1;
			}
			else T = 1;
		}
		if (T == 1) printf("NO\n");
		if (n <= 3) printf("NO\n");
	}
	return 0;
}