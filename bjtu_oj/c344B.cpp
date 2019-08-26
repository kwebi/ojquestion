#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn=1e3+5;
int a[maxn];
bool vis[maxn];
int dp[maxn][maxn];
int n;
int ans=maxn;

int main(){
    while(true){
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        if(n==0)break;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        int mx=a[n];
        int m;
        scanf("%d",&m);
        if(m<5){
            printf("%d\n",m);
            continue;
        }
        
        for(int i=1;i<=n-1;i++){
            for(int j=m-5;j>=0;j--){
                if(j>=a[i]){
                    dp[i][j]=max(dp[i-1][j-a[i]]+a[i],dp[i-1][j]);
                }else {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        printf("%d\n",m-dp[n-1][m-5]-mx);
    }
    return 0;
}
