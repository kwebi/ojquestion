#include<bits/stdc++.h>
using namespace std;

const int maxn=5e4+5;
string s[maxn];
int r[maxn];
int c[maxn];


int main() {
    int Q;
    scanf("%d",&Q);
    for(int q=0; q<Q; q++) {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(r,0,sizeof(r));
        memset(c,0,sizeof(c));
        int maxr=0,maxc=0;
        bool f=0;
        string ms;
        for(int i=0; i<n; i++) {
            cin >> s[i];
            for(int j=0; j<m; j++) {
                if(s[i][j]=='*') {
                    r[i]++;
                    c[j]++;
                }
            }
            if(r[i]>maxr) {
                maxr=r[i];
            }
        }
        int mj=0;
        int _max=n+m-1;
        int ans=1e9+7;
        for(int j=0; j<n; j++) {
            if(r[j]!=maxr)continue;
            for(int i=0; i<m; i++) {
                if(c[i]>=maxc) {
                    maxc=c[i];
                    if(s[j][i]=='*') {
                        ans=min(ans,_max-(maxr+maxc-1));
                    } else {
                        ans=min(ans, _max-(maxr+maxc));
                    }
                }
            }
        }

        printf("%d\n",ans);

    }
    return 0;
}
