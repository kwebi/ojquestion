#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1<<17;
ll a[maxn];
ll b[maxn];
vector<pii> ans;
queue<int> que;

int main() {
	ll n;
	scanf("%I64d",&n);

	for(ll i=0; i<n; i++) {
		scanf("%I64d%I64d",&a[i],&b[i]);
		if(a[i]==1) {
			que.push(i);
		}
	}
	while(que.size()) {
		int t=que.front();
		que.pop();
		if(a[t]==0)continue;
		int y=b[t];
		b[t]=0;
		a[t]--;
		a[y]--;
		b[y]^=t;
		if(a[y]==1) {
			que.push(y);
		}
		ans.push_back(make_pair(t,y));
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}
