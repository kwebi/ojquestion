#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+5;
struct Edge{
	int to,next;
}es[maxn*5];
int head[maxn],tot;
int Low[maxn],DFN[maxn],Stack[maxn];
int Index,top;
bool Instack[maxn];
int par[maxn];
bool bridge[maxn];
int n,m;
int bdg;

void init(){
	bdg=0;
	tot=0;
	for(int i=0;i<maxn;i++){
		head[i]=-1;
		DFN[i]=0;
		par[i]=i;
		bridge[i]=0;
	}
}


void addEdge(int u,int v){
	es[tot].to=v;
	es[tot].next=head[u];
	head[u]=tot++;
}

void Tarjan(int u,int pre){
	Low[u]=DFN[u]=++Index;
	int pren=0;
	for(int i=head[u];i!=-1;i=es[i].next){
		int v=es[i].to;
		if(v==pre&&pren==0){//处理重边
			pren=1;continue;
		}
		if(!DFN[v]){
			par[v]=u;
			Tarjan(v,u);
			Low[u]=min(Low[u],Low[v]);
			if(Low[v]>DFN[u]){//桥的判断条件
				bridge[v]=1;
				bdg++;
			}
		}else Low[u]=min(Low[u],DFN[v]);
	}
}

void Lca(int u,int v){
	if(DFN[u]>DFN[v]){
		if(bridge[u]){
			bdg--;
			bridge[u]=0;
		}
		u=par[u];
	}
	if(DFN[v]>DFN[u]){
		if(bridge[v]){
			bdg--;
			bridge[v]=0;
		}
		v=par[v];
	}
	while(u!=v){
		if(bridge[u]){
			bdg--;
			bridge[u]=0;
		}
		if(bridge[v]){
			bdg--;
			bridge[v]=0;
		}
		u=par[u];
		v=par[v];
	}
}

int main(){
	int cc=0;
	while(~scanf("%d%d",&n,&m)){
		if(n==0&&m==0)break;
		if(cc++>0)printf("\n");
		init();
		for(int i=1;i<=m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			addEdge(a,b);
			addEdge(b,a);
		}
		Tarjan(1,-1);
		int q;
		scanf("%d",&q);
		printf("Case %d:\n",cc);
		for(int i=1;i<=q;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			Lca(a,b);
			printf("%d\n",bdg);
		}
	}
	return 0;
}
