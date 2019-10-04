//kwb 2019.9.23
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;


int ans=0;
bool  vis[10][10];
int num[20];
int l[110];
int r[110];
int n,m;

void dfs(int d){
    if(d>n){
        memset(vis,0,sizeof(vis));
        int cnt=0;
        for(int i=1;i<=m;i++){
            int a=num[l[i]],b=num[r[i]];
            if(a<b)swap(a,b);
            if(!vis[a][b]){
                cnt++;
                vis[a][b]=1;
            }
        }
        ans=max(ans,cnt);
        return;
    }
    for(int i=1;i<=6;i++){
        num[d]=i;
        dfs(d+1);
    }
}


int main(){
    
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&l[i],&r[i]);
    }
    
    dfs(1);
    printf("%d",ans);
    return 0;
}

/*
7 9
1 2
1 3
1 4
2 3
2 4
3 4
5 6
5 7
6 7
*/
