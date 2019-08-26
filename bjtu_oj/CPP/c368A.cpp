#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
//适用于正负整数
template <class T>
inline bool scan_d(T &ret) {
	char c;
	int sgn;
	if(c=getchar(),c==EOF) return 0; //EOF
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	sgn=(c=='-')?-1:1;
	ret=(c=='-')?0:(c-'0');
	while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
	ret*=sgn;
	return 1;
}

inline void out(int x) {

	if(x>9) out(x/10);
	putchar(x%10+'0');
}

ll pow_m(ll x,ll y,ll mod) {
	ll t=x;
	ll ret=1;
	while(y>0) {
        if(y&1){
        	ret=(ret*t)%mod;
		}
		t=(t*t)%mod;
		y>>=1;
	}
	return ret%mod;
}
const int mod=1e9+7;

ll exgcd(ll a,ll b,ll& x,ll& y){
	if(a==0&&b==0)return -1;
	if(b==0){
		x=1;y=0;return a;
	}
	ll d=exgcd(b,a%b,x,y);
	ll t=x;
	x=y;
	y=t-a/b*y;
	return d;
}

int main() {
	int n;
	scanf("%d",&n);
	ll ans=(pow_m(27,n,mod)-pow_m(7,n,mod)+mod)%mod;
	printf("%I64d",ans);
	return 0;
}
