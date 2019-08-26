#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int maxn=2e3+5;

double f[maxn][maxn];



int main() {
    int n,t;
    double p;
    cin >>n>>p>>t;
    double ans=0;
    double p1=1-p;
    f[0][0]=1;
    for(int j=1; j<=t; j++) {
        for(int i=0; i<=n; i++) {
            if(i==n) {
                f[i][j]+=f[i][j-1];
            } else {
                f[i][j]+=f[i][j-1]*p1;
                f[i+1][j]+=f[i][j-1]*p;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        ans+=f[i][t]*i;
    }

    printf("%lf",ans);

    return 0;
}
