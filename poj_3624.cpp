#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<algorithm>
using namespace std;
int dp[12900];
int w[3420],v[3420];
int main()
{
    int n,weight;
    int i;
    while(~scanf("%d%d",&n,&weight))
    {
        for(i=0;i<n;i++)
          scanf("%d%d",&w[i],&v[i]);
        int ans=0;
        for(i=0;i<n;i++)
        {
            for(int k=weight;k>=w[i];k--)
            {
                dp[k]=max(dp[k],v[i]+dp[k-w[i]]);
                ans=max(ans,dp[k]);
            }
        }
        printf("%d\n",ans);
    }
}
