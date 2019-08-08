#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
const int maxlogn=30;
vector<int> G[maxn];
int parent[maxlogn][maxn];
int depth[maxn];
int tsize[maxn];
int n;


void dfs(int v,int p,int d) {
    parent[0][v]=p;
    depth[v]=d;
    tsize[v]=1;
    for(int i=0; i<G[v].size(); i++) {
        if(G[v][i]!=p) {
            dfs(G[v][i],v,d+1);
            tsize[v]+=tsize[G[v][i]];
        }
    }
}

void init(int V) {
    dfs(1,0,0);
    for(int k=0; k+1<maxlogn; k++) {
        for(int v=1; v<=V; v++) {
            if(parent[k][v]<=0)
                parent[k+1][v]=0;
            else
                parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
}

int lca(int u,int v) {
    if(depth[u]>depth[v])
        swap(u,v);
    for(int k=0; k<maxlogn; k++) {
        if((depth[v]-depth[u])>>k&1) {
            v=parent[k][v];
        }
    }
    if(u==v)
        return u;
    for(int k=maxlogn-1; k>=0; k--) {
        if(parent[k][u]!=parent[k][v]) {
            u=parent[k][u];
            v=parent[k][v];
        }
    }
    return parent[0][u];
}

int solve(int x,int y) {
    if(x==y)
        return n;
    int l=lca(x,y);
    int dis=depth[x]+depth[y]-2*depth[l];
    if(dis&1)
        return 0;
    else if(depth[x]==depth[y]) {
        int dx=depth[x]-depth[l]-1;
        int v1=x,v2=y;
        for(int k=0;k<maxlogn;k++){
            if(dx>>k&1){
                v1=parent[k][v1];
                v2=parent[k][v2];
            }
        }
        return n-tsize[v1]-tsize[v2];
    }

    if(depth[x]<depth[y])
        swap(x,y);
    int v1=x,v2=x;
    int d1=dis/2;
    int d2=dis/2-1;
    for(int k=0; k<maxlogn; k++) {
        if(d1>>k&1) {
            v1=parent[k][v1];
        }
        if(d2>>k&1) {
            v2=parent[k][v2];
        }
    }
    return tsize[v1]-tsize[v2];
}

int main() {
    cin>>n;
    for(int i=1; i<=n-1; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    init(n);
    int m;
    cin>>m;
    for(int j=1; j<=m; j++) {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",solve(x,y));
    }
    return 0;
}
