#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+5;
const int mod=1e9+7;
queue<int> que[maxn];

struct Node {
	int v;
	int p;
	bool operator<(const Node& b)const {
		return v>b.v;
	}
	Node() {
	}
	Node(int a,int b):v(a),p(b) {
	}
};

ll pow_m(ll x,ll y) {
	ll ret=1;
	ll t=x;
	while(y>0) {
		if(y&1) {
			ret=(ret*t)%mod;
		}
		t=(t*t)%mod;
		y>>=1;
	}
	return ret%mod;
}

int main() {
	int n;
	scanf("%d",&n);
	ll tot=0;
	for(int i=1; i<=n; i++) {
		int k;
		scanf("%d",&k);
		for(int j=1; j<=k; j++) {
			int v;
			scanf("%d",&v);
			que[i].push(v);
		}
		tot+=k;
	}
	priority_queue<Node> pque;
	for(int i=1; i<=n; i++) {
		if(que[i].empty())continue;
		int v= que[i].front();
		que[i].pop();
		pque.push(Node(v,i));
	}
	ll ans=0;
	int cnt=0;

	while(pque.size()) {
		Node t=pque.top();
		pque.pop();
		int i=t.p;
		int v=t.v;
		ans=(ans+v*pow_m(365,tot-cnt)%mod)%mod;
		if(que[i].size()) {
			pque.push(Node(que[i].front(),i));
			que[i].pop();
		}
		cnt++;
	}

	cout<<ans<<endl;
	return 0;
}
