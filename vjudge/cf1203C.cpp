#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=4e5+5;
ll a[maxn];

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

int main(){
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
	}
	
	ll ans=0;
	ll g=gcd(a[1],a[2]);
	for(int i=2;i<=n;i++){
		g=gcd(a[i],g);
	}
	for(ll i=1;i*i<=g;i++){
		if(g%i==0){
			if(i!=(g/i)){
				ans+=2;
			}else{
				ans++;
			}
		}
	}
	printf("%I64d",ans);
	return 0;
}
