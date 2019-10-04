#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define LC(x) ((x)<<1)
#define RC(x) ((x)<<1|1)

const int N=2e5+5;
char s1[N];
char s2[N];

vector<pii> v;
vector<pii> ans;
vector<pii> rv;
bool vis[N];

int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",s1);
    scanf("%s",s2);
    for(int i=0; i<n; i++) {
        if(s1[i]!=s2[i]) {
            if(s1[i]=='a')
                v.push_back(pii(i+1,0));
            else
                v.push_back(pii(i+1,1));
        }
    }
    int len=v.size();
    if(len&1) {
        printf("-1");
    } else {
        int cnt=0;
        int p=0;
        int rcnt=0;
        int rp=0;
        for(int i=0; i<len; i++) {
            if(v[i].second==0) {
                if(cnt==0) {
                    p=v[i].first;
                    cnt++;
                }else {
                    ans.push_back(pii(p,v[i].first));
                    //vis[p]=vis[i]=1;
                    cnt=0;
                }
            }else {
                if(rcnt==0) {
                    rp=v[i].first;
                    rcnt++;
                }else {
                    ans.push_back(pii(rp,v[i].first));
                    //vis[rp]=vis[i]=0;
                    rcnt=0;
                }
            }
        }
        if(ans.size()*2!=v.size()){
            ans.push_back(pii(p,p));
            ans.push_back(pii(rp,p));
        }
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++){
            printf("%d %d\n",ans[i].first,ans[i].second);
        }
    }
    return 0;
}

