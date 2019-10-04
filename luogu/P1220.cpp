#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)

const int N=65;

int f[N][N][2];
int n,c;
int a[N],b[N];

int calc(int i,int j,int l,int r){
    return (a[j]-a[i])*(b[n]-b[r]+b[l-1]);
}

int main(){
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
        b[i]+=b[i-1];
    }
    memset(f,0x3f,sizeof(f));
    f[c][c][0]=f[c][c][1]=0;
    for(int j=c;j<=n;j++){
        for(int i=j-1;i>0;i--){
            f[i][j][0]=min(f[i+1][j][0]+calc(i,i+1,i+1,j),f[i+1][j][1]+calc(i,j,i+1,j));
            f[i][j][1]=min(f[i][j-1][1]+calc(j-1,j,i,j-1),f[i][j-1][0]+calc(i,j,i,j-1));
        }
    }
    printf("%d\n",min(f[1][n][0],f[1][n][1]));
    return 0;
}

