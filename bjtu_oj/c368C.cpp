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

const int maxn=1e5+5;
int a[maxn];
int b[maxn];
ll as[maxn];
ll bs[maxn];
vector<ll> num;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scan_d(a[i]);
		num.push_back(a[i]);
	}
	for(int i=1;i<=m;i++){
		scan_d(b[i]);
		num.push_back(b[i]);
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	for(int i=1;i<=n;i++){
		as[i]=as[i-1]+a[i];
	}
	for(int i=1;i<=m;i++){
		bs[i]=bs[i-1]+b[i];
	}
	if(a[1]>=b[m]){
		printf("0");return 0;
	}
	ll ans=1e18+7;
	for(ll o=0;o<num.size();o++){
		ll i=num[o];
		ll pi=lower_bound(a+1,a+1+n,i)-a;
		ll px=upper_bound(b+1,b+1+m,i)-b;
		ans=min(ans,(pi-1)*i*1ll-as[pi-1]+(bs[m]-bs[px-1])-(m-px+1)*i*1ll);
	}
	printf("%I64d",ans);
	return 0;
}

