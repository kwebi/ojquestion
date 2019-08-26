#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=2e3+5;
char s[maxn][maxn];

int rb[maxn][maxn];
int cb[maxn][maxn];

int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++) {
		scanf("%s",s[i]+1);
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			rb[i][j]=rb[i][j-1]+s[i][j]=='B';
		}
		if(rb[i][n]==0)ans++;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cb[j][i]=cb[j-1][i]+s[j][i]=='B';
		}
		if(cb[n][i]==0)ans++;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {

		}
	}
	return 0;
}
