#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

struct node {
    int c,a,b,cnt;
};

bool vis[105][105][105];

int main() {
    int s,n,m;
    while(true) {

        scanf("%d%d%d",&s,&n,&m);
        if(s==0&&n==0&&m==0)
            break;
        if(s&1) {
            printf("NO\n");
            continue;
        }
        memset(vis,0,sizeof(vis));
        if(n<m)
            swap(n,m);

        queue<node> Q;
        Q.push({s,0,0,0});
        int ans=1e9+7;
        vis[s][0][0]=1;

        while(!Q.empty()) {
            node fnt=Q.front();
            Q.pop();
            if(fnt.c==s/2) {
                ans=min(ans, fnt.cnt);
                continue;
            }
            if(fnt.c!=0&&fnt.a!=n) {
                node ano=fnt;
                ano.c-=min(fnt.c, n-fnt.a);
                ano.a+=min(fnt.c, n-fnt.a);
                ano.cnt++;
                if(!vis[ano.c][ano.a][ano.b]) {
                    vis[ano.c][ano.a][ano.b]=1;
                    Q.push(ano);
                }
            }
            if(fnt.c!=0&&fnt.b!=m) {
                node ano=fnt;
                ano.c-=min(fnt.c, m-fnt.b);
                ano.b+=min(fnt.c, m-fnt.b);
                ano.cnt++;
                if(!vis[ano.c][ano.a][ano.b]) {
                    vis[ano.c][ano.a][ano.b]=1;
                    Q.push(ano);
                }
            }
            if(fnt.a!=0&&fnt.c!=s) {
                node ano=fnt;
                ano.a-=min(fnt.a,s-fnt.c);
                ano.c+=min(fnt.a,s-fnt.c);
                ano.cnt++;
                if(!vis[ano.c][ano.a][ano.b]) {
                    vis[ano.c][ano.a][ano.b]=1;
                    Q.push(ano);
                }
            }
            if(fnt.a!=0&&fnt.b!=m) {
                node ano=fnt;
                ano.a-=min(fnt.a,m-fnt.b);
                ano.b+=min(fnt.a,m-fnt.b);
                ano.cnt++;
                if(!vis[ano.c][ano.a][ano.b]) {
                    vis[ano.c][ano.a][ano.b]=1;
                    Q.push(ano);
                }
            }
            if(fnt.b!=0&&fnt.a!=n) {
                node ano=fnt;
                ano.b-=min(fnt.b,n-fnt.a);
                ano.a+=min(fnt.b,n-fnt.a);
                ano.cnt++;
                if(!vis[ano.c][ano.a][ano.b]) {
                    vis[ano.c][ano.a][ano.b]=1;
                    Q.push(ano);
                }
            }
            if(fnt.b!=0&&fnt.c!=s) {
                node ano=fnt;
                ano.b-=min(fnt.b,s-fnt.c);
                ano.c+=min(fnt.b,s-fnt.c);
                ano.cnt++;
                if(!vis[ano.c][ano.a][ano.b]) {
                    vis[ano.c][ano.a][ano.b]=1;
                    Q.push(ano);
                }
            }

        }
        if(ans!=1e9+7)
            printf("%d\n",ans);
        else
            printf("NO\n");

    }
    return 0;
}
