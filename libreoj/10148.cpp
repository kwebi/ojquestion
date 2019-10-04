#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int a[210];
int f[210][210];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i+n]=a[i];
    }
    for(int l=1;l<=n;l++){
        for(int i=1;i+l<=2*n;i++){
            int j=i+l;
            for(int k=i;k<j;k++){
                f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+a[i]*a[k+1]*a[j+1]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,f[i][i+n-1]);
    }
    printf("%d\n",ans);
    return 0;
}

