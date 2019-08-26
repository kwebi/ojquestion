#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int maxn=1e3+5;
char s1[maxn][maxn],s2[maxn][maxn];
const unsigned int hash1 = 200379, hash2 = 211985;
ull p1[maxn],p2[maxn];
ull h[maxn][maxn];

int main() {
	int T;
	scanf("%d",&T);
	p1[0]=1;
	p2[0]=1;
	for(int i=1; i<maxn; i++) {
		p1[i]=hash1*p1[i-1];
		p2[i]=hash2*p2[i-1];
	}
	memset(s2,0,sizeof(s2));
	while(T--) {
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++) {
			scanf("%s",s1[i]+1);
		}
		int x,y;
		scanf("%d%d",&x,&y);
		for(int i=1; i<=x; i++) {
			scanf("%s",s2[i]+1);
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				h[i][j]=h[i-1][j-1]*hash1*hash2+(h[i-1][j]-h[i-1][j-1]*hash2)*hash1+(h[i][j-1]-h[i-1][j-1]*hash1)*hash2+s1[i][j];
			}
		}
		ll tmp=0;
		for(int i=1; i<=x; i++) {
			for(int j=1; j<=y; j++) {
				tmp+=s2[i][j]*p1[x-i]*p2[y-j];
			}
		}
		ll ans=0;
		for(int i=x; i<=n; i++) {
			for(int j=y; j<=m; j++) {
				ll t=0;
				t=h[i][j]+h[i-x][j-y]*p1[x]*p2[y]-h[i-x][j]*p1[x]-h[i][j-y]*p2[y];
				if(t==tmp) {
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
2
1 1
x
1  1
y
3  3
abc
bcd
cde
2  2
bc
cd
*/


