#include<stdio.h>
#include<string.h>


int sg[305][305];
int mHush[10001];

int getSG(int x,int y) {
	if(sg[x][y]!=-1)return sg[x][y];
	memset(mHush,0,sizeof(mHush));
	for(int i=2;i<=x-2;i++){
		mHush[getSG(i,y)^getSG(x-i,y)]=1;//×Ó×´Ì¬Òì»ò
	}
	for(int i=2;i<=y-2;i++){
		mHush[getSG(x,i)^getSG(x,y-i)]=1;
	}
	for(int i=0;1;i++){
		if(mHush[i]!=1){
			return sg[x][y]=sg[y][x]=i;
		}
	}
	return sg[x][y];
}

int main() {
	sg[1][1]=0;
	memset(sg,-1,sizeof(sg));
	int w,h;
	while(~scanf("%d%d",&w,&h)) {
		if(getSG(w,h)) printf("WIN\n");
		else printf("LOSE\n");
	}
	return 0;
}
