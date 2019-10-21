#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N=1e5+7;

int a[N];
int b[N];
unordered_map<int,int> mp;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[n-i+1]);
        mp[a[n-i+1]]=n-i+1;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[n-i+1]);
        b[n-i+1]=mp[b[n-i+1]];
    }
    int mx=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(mx>b[i])ans++;
        else {
            mx=b[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}

