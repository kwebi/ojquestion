#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std; 

int f[105][105];

int main(){
    int C;
    scanf("%d",&C);
    while(C--){
        memset(f,0,sizeof(f));
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                scanf("%d",&f[i][j]);
            }
        }
        int ans=0;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                f[i][j]+=max(f[i-1][j],f[i-1][j-1]);
            }
        }
        for(int j=1;j<=n;j++){
            ans=max(ans,f[n][j]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
