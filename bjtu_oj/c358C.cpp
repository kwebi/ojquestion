#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6+7;
const ll maxv=(1ll<<32)-1;
string s[maxn];
char s1[10000];

int getN(string& a) {
	int ret=0;
	for(int i=4; i<a.size(); i++) {
		ret=ret*10+a[i]-'0';
	}
	return ret;
}

bool mok(ll a) {
	return a<=maxv;
}

int main() {
	int n;
	scanf("%d",&n);
	ll ans=0;
	getchar();
	for(int i=0; i<n; i++) {
		char c;
		while(true) {
			c=getchar();
			if(c!='\n') s[i].push_back(c);
			else break;
		}
	}
	stack<ll> stk;
	stk.push(1);
	bool f=0;
	for(int i=0; i<n; i++) {
		if(s[i].size()>4) {
			ll t=getN(s[i]);
			ll p=stk.top();
			//cout<<p<<endl;
			if(t*p>maxv) stk.push(maxv+1);
			else stk.push(t*p);
		} else if(s[i][0]=='a') {
			ll t=stk.top();
			ans+=t;
			if(!mok(ans)) {
				f=1;
				break;
			}
		} else {
			stk.pop();
		}
	}
	if(f) {
		printf("OVERFLOW!!!\n");
	} else {
		cout<<ans<<endl;
	}
	return 0;
}



