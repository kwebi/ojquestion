#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const ll MAX=1e18+1;

ll pow_(ll x,ll y) {
	ll ret=1;
	for(ll i=1; i<=y; i++) {
		if(ret>MAX/x)return MAX;
		ret*=x;
	}
	return ret;
}

set<ll> Set;
vector<ll> vec;

int main() {
	ll x,y,l,r;
	cin>>x>>y>>l>>r;
	ll lx=1LL*(log2(MAX)/log2(x));
	ll ly=1LL*(log2(MAX)/log2(y));
	for(ll i=0; i<=lx; i++) {
		ll t1=pow_(x,i);
		if(t1>r)break;
		for(ll j=0; j<=ly; j++) {
			ll t2=pow_(y,j);
			if(t2>r)break;
			if((t1+t2)>=l&&(t1+t2)<=r) {
				Set.insert(t1+t2);
			}
		}
	}
	for(auto e:Set) {
		vec.push_back(e);
	}
	sort(vec.begin(),vec.end());
	ll ans=0;
	for(ll i=1; i<vec.size(); i++) {
		ans=max(ans,vec[i]-vec[i-1]-1);
	}
	if(vec.size()) {
		ans=max(ans,vec[0]-l);
		ans=max(ans,r-vec.back());
	}else {
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}

