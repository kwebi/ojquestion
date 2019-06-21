#include<stdio.h>
#include<cstring>

const int maxn=1e6+5;
char st[maxn];
char ss[maxn];
bool have1[35];
bool have2[35];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=34; j++) have1[j]=0,have2[j]=0;
        scanf("%s",ss);
        scanf("%s",st);
        int lens=strlen(ss);
        int lent=strlen(st);
        int j1=0,j2=0;
        bool ans=1;
        while(j1<lens||j2<lent) {
            if(j1<lens&&j2>=lent) {
                ans=0;
                break;
            }
            if(j1>=lens&&j2<lent) {
                ans=0;
                break;
            }
            char now = ss[j1];
            if(now!=st[j2]) {
                ans=0;
                break;
            }
            int cnt1=0,cnt2=0;
            while(ss[j1]==now) j1++,cnt1++;
            while(st[j2]==now) j2++,cnt2++;
            if(cnt2<cnt1){
                ans=0;
                break;
            }
        }
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
