#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
char s[110][110];
bool ans[110];
bool vis[110][110];

int main() {
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		scanf("%s",s[i]+1);
	}
	for(int j=1; j<=m; j++) {
		for(int i=2; i<=n; i++) {
			char p=s[i-1][j];
			char now=s[i][j];
			bool f=0;
			for(int k=1; k<=m; k++) {
				if(vis[i][k]) {
					f=1;
					break;
				}
			}
			if(f)continue;
			if(now<p) {
				ans[j]=1;
				break;
			} else if(now>p) {
				vis[i][j]=1;
			}
		}
		if(ans[j]) {
			for(int k=2; k<=n; k++)vis[k][j]=0;
		}
	}
	int res=0;
	for(int i=1; i<=m; i++) {
		if(ans[i])res++;
	}
	printf("%d\n",res);
	return 0;
}

