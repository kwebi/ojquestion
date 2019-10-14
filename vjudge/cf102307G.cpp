#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N=1e4+7;
int deg[N];
int son[N];
int dep[N];
bool inq[N];
priority_queue<pii> que;

int dfs(int u){
    if(u==0)return 0;
    if(dep[u])return dep[u];
    int ret=1;
    ret=max(dfs(son[u])+1,ret);
    dep[u]=ret;
    return ret;
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        int u;
        scanf("%d",&u);
        son[i]=u;
        deg[u]++;
    }
    for(int i=1;i<=n;i++){
        if(deg[i]==0)dfs(i);
    }
    int cnt=0;
    int ans=0;
    //for(int i=1;i<=n;i++)printf("%d %d\n",dep[i],deg[i]);
    for(int i=1;i<=n;i++){
        if(deg[i]==0){
            que.push(pii(dep[i],i));
        }
    }
    while(cnt<n){
        vector<int> tmp;
        for(int i=1;i<=k;i++){
            if(que.empty())break;
            pii t=que.top();que.pop();
            cnt++;
            int v=son[t.second];
            deg[son[t.second]]--;
            if(deg[v]==0)tmp.push_back(v);
        }
        for(int i=0;i<tmp.size();i++){
            int v=tmp[i];
            que.push(pii(dep[v],v));
        }
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}

