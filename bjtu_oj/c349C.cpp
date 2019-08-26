#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    if(n+m-2<k){
        printf("-1");
        return 0;
    }
    if(n>m)swap(n,m);
    ll x,y;
    ll ans=1;
    if(k<n){
        y=1;
        x=k+1;
        ans=max(ans,n/y*(m/x));
        ans=max(ans,m/y*(n/x));
    }else if(k>=n&&k<m){
        x=1;
        y=k+1;
        ans=max(ans,n/x*(m/y));
    }else {
        x=n;
        y=k+1-n+1;
        ans=max(ans,n/x*(m/y));
        ans=max(ans,n/(k+1-m+1));
    }
    cout <<ans;
	return 0;
}
