#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e4+5;
struct Edge{
	int v,next;
}es[maxn*5];
int head[maxn],tot;
int Low[maxn],DFN[maxn],Stack[maxn],Belong[maxn];
int Index,top;
bool Instack[maxn];
int num[maxn];
int scc;
int n,m;

void addEdge(int u,int v){
	es[tot].v=v;
	es[tot].next=head[u];
	head[u]=tot++;
}

void Tarjan(int u){
	int v;
	Low[u]=DFN[u]=++Index;
	Stack[top++]=u;
	Instack[u]=1;
	for(int i=head[u];i!=-1;i=es[i].next){
		v=es[i].v;
		if(!DFN[v]){
			Tarjan(v);
			if(Low[u]>Low[v])Low[u]=Low[v];
		}else if(Instack[v]&&Low[u]>DFN[v]) Low[u]=DFN[v];
	}
	if(Low[u]==DFN[u]){
		scc++;
		do{
			v=Stack[--top];
			Instack[v]=0;
			Belong[v]=scc;
			num[scc]++;
		}while(u!=v);
	}
}

int main(){
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		addEdge(a,b);
	}
	for(int v=1;v<=n;v++){
		if(!DFN[v])Tarjan(v);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		//printf("%d %d\n",i,Belong[i]);printf("%d\n",i);
		if(num[i]>=2)ans++;
	}
	printf("%d\n",ans);
	return 0;
}

