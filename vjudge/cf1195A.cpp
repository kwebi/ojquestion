#include<bits/stdc++.h>
using namespace std;

const int maxn=1e3+5;

int a[maxn];
map<int,int> mp;

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        mp[a[i]]++;
    }
    int ans=0;
    int num = ceil(n/2.0);
    for(auto e:mp){
        if(e.second%2==0){
            num -= e.second/2;
            ans+=e.second;
        }else if(e.second>2){
            num -= e.second/2;
            ans += e.second-1;
        }
    }
    if(num>0){
        ans+=num;
    }
    cout <<ans<<endl;
    return 0;
}
