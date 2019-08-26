#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=2e5+5;
struct Edge {
	int to,next;
} edge[maxn*3];
struct classcomp {
	bool operator() (const int& lhs, const int& rhs) const {
		return lhs>rhs;
	}
};
int head[maxn],tot;
int a[maxn];
int ans[maxn];
int dp[maxn];
vector<int> Set[maxn];

ll gcd(ll a,ll b) {
	return b==0?a:gcd(b,a%b);
}

void addEdge(int u,int v) {
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}

void dfs(int u,int pre) {
	for(int i=head[u]; i!=-1; i=edge[i].next) {
		int v=edge[i].to;
		if(v==pre)continue;
		dp[v]=gcd(dp[u],a[v]);
		Set[v].push_back(dp[u]);
		for(int it:Set[u]) {
			Set[v].push_back(gcd(it,a[v]));
		}
		sort(Set[v].begin(),Set[v].end());
		Set[v].erase(unique(Set[v].begin(),Set[v].end()),Set[v].end());
		dfs(v,u);
	}
}


int main() {
	int n;
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=n-1; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}
	dp[1]=a[1];
	Set[1].push_back(0);
	dfs(1,0);
	for(int i=1; i<=n; i++) {
		ans[i]=max(dp[i],Set[i].back());
	}
	for(int i=1; i<=n; i++) {
		printf("%d ",ans[i]);
	}

	return 0;
}
