#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=2e3+7;
struct Edge {
	int to,next;
} edge[maxn*maxn];
int head[maxn],tot;

void init() {
	memset(head,-1,sizeof(head));
	tot=0;
}

void addEdge(int u,int v) {
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}
int linker[maxn];
int used[maxn];

bool dfs(int u) {
	for(int i=head[u]; i!=-1; i=edge[i].next) {
		int v=edge[i].to;
		if(used[v])continue;
		used[v]=1;
		if(linker[v]==-1||dfs(linker[v])) {
			linker[v]=u;
			return true;
		}
	}
	return false;
}
int uN;
int hungry() {
	int res=0;
	memset(linker,-1,sizeof(linker));

	for(int i=1; i<=uN; i++) {
		memset(used,0,sizeof(used));
		if(dfs(i))res++;
	}
	return res;
}

int mp[maxn][maxn];

int main() {
	init();
	int n,k;
	scanf("%d%d",&n,&k);
	uN=n;
	while(k--) {
		int r,c;
		scanf("%d%d",&r,&c);
		if(mp[r][c]==0) {
			mp[r][c]=1;
			addEdge(r,n+c);
		}
	}
	printf("%d\n",hungry());
	return 0;
}
