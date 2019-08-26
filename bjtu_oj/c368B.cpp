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

const int maxn=1e6+5;
int p[maxn];

void Prime(int n) {
	for(int i=2; i<=n; i++) {
		if(!p[i]) {
			for(int j=i*2; j<=n; j+=i) {
				p[i]=1;
			}
		}
	}
}

ll gcd(ll a,ll b) {
	return b==0?a:gcd(b,a%b);
}

ll solve(ll a,ll b,ll c){
	ll t=a*b/gcd(a,b);
	return t*c/gcd(t,c);
}

int main() {
	int n;
	scanf("%d",&n);
	ll ans=0;
	for(int i=n;i>=n-50&&i>=1;i--){
		for(int j=n;j>=n-50&&j>=1;j--){
			for(int k=n;k>=n-50&&k>=1;k--){
				ans=max(ans,solve(i,j,k));
			}
		}
	}
	printf("%I64d",ans);
	return 0;
}

