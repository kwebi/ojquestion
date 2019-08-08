#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+5;
pii a[maxn];

int main(){
	ll n,r,avg;
	cin>>n>>r>>avg;
	ll sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].second,&a[i].first);
		sum+=a[i].second;
	}
	ll need=avg*n-sum;
	if(need<=0)printf("0\n");
	else{
		ll ans=0;
		sort(a+1,a+1+n);
		for(int i=1;i<=n&&need>0;i++){
			if(a[i].second<r){
				ll t=min(r-a[i].second,need);
				need-=t;
				ans+=t*a[i].first;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

