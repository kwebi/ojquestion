#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)

int a[100];
int b[100];
int c[100];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    for(int i=1;i<=n-1;i++){
        scanf("%d",&c[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=b[a[i]];
        if(a[i]>1&&i>1){
            if(a[i]-a[i-1]==1){
                ans+=c[a[i]-1];
            }
        }
    }
    printf("%d",ans);
    return 0;
}

