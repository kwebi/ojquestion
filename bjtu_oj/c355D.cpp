#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
pii vp[2000];
int cnt;
const int maxn=2e3+5;
struct Edge{
	int to,next;
}es[maxn*maxn];
int head[1500],tot;
int Low[maxn],DFN[maxn],Stack[maxn],Belong[maxn];
int Index,top,scc;
bool Instack[maxn];

void addEdge(int u,int v){
	es[tot].to=v;
	es[tot].next=head[u];
	head[u]=tot++;
}

void Tarjan(int u){
	Low[u]=DFN[u]=++Index;
	Stack[top++]=u;
	Instack[u]=1;
	for(int i=head[u];i!=-1;i=es[i].next){
		int v=es[i].to;
		if(!DFN[v]){
			Tarjan(v);
			Low[u]=min(Low[u],Low[v]);
		}else if(Instack[v]) Low[u]=min(Low[u],DFN[v]);
	}
	if(Low[u]==DFN[u]){
		scc++;
		int v=u;
		do{
			v=Stack[--top];
			Instack[v]=0;
			Belong[v]=scc;
		}while(v!=u);
	}
}


int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>b)swap(a,b);
		vp[++cnt]=make_pair(a,b);
	}
	for(int i=1;i<=cnt;i++){
		for(int j=i+1;j<=cnt;j++){
			int xi=vp[i].first;
			int yi=vp[i].second;
			int xj=vp[j].first;
			int yj=vp[j].second;
			if((xi<=xj&&yi>=xj&&yj>=yi)||(xj<=xi&&yj>=xi&&yi>=yj)){
				addEdge(i,j+cnt);
				addEdge(j+cnt,i);
				addEdge(i+cnt,j);
				addEdge(j,i+cnt);
			}
		}
	}
	for(int i=1;i<=2*m;i++){
		if(!DFN[i])Tarjan(i);
	}
	bool ans=1;
	for(int i=1;i<=m;i++){
		if(Belong[i]==Belong[i+m]){
			ans=0;break;
		}
	}
	if(ans){
		printf("panda is telling the truth...\n");
	}else{
		printf("the evil panda is lying again\n");
	}
	return 0;
}
