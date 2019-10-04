#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)


int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int s,i,e;
        scanf("%d%d%d",&s,&i,&e);
        ll t=(s+e-i);
        if(t<=0)printf("0\n");
        else if(t>2*e){
            printf("%d\n",e+1);
        }
        else {
            ll tmp=t/2;
            if(tmp*2==t)tmp--;
            printf("%d\n",tmp+1);
        }
    }
    return 0;
}

