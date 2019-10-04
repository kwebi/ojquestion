#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)

int a[105];
int b[105];
int c[105];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++){
        scanf("%d",&a[i]);
    }
    a[0]=a[n]=1e9;
    int ans=0;
    for(int j=1;j<=n;j++){
        b[j]=min(a[j-1],a[j]);
        ans+=b[j];
    }
    printf("%d",ans);
    return 0;
}


