#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int k,m;
int a[10];
int mtx[12][12];
int ans[12][12];
int tmp[12][12];

void mul(int a[][12],int b[][12]) {
	memset(tmp,0,sizeof(tmp));
	for(int i=0; i<=9; i++) {
		for(int j=0; j<=9; j++) {
			for(int k=0; k<=9; k++) {
				tmp[i][j]=(tmp[i][j]+a[i][k]*b[k][j]%m)%m;
			}
		}
	}
	for(int i=0; i<=9; i++) {
		for(int j=0; j<=9; j++) {
			a[i][j]=tmp[i][j];
		}
	}
}

void pow_m(int k) {
	memset(ans,0,sizeof(ans));
	for(int i=0; i<=9; i++)ans[i][i]=1;
	while(k>0) {
		if(k&1) {
			mul(ans,mtx);
		}
		mul(mtx,mtx);
		k>>=1;
	}
}

int main() {
	while(~scanf("%d%d",&k,&m)) {
		memset(mtx,0,sizeof(mtx));
		for(int i=0; i<=9; i++) {
			scanf("%d",&a[i]);
			mtx[i][0]=a[i];
		}
		for(int i=0; i<=9; i++) {
			mtx[i][i+1]=1;
		}

		if(k<10) {
			printf("%d\n",k%m);
		} else {
			pow_m(k-9);
			int res=0;
			for(int i=0; i<=9; i++) {
				res=(res+(9-i)*ans[i][0]%m)%m;
			}
			printf("%d\n",res);
		}
	}
	return 0;
}
