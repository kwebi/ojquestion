#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int a,b,n;
int mtx[2][2];
const int mod=7;
int t[2][2]= {0};

void mul(int a[][2],int b[][2]) {
	int c[2][2]= {0};
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			for(int k=0; k<2; k++) {
				c[i][j]=(c[i][j]+a[i][k]*b[k][j]%mod)%mod;
			}
		}
	}
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			a[i][j]=c[i][j];
		}
	}
}

void pow_m(int k) {
	memset(t,0,sizeof(t));
	for(int i=0; i<2; i++)t[i][i]=1;
	while(k>0) {
		if(k&1) {
			mul(t,mtx);
		}
		mul(mtx,mtx);
		k>>=1;
	}
}

int main() {
	while(~scanf("%d%d%d",&a,&b,&n)) {
		if(a==0&&b==0&&n==0)break;
		mtx[0][0]=a;
		mtx[1][0]=b;
		mtx[0][1]=1;
		mtx[1][1]=0;
		if(n==1||n==2) {
			printf("1\n");
			continue;
		}
		pow_m(n-2);
		int ans=(t[0][0]+t[1][0])%7;
		printf("%d\n",ans);
	}
	return 0;
}

