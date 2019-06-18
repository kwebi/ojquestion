#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn=1e5+5;
int a[maxn];

int main() {
    int T;
    scanf("%d",&T);
    for(int _t=0; _t<T; _t++) {
        int n,s;
        scanf("%d%d",&n,&s);
        for(int i=0; i<n; ++i) {
            scanf("%d",&a[i]);
        }
        int sum=0;
        int i=0,t=0;
        int ans=n+1;
        while(true) {
            while(sum<s&&t<n) {
                sum+=a[t++];
            }
            if(sum<s)break;
            ans=min(ans,t-i);
            sum-=a[i++];
        }
        if(ans>n)
            printf("0\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
