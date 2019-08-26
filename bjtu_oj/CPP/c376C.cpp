#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e3+5;
ll x[maxn];
ll y[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%I64d%I64d",&x[i],&y[i]);
	}
	sort(x+1,x+1+n);
	sort(y+1,y+1+n);
	ll t1=x[n]-x[1];
	ll t2=y[n]-y[1];
	ll t=max(t1,t2);
	printf("%I64d",t*t);
	return 0;
}

//ios::sync_with_stdio(false);cin.tie(0);
