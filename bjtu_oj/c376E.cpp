#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int p[100005];
vector<int> prime;

void isP() {
	p[1]=1;
	for(int i=2; i<=100000; i++) {
		if(!p[i]) {
			prime.push_back(i);
			for(int j=i*2; j<=100000; j+=i) {
				p[j]=1;
			}
		}
	}
}

ll getN(ll x) {
	ll e=1e18;
	ll b=1;
	ll mid=(e+b)/2;
	while(e>=b) {
		mid=(e+b)/2;
		if(2*mid-1>x*x) {
			e=mid-1;
		} else if(2*mid-1<x*x) {
			b=mid+1;
		} else {
			return mid;
		}
	}
	return -1;
}

int main() {
	int n;
	scanf("%d",&n);
	isP();
	ll t=n;
	vector<int> yin;
	for(int i=1; i*i<=t; i++) {
		if(t%i==0) {
			//if(i==1)printf("67 %d\n",p[t]);
			if(!p[i])yin.push_back(i);
			if(t/i<100000) {
				if(!p[t/i])yin.push_back(t/i);
			} else {
				int c=t/i;
				bool f=1;
				for(int j=0; j<prime.size(); j++) {
					if(c%prime[j]==0) {
						f=0;
						break;
					}
				}
				if(f)yin.push_back(t/i);
			}
		}
	}
	ll ans=-1;
	for(int i=0; i<yin.size(); i++) {
		//cout<<yin[i]<<endl;
		ans=getN(yin[i]);
		if(ans!=-1) {
			if(t/yin[i]*(ans)>1e18)continue;
			printf("%I64d %I64d",t/yin[i]*(ans-1),t/yin[i]*(ans));
			return 0;
		}
	}
	vector<ll> ryin;
	for(int i=1; i*i<=t; i++) {
		if(t%i==0) {
			if(t/i==1)continue;
			ryin.push_back(t/i);
			if(i==1)continue;
			ryin.push_back(i);
		}
	}
	double eps=1e-7;
	for(int i=0; i<ryin.size(); i++) {
		//cout<<ryin[i]<<endl;
		double t1=sqrt(ryin[i]*2-1);
		double t2=sqrt(ryin[i]*2+1);
		if(fabs(ll(t1)-t1)<eps) {
			printf("%I64d %I64d",t/ryin[i]*(ll(t1)),t/ryin[i]*(ryin[i]-1));
			return 0;
		} else if(fabs(ll(t2)-t2)<eps) {printf("%I64d %I64d",t/ryin[i]*(ll(t2)),t/ryin[i]*(ryin[i]+1)); return 0;}
	}
	printf("-1");
	return 0;
}

//ios::sync_with_stdio(false);cin.tie(0);
