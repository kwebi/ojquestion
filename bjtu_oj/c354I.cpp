#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn=200;
int disv[200][200];

struct Edge{
	int u,v,c;
	bool operator<(const Edge&b){
		return c<b.c;
	}
}es[20010];
int cnt=0;
int par[200];
void init(){
	for(int i=0;i<=maxn;i++){
		par[i]=i;
	}
}

int findp(int x){
	return x==par[x]?x:par[x]=findp(par[x]);
}

void unite(int x,int y){
	x=findp(x);
	y=findp(y);
	if(x<y){
		par[x]=y;
	}else if(x>y){
		par[y]=x;
	}
}

bool samep(int x,int y){
	return findp(x)==findp(y);
}

void addEdge(int u,int v,int c){
	es[cnt].u=u;
	es[cnt].v=v;
	es[cnt].c=c;
	cnt++;
}

int main(){
	init();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&disv[i][j]);
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);
		unite(a,b);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(!samep(i,j)){
				addEdge(i,j,disv[i][j]);
			}
		}
	}
	sort(es,es+cnt);
	int ans=0;
	for(int i=0;i<cnt;i++){
		Edge e=es[i];
		if(!samep(e.u,e.v)){
			unite(e.u,e.v);
			ans+=e.c;
		}
	}
	printf("%d",ans);
	return 0;
}

