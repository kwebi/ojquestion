#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=2e3+5;
char s[maxn][maxn];
char ans[maxn][maxn];
int du[maxn][maxn];
int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};

bool vis[maxn][maxn];
vector<pii> G;

int main() {
    int n,m;
    cin >>n>>m;
    for(int i=1; i<=n; i++) {
        scanf("%s",s[i]+1);
    }
    for(int i=0; i<=n; i++)
        s[i][0]=s[i][m+1]='*';
    for(int i=0; i<=m; i++)
        s[0][i]=s[n+1][i]='*';

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s[i][j]=='.') {
                for(int t=0; t<4; t++) {
                    if(s[i+dx[t]][j+dy[t]]=='.')
                        du[i][j]++;
                }
                G.push_back(make_pair(i,j));
            }
            ans[i][j]=s[i][j];
        }
    }

    queue<pii> Q;
    for(auto e:G) {
        if(du[e.first][e.second]==1)
            Q.push(make_pair(e.first,e.second));
    }
    while(!Q.empty()) {
        pii f=Q.front();
        Q.pop();
        int i=f.first;
        int j=f.second;
        if(vis[i][j])
            continue;
        int ty=-2,tx=-2;
        bool flag=0;
        for(int t=0; t<4; t++) {
            tx=i+dx[t];
            ty=j+dy[t];
            if(!vis[tx][ty]&&s[i+dx[t]][j+dy[t]]=='.') {
                vis[tx][ty]=1;
                vis[i][j]=1;
                flag=1;
                if(t==2){
                    ans[i][j]='>';
                    ans[tx][ty]='<';
                }else if(t==3){
                    ans[i][j]='<';
                    ans[tx][ty]='>';
                }else if(t==1){
                    ans[i][j]='^';
                    ans[tx][ty]='v';
                }else if(t==0){
                    ans[i][j]='v';
                    ans[tx][ty]='^';
                }
                break;
            }
        }
        if(flag) {
            for(int t=0; t<4; t++) {
                int x=tx+dx[t];
                int y=ty+dy[t];
                if(!vis[x][y]&&s[x][y]=='.') {
                    du[x][y]--;
                    if(du[x][y]==1) {
                        Q.push(make_pair(x,y));
                    }
                }
            }
        }
    }
    for(auto e:G){
        if(!vis[e.first][e.second]){
            printf("Not unique");
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%c",ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
