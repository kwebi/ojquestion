#include<stdio.h>
#include<math.h>
#include<map>
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

int k[11];
int p[11];

int n,m;
int mid;

int ans=0;

const int mod=12313813;

struct node {
    int v;
    int c;
} mHush[mod];

int hush(int v) {
    int lc=int(abs(v))%mod;
    while(mHush[lc].c>0&&mHush[lc].v!=v)
        lc=(lc+1)%mod;
    return lc;
}

int mpow[155][7];

void dfs(int num,int step) {
    if(step==mid) {
        int lc=hush(num);
        mHush[lc].c++;
        mHush[lc].v=num;
        return;
    }

    for(int j=1; j<=m; j++) {
        dfs(num+k[step]*mpow[j][p[step]],step+1);
    }
}

void dfs2(int num,int step) {
    if(step==n+1) {
        int lc=hush(num);
        ans+=mHush[lc].c;
        return;
    }
    for(int j=1; j<=m; j++) {
        dfs2(num-k[step]*mpow[j][p[step]],step+1);
    }
}

int main() {
    cin>>n>>m;
    mid=(n)/2+1;
    for(int i=1; i<=n; i++) {
        scanf("%d%d",&k[i],&p[i]);
    }

    for(int i=1; i<=152; i++) {
        mpow[i][0]=1;
        for(int j=1; j<=8; j++) {
            mpow[i][j]=mpow[i][j-1]*i;
        }
    }
    dfs(0,1);
    dfs2(0,mid);

    printf("%d\n",ans);
    return 0;
}
