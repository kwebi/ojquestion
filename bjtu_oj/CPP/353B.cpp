#include<bits/stdc++.h>

char s[60][60];
int vis[60][60];
int num[60][60];

int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};

int ans=0;
int n,m;

void dfs(int x,int y,int cnt,int id) {
	//printf("%d %d %d\n",x,y,num[x][y]);
	if(ans)return;
	if(num[x][y]>=4) {
		for(int i=0; i<4; i++) {
			int tx=x+dx[i];
			int ty=y+dy[i];
			//if(x==3&&y==1)printf("%d %d %d\n",tx,ty,num[tx][ty]);
			if(tx<1||tx>n||ty<1||ty>m)continue;

			if(s[x][y]==s[tx][ty]&&vis[tx][ty]==id) {
				if(num[tx][ty]==1){
					ans=1;
					return;
				}
			}
		}
	}
	for(int i=0; i<4; i++) {
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(tx<1||tx>n||ty<1||ty>m)continue;

		if(s[x][y]==s[tx][ty]&&vis[tx][ty]!=id) {
			vis[tx][ty]=id;
			num[tx][ty]=cnt+1;
			dfs(tx,ty,cnt+1,id);
			//num[tx][ty]=0;
			vis[tx][ty]=0;
		}
	}
	
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%s",s[i]+1);
	}
	//dfs(4,1,0,s[4][1]);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			memset(num,0,sizeof(num));
			memset(vis,0,sizeof(vis));
			vis[i][j]=s[i][j];
			num[i][j]=1;
			dfs(i,j,1,s[i][j]);
		}
	}
	if(ans){
		printf("Yes\n");
	}else {
		printf("No\n");
	}

	return 0;
}
