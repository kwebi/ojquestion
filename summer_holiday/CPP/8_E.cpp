//
// Created by 弱冠 on 2018/7/20.
//
#include <cstdio>
#include <iostream>
using namespace std;
char field[1005][1005];

int n;
void dfs(int x,int y) {
    field[x][y]='*';
    for (int dx=-1;dx<=1;dx++){
        for(int dy=-1;dy<=1;dy++){
            int nx = dx+x;
            int ny= dy+y;
            if(0<=nx&&nx<n&&0<=ny&&ny<n&&field[nx][ny]=='#'){
                dfs(nx,ny);
            }
        }
    }
}

int main() {
    freopen("../data.txt","r",stdin);
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> field[i][j];
        }
    }
    int res=0;
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (field[i][j]=='#'){
                dfs(i,j);
                res++;
            }
        }
    }
    printf("%d\n",res);
    return 0;
}
