#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int ans=0;
    for(int i=0;i<=n;i++){
        if(i*2<=m){
            int t=i;
            t+=min((n-i)/2,m-2*i);
            ans=max(ans,t);
        }

    }
    for(int i=0;i<=m;i++){
        if(i*2<=n){
            int t=i;
            t+=min((m-i)/2,n-2*i);
            ans=max(ans,t);
        }
    }
    cout <<ans<<endl;
    return 0;
}
