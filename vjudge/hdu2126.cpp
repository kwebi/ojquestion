#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int a[50];
int f[33][33][510];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                f[i][0][j]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){//从零开始，因为第i层需要从i-1层更新
                for(int k=1;k<=i;k++){
                    if(k!=i)f[i][k][j]+=f[i-1][k][j];
                    if(j>=a[i])f[i][k][j]+=f[i-1][k-1][j-a[i]];
                    //if(f[i-1][k-1][j-a[i]])printf(":%d %d %d\n",k,j,f[i][k][j]);
                }
            }
        }
        int t=0;
        for(int i=n;i>=1;i--){
            if(f[n][i][m]){
                t=i;
                printf("You have %d selection(s) to buy with %d kind(s) of souvenirs.\n",f[n][i][m],t);
                break;
            }
        }
        
        if(!t)
            printf("Sorry, you can't buy anything.\n");
    }
    return 0;
}

/*
1
4 8
1 2 3 4
*/
