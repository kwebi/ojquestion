#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=210;
struct Edge{
	int to,next,w;
	Edge(){
	}
	Edge(int a,int b,int c):to(a),next(b),w(c){
	}
}edge[maxn*maxn];
int head[maxn],tot;
int dep[maxn],cur[maxn];

void addEdge(int u,int v,int w){
	edge[tot]=Edge(v,head[u],w);
	head[u]=tot++;
	edge[tot]=Edge(u,head[v],0);
	head[v]=tot++;
}

bool bfs(){
	
}

int main(){
	int N,F,D;
	scanf("%d%d%d",&N,&F,&D);
	for(int i=1;i<=N;i++){
		int f,d;
		scanf("%d%d",&f,&d);
		for(int j=1;j<=f;j++){
			int t;scanf("%d",&t);
		}
		for(int j=1;j<=d;j++){
			int t;scanf("%d",&t);
		}
	}
	
	return 0;
}
