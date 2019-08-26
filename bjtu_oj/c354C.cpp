#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=5e5+7;

int n,m;
int num[maxn];
int ans=0;
int ind[maxn];
int outd[maxn];


int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		ans=0;
		memset(ind,0,sizeof(ind));
		memset(outd,0,sizeof(outd));
		for(int i=1; i<=n; i++)scanf("%d",&num[i]);
		for(int i=1; i<=m; i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			ind[v]++;
			ind[u]++;
		}
		int cnt=0;
		for(int i=1; i<=n; i++) {
			if(ind[i]&1)cnt++;
		}
		if(cnt!=0&&cnt!=2) {
			printf("Impossible\n");
		} else if(cnt==2) {
			for(int i=1;i<=n;i++){
				ans^=((ind[i]+1)/2%2==0?0:num[i]);
			}
			printf("%d\n",ans);
		}else {
			int t=0;
			for(int i=1;i<=n;i++){
				t^=((ind[i]+1)/2%2==0?0:num[i]);
			}
			for(int i=1;i<=n;i++){
				ans=max(ans,t^num[i]);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}

