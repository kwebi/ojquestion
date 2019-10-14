#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int a[110];
double b[110];
double f[11000];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(f,0,sizeof(f));
        double p;
        int n;
        scanf("%lf%d", &p, &n);
        int v=0;
        for (int i = 1; i <= n; i++) {
            scanf("%d%lf", &a[i], &b[i]);
            b[i]=1-b[i];
            v+=a[i];
        }
        f[0]=1;
        for(int i=1;i<=n;i++) {
            for(int j=v;j>=0;j--) {//逆序
                if(j<a[i])continue;
                f[j]=max(f[j],f[j-a[i]]*b[i]);
                //if(f[j]!=0)printf("%d %lf\n",j,f[j]);
            }
        }
        int ans=0;
        for(int i=v;i>=0;i--){
            if((1-f[i])<p){
                ans=i;break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

