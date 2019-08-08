#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e3+5;
int rg[maxn][maxn];
int n,m;
struct Edge {
	int to,next;
} es[maxn*maxn];
int head[maxn],tot;
int Low[maxn],DFN[maxn],Stack[maxn],Belong[maxn];
bool Instack[maxn];
int Index,top;
int col[maxn],in[maxn],kind[maxn],ok[maxn];
void addEdge(int u,int v) {
	es[tot].to=v;
	es[tot].next=head[u];
	head[u]=tot++;
}

bool check(int x,int c) {
	col[x]=c;
	for(int i=head[x]; i!=-1; i=es[i].next) {
		int v=es[i].to;
		if(in[v]) {
			if(col[v]!=-1) {
				if(col[v]==col[x])return false;
				continue;
			}
			if(!check(v,!c))return false;
		}
	}
	return true;
}

void Tarjan(int u,int pre) {
	DFN[u]=Low[u]=++Index;
	Stack[top++]=u;
	for(int i=head[u]; i!=-1; i=es[i].next) {
		int v=es[i].to;
		if(v==pre)continue;
		if(!DFN[v]) {
			Tarjan(v,u);
			Low[u]=min(Low[u],Low[v]);
			if(Low[v]>=DFN[u]) {
				memset(col,-1,sizeof(col));
				memset(in,0,sizeof(in));
				int x;
				int cnt=0;
				do {
					x=Stack[--top];
					kind[cnt++]=x;
					in[x]=1;
				} while(v!=x);
				if(cnt<=1)continue;
				in[u]=1;
				if(!check(u,0)) { //·Ç¶þ·ÖÍ¼
					ok[u]=1;
					while(cnt--) {
						ok[kind[cnt]]=1;
					}
				}
			}
		} else if(Low[u]>DFN[v]) Low[u]=DFN[v];
	}
}

int main() {
	while(~scanf("%d%d",&n,&m)) {
		if(n==m&&n==0)break;
		memset(rg,0,sizeof(rg));
		memset(head,-1,sizeof(head));
		memset(Instack,0,sizeof(Instack));
		memset(DFN,0,sizeof(DFN));
		memset(Low,0,sizeof(Low));
		for(int i=1; i<=n; i++) {
			ok[i]=0;
		}
		tot=0,top=0;
		for(int i=1; i<=m; i++) {
			int a,b;
			scanf("%d%d",&a,&b);
			rg[a][b]=1;
			rg[b][a]=1;
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(i!=j&&!rg[i][j])addEdge(i,j),addEdge(j,i);
			}
		}
		int ans=0;
		for(int i=1; i<=n; i++) {
			if(!DFN[i])
				Tarjan(i,-1);
		}
		for(int i=1; i<=n; i++) {
			if(ok[i])ans++;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}
