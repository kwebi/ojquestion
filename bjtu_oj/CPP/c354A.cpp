#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

typedef long long ll;

vector<int> G[210];
int dr[210];
bool vis[210][210];
int res[210];

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,m;
		scanf("%d%d",&n,&m);
		vector<int> ans;
		for(int i=0; i<=n; i++)G[i].clear();
		memset(dr,0,sizeof(dr));
		memset(vis,0,sizeof(vis));
		memset(res,0,sizeof(res));
		for(int i=1; i<=m; i++) {
			int a,b;
			scanf("%d%d",&a,&b);
			if(!vis[b][a]) {//ÖØ±ß
				vis[b][a]=1;
				G[b].push_back(a);
				dr[a]++;
			}
		}
		priority_queue<int> Q;
		for(int i=1; i<=n; i++) {
			if(dr[i]==0) {
				Q.push(i);
			}
		}
		int t=n;
		while(!Q.empty()) {
			int f=Q.top();
			Q.pop();
			ans.push_back(f);
			res[f]=t--;
			for(int j=0; j<G[f].size(); j++) {
				int v=G[f][j];
				dr[v]--;
				if(dr[v]==0) {
					Q.push(v);
				}
			}
		}

		if(ans.size()!=n) {
			printf("-1\n");
			continue;
		}
		for(int i=1; i<=n; i++) {
			printf("%d%c",res[i],i==n?'\n':' ');
		}
	}
	return 0;
}
