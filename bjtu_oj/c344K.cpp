#include<bits/stdc++.h>

int a[20];

int dp[20][5];

int dfs(int pos,int pre,int sta,bool limit){
    if(pos==-1)return 1;
    if(!limit&&dp[pos][sta]!=-1)return dp[pos][sta];
    int up=limit?a[pos]:9;
    int ans=0;
    for(int i=0;i<=up;i++){
        if(pre==6&&i==2)continue;
        if(i==4)continue;
        ans+=dfs(pos-1,i,i==6,limit&&i==a[pos]);
    }
    dp[pos][sta]=ans;
    return ans;
}

int solve(int x){
    memset(a,0,sizeof(a));
    memset(dp,-1,sizeof(dp));
    int cnt=0;
    while(x!=0){
        int t=x%10;
        a[cnt++]=t;
        x/=10;
    }
    int ans= dfs(cnt-1,-1,0,true);
    return ans;
}

int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0)break;
        printf("%d\n",solve(m)-solve(n-1));
    }
    return 0;
}

