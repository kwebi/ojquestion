#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn=2e6+5;

int a[maxn];

int dp[maxn];

int main() {
	int n,x,y;
	cin>>n>>x>>y;
	
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		ll r=(1ll<<61);
		ll l=0;
		while(l<r){
		    ll mid=(l+r)/2;
		    if(mid/x+mid/y>=a[i]){
		        r=mid;
            }else {
                l=mid+1;
            }
        }
        if(r%x==0&&(r%y==0)){
            printf("Both\n");
        }else if(r%x==0){
            printf("Vova\n");
        }else {
            printf("Vanya\n");
        }
	}

	return 0;
}
