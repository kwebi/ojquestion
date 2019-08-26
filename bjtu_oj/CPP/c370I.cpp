#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e4+5;
ll a[maxn];
const int N=62;
ll P[65],tmp[65],cnt;
bool flag;//flag表示有无0
void ins(ll x){
	for(int i=N;~i;i--){
		if(x&(1LL<<i)){
			if(!P[i]){
				P[i]=x;return;
			}else{
				x^=P[i];
			}
		}
	}
	flag=true;
}

void init(){
	for(int i=0;i<=N;i++){
		for(int j=i-1;~j;j--){
			if(P[i]&(1LL<<j))P[i]^=P[j];
		}
		if(P[i])tmp[cnt++]=P[i];
	}
}

ll query(ll k){
	ll res=0;
	k-=flag;
	if(k>=(1LL<<cnt))return -1;
	for(int i=0;i<=N;i++){
		if(k&(1LL<<i))res^=tmp[i];
	}
	return res;
}

int main(){
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		int n;
		scanf("%d",&n);
		memset(P,0,sizeof(P));
		cnt=0,flag=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			ins(a[i]);
		}
		init();
		int q;
		scanf("%d",&q);
		printf("Case #%d:\n",++cas);
		for(int i=1;i<=q;i++){
			ll t;scanf("%lld",&t);
			printf("%lld\n",query(t));
		}
	}
	return 0;
}

