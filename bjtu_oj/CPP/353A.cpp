#include<bits/stdc++.h>

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i&1)printf("#");
			else {
				int t=i/2;
				if(t&1&&j==m)printf("#");
				else if(t%2==0&&j==1)printf("#");
				else printf(".");
			}
		}
		printf("\n");
	}
	return 0;
}
