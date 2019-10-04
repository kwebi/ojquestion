#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)


int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int c,m,x;
        scanf("%d%d%d",&c,&m,&x);
        int pmi=min(c,m);
        int ans=0;
        if(x>=pmi){
            printf("%d\n",pmi);
        }else {
            ans+=x;
            c-=x;
            m-=x;
            if(c>m)swap(c,m);
            if(c*2<=m){
                ans+=c;
            }else {
                int t=(c+m)/3;
                ans+=min(c,min(m,t));
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

