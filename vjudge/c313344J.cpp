#include<bits/stdc++.h>
using namespace std;

int sg[1<<21];
int mp[25];

int getSG(int x) {
	memset(mp,0,sizeof(mp));
	for(int i=20; i>=0; i--) {
		if(x&(1<<i)) {
		    int tmp=x;
			for(int j=i-1; j>=0; j--) {
                if(!(x&(1<<j))){
                    tmp^=(1<<i)^(1<<j);
                    mp[sg[tmp]]=1;
                    break;
                }
			}
		}
	}
	for(int i=0;i<=20;i++){
	    if(!mp[i])return i;
    }
}

int main() {
	memset(sg,0,sizeof(sg));
	for(int i=1; i<=(1<<20); i++) {
		sg[i]=getSG(i);
	}
	int T;
	scanf("%d",&T);
	while(T--) {
		int n;
		scanf("%d",&n);
		int ans=0;
		for(int i=1; i<=n; i++) {
			int m;
			scanf("%d",&m);
			int x=0;
			for(int j=1; j<=m; j++) {
				int t;
				scanf("%d",&t);
				x|=(1<<(20-t));
			}
			ans^=sg[x];
		}
		if(!ans) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}

	}
	return 0;
}
