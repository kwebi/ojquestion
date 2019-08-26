#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+7;
struct Edge {
	int u,v,c;
	bool operator<(const Edge& b){
		return c>b.c;
	}
} es[maxn];
int cnt=0;
bool dang[maxn];
int par[maxn];
int n,k;

void addEdge(int u,int v,int c) {
	es[cnt].u=u;
	es[cnt].v=v;
	es[cnt].c=c;
	cnt++;
}

void init() {
	for(int i=0; i<=n; i++) {
		par[i]=i;
	}
}

int findp(int x) {
	return x==par[x]?x:par[x]=findp(par[x]);
}

void unite(int x,int y) {
	x=findp(x);
	y=findp(y);
	if(x!=y) {
		if(dang[x]) {
			par[y]=x;
		} else {
			par[x]=y;
		}
	}
}

bool samep(int x,int y) {
	return findp(x)==findp(y);
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		cnt=0;
		memset(dang,0,sizeof(dang));
		scanf("%d%d",&n,&k);
		init();
		for(int i=1; i<=n-1; i++) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			addEdge(a,b,c);
		}
		sort(es,es+cnt);
		for(int i=1; i<=k; i++) {
			int u;
			scanf("%d",&u);
			dang[u]=1;
		}
		long long ans=0;
		for(int i=0; i<cnt; i++) {
			Edge& e=es[i];
			if(dang[findp(e.u)]&&dang[findp(e.v)]) {
				ans+=e.c;
			} else {
				unite(e.u,e.v);
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
