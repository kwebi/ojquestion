#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

using ll=long long;

const int maxn=1e4+5;

struct Edge {
	int t,c;
};
vector<Edge> G[maxn];
ll f[maxn][10];
int mx[maxn];

void dfs(int p,int x) {
	for(int i=0; i<G[x].size(); i++) {
		Edge& e=G[x][i];
		if(e.t!=p) {
			dfs(x,e.t);
			if(f[e.t][0]+e.c>=f[x][0]) {
				f[x][1]=f[x][0];
				f[x][0]=f[e.t][0]+e.c;
				mx[x]=e.t;
			} else if(f[x][1]<f[e.t][0]+e.c) {
				f[x][1]=f[e.t][0]+e.c;
			} else if(f[x][1]<f[e.t][1]+e.c) {
				f[x][1]=f[e.t][1]+e.c;
			}
		}
	}
}

void dfsT(int p,int x) {
	for(int i=0; i<G[x].size(); i++) {
		Edge& e=G[x][i];
		if(e.t!=p) {
			if(e.t==mx[x]) {
				f[e.t][2]=max(f[x][2]+e.c,f[x][1]+e.c);
			} else {
				f[e.t][2]=max(f[x][2]+e.c,f[x][0]+e.c);
			}
			dfsT(x,e.t);
		}
	}
}

int main() {
	int n;
	while(~scanf("%d",&n)) {
		memset(f,0,sizeof(f));
		memset(mx,0,sizeof(mx));
		for(int i=1;i<=n;i++)G[i].clear();
		int now=1;
		for(int i=1; i<=n-1; i++) {
			now++;
			int a,b;
			scanf("%d%d",&a,&b);
			G[a].push_back((Edge) {
				now,b
			});
			G[now].push_back((Edge) {
				a,b
			});
		}
		dfs(0,1);
		dfsT(0,1);
		for(int i=1; i<=n; i++) {
			printf("%lld\n",max(f[i][0],f[i][2]));
		}
	}
	return 0;
}
