#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int M=1e5+1;
int a[210];
int b[210];
int c[210];
int f[M];

int main(){
    int n,m;
    while (~scanf("%d%d",&n,&m)&&(n!=0||m!=0))
    {
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)scanf("%d",&c[i]);
        for(int i=1;i<=n;i++)scanf("%d",&b[i]);
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=b[i];j<<=1){
                a[++cnt]=c[i]*j;
                b[i]-=j;
            }
            if(b[i]>0){
                a[++cnt]=c[i]*b[i];
            }
        }

        f[0]=1;
        for(int i=1;i<=cnt;i++){
            //printf("%d ",a[i]);
            for(int j=m;j>=a[i];j--){
                f[j]|=f[j-a[i]];
            }
        }
        //cout<<endl;
        int ans=0;
        for(int i=m;i>=1;i--){
            if(f[i])ans++;
        }
        printf("%d\n",ans);
    }
    
    return 0;
}

