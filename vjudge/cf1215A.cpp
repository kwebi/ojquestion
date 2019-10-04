#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)


int main() {
    int a1,a2,k1,k2,n;
    scanf("%d%d%d%d%d",&a1,&a2,&k1,&k2,&n);
    int t=a1*(k1-1)+a2*(k2-1);
    int mi=max(n-t,0);
    int mx=0;
    if(k1>k2){
        swap(k1,k2);
        swap(a1,a2);
    }
    int tmp=min(n/k1,a1);
    mx=tmp;
    if(n-tmp*k1>0) {
        n-=tmp*k1;
        mx+=min(n/k2,a2);
    }

    printf("%d %d\n",mi,mx);
    return 0;
}

