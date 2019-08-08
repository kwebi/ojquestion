#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e3+5;
int a[maxn];
map<ll,int> vis;
map<ll,int> mp;

ll ans=0;

void dfs(ll x,ll y, ll d) {
	if(mp.count(y)!=0&&vis[y]<mp[y]) {
		//printf("%d %d %d\n",x,y,d+1);
		ans=max(ans,d+1);
		vis[y]++;
		dfs(y,x+y,d+1);
		vis[y]--;
	}
}

int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		mp[a[i]]++;
	}
	if(n>=2)ans=max(ans,2ll);
	for(auto e1:mp) {
		for(auto e2:mp) {
			ll ai=e1.first,aj=e2.first;
			vis[ai]++;
			vis[aj]++;
			if(vis[ai]<=mp[ai]&&vis[aj]<=mp[aj]) {
				dfs(ai,ai+aj,2);
				dfs(aj,ai+aj,2);
			}
			vis[ai]--;
			vis[aj]--;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}

