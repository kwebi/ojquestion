#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e4+5;
vector<int> G[maxn];
int ind[maxn];
int mx[maxn];

int main() {
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		memset(ind,0,sizeof(ind));
		for(int i=1; i<=n; i++) {
			mx[i]=888;
			G[i].clear();
		}
		for(int i=1; i<=m; i++) {
			int a,b;
			scanf("%d%d",&a,&b);
			G[b].push_back(a);
			ind[a]++;
		}

		queue<int> Q;
		for(int i=1; i<=n; i++) {
			if(ind[i]==0) {
				Q.push(i);
			}
		}
		int ans=0;
		vector<int> cc;
		while(!Q.empty()) {
			int f=Q.front();
			Q.pop();
			cc.push_back(f);
			ans+=mx[f];
			for(int j=0; j<G[f].size(); j++) {
				int v=G[f][j];
				ind[v]--;
				mx[v]=max(mx[v],mx[f]+1);
				if(ind[v]==0) {
					Q.push(v);
				}
			}
		}
		if(cc.size()!=n) {
			printf("-1\n");
		} else {
			printf("%d\n",ans);
		}
	}
	return 0;
}
