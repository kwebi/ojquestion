#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N=1e5+7;
int n,k;
vector<int> G[N];
priority_queue<pii> que;
int fa[N];
int sz[N];

void dfs(int u){
    int j;
    for(j=0;j<G[u].size();j++){
        int v=G[u][j];
        if(sz[v]+1==sz[u]){
            dfs(v);
            break;
        }
        que.push(pii(sz[v],v));
    }
    j++;
    for(int i=j;i<G[u].size();i++){
        que.push(pii(sz[G[u][i]],G[u][i]));
    }
}

int rdfs(int u,int p){
    int ret=1;
    for(int j=0;j<G[u].size();j++){
        int v=G[u][j];
        if(v!=p){
            ret=max(ret,rdfs(v,u)+1);
        }
    }
    //printf("%d %d\n",u,ret);
    //que.push(pii(ret,u));
    sz[u]=ret;
    return ret;
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n-1;i++){
        int v;
        scanf("%d",&v);
        G[v].push_back(i+1);
        fa[i+1]=v;
    }
    rdfs(1,0);
    int cnt=0;
    int ans=0;
    que.push(pii(sz[1],1));
    while(cnt<k&&que.size()){
        pii t=que.top();que.pop();
        int v=t.second;
        ans+=t.first;
        dfs(t.second);
        cnt++;
    }
    printf("%d\n",ans);
    return 0;
}

