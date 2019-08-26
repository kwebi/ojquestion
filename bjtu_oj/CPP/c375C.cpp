#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e7+5;
ll phi[maxn];
ll prime[maxn];
bool check[maxn];
int tot;
ll sumphi[maxn];
ll sum[maxn];

void getPhi(int N) {
	memset(check,0,sizeof(check));
	//phi[1]=1;
	tot=0;
	for(int i=2; i<=N; i++) {
		if(!check[i]) {
			prime[tot++]=i;
			phi[i]=i-1;
		}
		for(int j=0; j<tot; j++) {
			if(i*prime[j]>N)break;
			check[i*prime[j]]=1;
			if(i%prime[j]==0) {
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			} else {
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
			}
		}
	}
	for(int i=1; i<=N; i++) {
		sum[i]=sum[i-1]+i;
		sumphi[i]=sumphi[i-1]+phi[i];
	}

}

int main() {
	getPhi(4000005);
	int n;
	while(~scanf("%d",&n)&&n) {
		ll ans=0;
		for(int l=1,r; l<=n; l=r+1) {
			r=n/(n/l);
			ans+=(sum[r]-sum[l-1])*sumphi[n/l];
		}
		printf("%lld\n",ans);
	}
	return 0;
}


