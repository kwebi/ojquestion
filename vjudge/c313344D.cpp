#include<stdio.h>
#include<queue>
#include<cstring>
using namespace std;

typedef pair<int,int> pii;

char s[205][205];
int n,m;

int dx[]= {-1,1,0,0};
int dy[]= {0,0,1,-1};
bool vis[205][205];
struct node {
    int x,y,cnt;
};

vector<node> ans1,ans2;

void bfs(int x,int y) {
    queue<node> Q;
    Q.push({x,y,0});
    node res;
    while(!Q.empty()) {
        node fnt=Q.front();
        Q.pop();
        if(s[fnt.x][fnt.y]=='@') {
            res.cnt=fnt.cnt;
            res.x=fnt.x;
            res.y=fnt.y;
            if(s[x][y]=='Y')
                ans1.push_back(res);
            else
                ans2.push_back(res);
        }
        for(int i=0; i<4; i++) {
            int tx=fnt.x+dx[i];
            int ty=fnt.y+dy[i];
            if(tx<=0||tx>n||ty<=0||ty>m)
                continue;
            if(!vis[tx][ty]&&(s[tx][ty]=='.'||s[tx][ty]=='@')) {
                vis[tx][ty]=1;
                Q.push({tx,ty,fnt.cnt+1});
            }
        }
    }

}

int main() {

    while(~scanf("%d%d",&n,&m)) {

        ans1.resize(0);
        ans2.resize(0);
        for(int i=1; i<=n; i++) {
            scanf("%s",s[i]+1);
        }
        int mans=1e9+7;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i][j]=='Y'||s[i][j]=='M') {
                    memset(vis,0,sizeof(vis));
                    bfs(i,j);
                }
            }
        }
        for(auto e1:ans1){
            for(auto e2:ans2){
                if(e1.x==e2.x&&e1.y==e2.y){
                    mans=min(mans,(e1.cnt+e2.cnt)*11);
                }
            }
        }
        printf("%d\n",mans);
    }

    return 0;
}
