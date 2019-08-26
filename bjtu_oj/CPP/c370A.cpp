#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int tmp[12][12];
int ans[12][12];
int b[12][12];
int n,k;
const int mod=9973;

void chen(int a1[][12],int b1[][12]) {
	memset(tmp,0,sizeof(tmp));
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=n; k++) {
				tmp[i][j]=(tmp[i][j]+a1[i][k]*b1[k][j]%mod)%mod;
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++)
			a1[i][j]=tmp[i][j];
	}
}

void pow_m(int k) {
	memset(ans,0,sizeof(ans));
	for(int i=1; i<=n; i++)ans[i][i]=1;
	while(k>0) {
		if(k&1) {
			chen(ans,b);
		}
		chen(b,b);
		k>>=1;
	}
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&k);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				scanf("%d",&b[i][j]);
			}
		}
		pow_m(k);
		int res=0;
		for(int i=1; i<=n; i++) {
			res=(res+ans[i][i])%mod;
		}
		printf("%d\n",res);
	}
	return 0;
}
