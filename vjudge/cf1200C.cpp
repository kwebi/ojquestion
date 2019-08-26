#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll gcd(ll a,ll b) {
	return b==0?a:gcd(b,a%b);
}


int main() {
	ll n,m,q;
	cin>>n>>m>>q;
	ll g=gcd(n,m);
	ll rn=n/g;
	ll rm=m/g;
	for(ll i=1; i<=q; i++) {
		ll sx,sy,ex,ey;
		scanf("%I64d%I64d%I64d%I64d",&sx,&sy,&ex,&ey);

		ll t1=(sx==1?rn:rm);
		ll t2=(ex==1?rn:rm);
		ll tmp1=((sy-1)/t1);
		ll tmp2=((ey-1)/t2);
		if(tmp1==tmp2) {
			printf("YES\n");
		} else printf("NO\n");
	}
	return 0;
}
