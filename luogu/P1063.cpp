#include<bits/stdc++.h>
using namespace std;

int a[305];
int n;
int f[305][305];

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}

	int ans = 0;

	for(int i=1;i<=n;i++){
		for(int l=1;l+i<=2*n;l++){
			int r=l+i;
			for(int k=l+1;k<=r-1;k++){
				f[l][r]=max(f[l][r],f[l][k]+f[k][r]+a[l]*a[k]*a[r]);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		ans = max(f[i][i + n], ans);
	}
	printf("%d\n", ans);
	return 0;
}
