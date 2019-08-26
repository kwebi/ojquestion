#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int mod=9973;

ll exgcd(ll a,ll b,ll& x,ll& y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll d=exgcd(b,a%b,x,y);
	ll t=x;
	x=y;
	y=t-a/b*y;
	return d;
}



int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,b;
		scanf("%d%d",&n,&b);
		ll x,y;
		exgcd(b,mod,x,y);
		x=(x%mod+mod)%mod;
		printf("%I64d\n",x*n%mod);
	}
	return 0;
}
