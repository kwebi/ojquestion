#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=2e4+5;
int a[maxn];
int b[maxn];
int ind[maxn];
vector<int> G[maxn];
int res[maxn];
int n,m;

int mdis(int u,int v) {
	return u-v<0?u-v+n:u-v;
}

int main() {
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		scanf("%d%d",&a[i],&b[i]);
		ind[a[i]]++;
		G[a[i]].push_back(b[i]);
	}

	for(int v=1; v<=n; v++) {
		for(int i=1; i<=n; i++) {
			int t=1e9;
			for(int j=0; j<G[i].size(); j++) {
				int k=G[i][j];
				t=min(t,mdis(k,i));
			}
			if(ind[i]>0) {
				res[v]=max(res[v],mdis(i,v)+t+(ind[i]-1)*n);
			}
		}
	}

	for(int i=1; i<=n; i++)
		printf("%d ",res[i]);
	return 0;
}

