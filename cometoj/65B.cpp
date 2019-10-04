#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)

const int N=1e5+5;
int a[N];
unordered_map<int,int> mp;
unordered_map<int,int> rmp;


int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mp[a[i]]++;
    }
    if(mp.size()==n){
        printf("%d\n",n);
        return 0;
    }
    int mx=0;
    for(auto &e:mp){
        if(e.second>mx){
            mx=e.second;
        }
    }
    int cnt=0;
    for(auto &e:mp){
        if(e.second==mx){
            cnt++;
        }
    }
    printf("%d\n",(n-cnt)/(mx-1)-1);

    return 0;
}

