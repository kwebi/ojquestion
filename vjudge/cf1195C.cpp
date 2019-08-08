#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
typedef long long ll;
int a[maxn];
int b[maxn];
ll f[maxn][2];



int main() {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    for(int i=0; i<n; i++) {
        scanf("%d",&b[i]);
    }
    f[0][0]=a[0];
    f[0][1]=b[0];
    ll m0=a[0];
    ll m1=b[0];
    for(int i=1; i<n; i++) {
        f[i][0]=m1+a[i];
        f[i][1]=m0+b[i];
        if(f[i][0]>m0){
            m0=f[i][0];
        }
        if(f[i][1]>m1){
            m1=f[i][1];
        }
    }
    cout << max(m1,m0)<<endl;

    return 0;
}
