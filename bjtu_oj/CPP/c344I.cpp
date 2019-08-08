#include<stdio.h>
using namespace std;

typedef long long ll;

int s[25][25];
int a[1<<13];
int f[25][1<<13];
int cur[25];
int m,n;
int cnt;
const int Mod=1e8;

inline bool mok(int x) {
	return (x&(x<<1))==0;
}

void init() {
	cnt=0;
	int mx=1<<n;
	for(int i=0; i<mx; i++) {
		if(mok(i)) a[++cnt]=i;
	}
}

inline bool mcmp(int x,int k) {
	return ((x&cur[k])==0);
}

int main() {
	scanf("%d%d",&m,&n);
	for(int i=1; i<=m; i++) {
		cur[i]=0;//第i行逆状态
		for(int j=1; j<=n; j++) {
			scanf("%d",&s[i][j]);
			if(s[i][j]==0)
				cur[i]+=(1<<(n-j));
		}
	}
	init();
	for(int j=1; j<=cnt; j++) {
		if(mcmp(a[j],1)) f[1][j]=1;//枚举符合第1行的状态
	}
	for(int i=2;i<=m;i++){
		for(int k=1;k<=cnt;k++){//i的第k个状态
			if(!mcmp(a[k],i))continue;
			for(int j=1;j<=cnt;j++){//枚举i-1的j状态
				if(!mcmp(a[j],i-1))continue;
				if(a[k]&a[j])continue;
				f[i][k]=(f[i][k]+f[i-1][j])%Mod;
			}
		}
	}
	int ans=0;
	for(int k=1;k<=cnt;k++){
		ans=(ans+f[m][k])%Mod;
	}
	printf("%d\n",ans);

	return 0;
}

