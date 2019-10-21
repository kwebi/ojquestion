#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

template<class T>
T sq(const T& x){return x*x;}

template<class T>
bool toMin(T& a,const T&b){
    return b<a?a=b,1:0;
}

int p[510];
int w[510];
int f[10010];

const int INF=0x3f3f3f3f;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int E,F;
        memset(f,0x3f,sizeof(f));
        scanf("%d%d",&E,&F);
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&p[i],&w[i]);
        }
        f[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=w[i];j<=F-E;j++){
                toMin(f[j],f[j-w[i]]+p[i]);
            }
        }
        if(f[F-E]==INF){
            printf("This is impossible.\n");
        }else printf("The minimum amount of money in the piggy-bank is %d.\n",f[F-E]);
    }
    return 0;
}

