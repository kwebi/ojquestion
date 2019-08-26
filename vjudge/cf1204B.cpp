#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main(){
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	ll mi=0,mx=0;
	for(int i=1;i<=(n-(l-1));i++)mi++;
	for(int i=1;i<=(l-1);i++){
		mi+=(1LL<<i);
	}
	for(int i=0;i<=(r-1);i++){
		mx+=(1LL<<i);
	}
	for(int i=1;i<=(n-r);i++){
		mx+=(1LL<<(r-1));
	}
	printf("%I64d %I64d",mi,mx);
	return 0;
}


