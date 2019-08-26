#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e6+5;
int prime[maxn];
bool check[maxn];
int mu[maxn];
ll sum[maxn];

void Moblus() {
	memset(check,0,sizeof(check));
	mu[1]=1;
	int tot=0;
	for(int i=2; i<maxn; i++) {
		if(!check[i]) {
			prime[tot++]=i;
			mu[i]=-1;
		}
		for(int j=0; j<tot; j++) {
			if(i*prime[j]>=maxn)break;
			check[i*prime[j]]=1;
			if(i%prime[j]==0) {
				mu[i*prime[j]]=0;
				break;
			} else {
				mu[i*prime[j]]=-mu[i];
			}
		}
	}
}

ll solve(int n,int m) {
	ll ans=0;
	if(n>m)swap(n,m);
	for(int i=1,la=0; i<=n; i=la+1) {
		la=min(n/(n/i),m/(m/i));
		ans+=1LL*(sum[la]-sum[i-1])*(n/i)*(m/i);
	}
	ll tmp=0;
	for(int i=1,la=0; i<=n; i=la+1) {
		la=min(n/(n/i),m/(m/i));
		tmp+=1LL*(sum[la]-sum[i-1])*(n/i)*(n/i);
	}
	return ans-tmp/2;
}

int main() {
	Moblus();
	sum[0]=0;
	for(int i=1; i<maxn; i++) {
		sum[i]=sum[i-1]+mu[i];
	}
	int T;
	int cas=0;
	scanf("%d",&T);
	while(T--) {
		int a,b,c,d,k;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		printf("Case %d: ",++cas);
		if(k==0)printf("0\n");
		else printf("%I64d\n",solve(b/k,d/k));
	}
	return 0;
}


