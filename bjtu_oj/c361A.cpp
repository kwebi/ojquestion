#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=3e6+7;
struct Edge {
	int to,next;
} edge[maxn];
int head[maxn],tot;
int linker[maxn],cur[maxn];
int uN;
void init() {
	uN=0;
	memset(head,-1,sizeof(head));
	memset(cur,-1,sizeof(cur));
	tot=0;
}

void addEdge(int u,int v) {
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}

bool dfs(int u) {
	for(int i=head[u]; i!=-1; i=edge[i].next) {
		int v=edge[i].to;
		if(cur[v]==i)continue;
		cur[v]=i;
		if(linker[v]==-1||dfs(linker[v])) {
			linker[v]=u;
			return 1;
		}
	}
	return false;
}


int hungary() {
	int res=0;
	memset(linker,-1,sizeof(linker));
	for(int i=1; i<=uN; i++) {
		if(dfs(i))res++;
		else break;
	}
	return res;
}

int main() {
	int n;
	scanf("%d",&n);
	init();

	for(int i=1; i<=n; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		addEdge(a,n+i);
		addEdge(b,n+i);
		uN=max(uN,max(a,b));
	}

	printf("%d\n",hungary());
	return 0;
}
