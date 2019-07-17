//#include <bits/stdc++.h>
#include<stdio.h>
#include <cmath>
#include <stdlib.h>


const int maxn = 1e5 + 5;
double a[maxn];
int n, k;

bool C(double x) {
	int num = 0;
	for (int i = 0; i < n; i++) {
		num +=(int) (a[i] / x);
	}
	return num >= k;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &a[i]);
	}
	double beg = 0;
	double end = 1e6;
	for (int i = 0; i < 100; i++) {
		double mid = (beg + end) / 2;
		if (C(mid)) beg = mid;
		else end = mid;
	}
	printf("%.2f\n", floor(beg * 100) / 100);

	return 0;
}
