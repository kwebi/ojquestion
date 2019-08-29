#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N=3e5+5;
const int mod=20071027;
const int M=400100;
char s[N];
char str[4010][110];
ll dp[N];

struct Trie{
    int ch[M][27];
    int val[M];
    int sz;
    Trie(){sz=1;memset(ch[0],0,sizeof(ch[0]));}
    void init(){sz=1;memset(ch[0],0,sizeof(ch[0]));}
    int idx(char c){return c-'a';}
    void insert(char s[],int v) {
        int u=0,n=strlen(s);
        for(int i=0;i<n;i++){
            int c=idx(s[i]);
            if(!ch[u][c]){
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz]=0;
                ch[u][c]=sz++;
            }
            u=ch[u][c];
        }
        val[u]=v;
    }
}tr;

int main(){
    int cas=0;
	while(~scanf("%s",s)) {
        memset(dp,0,sizeof(dp));
        tr.init();
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%s",str[i]);
            tr.insert(str[i],1);
        }
        int len=strlen(s);
        dp[len]=1;
        for(int i=len-1;i>=0;i--){
            int u=0;
            for(int j=i;j<=len-1;j++){
                int c=s[j]-'a';
                if(tr.ch[u][c]){
                    u=tr.ch[u][c];
                    if(tr.val[u]) dp[i]=(dp[i]+dp[j+1])%mod;
                }else{ break;}
            }
        }
        printf("Case %d: %d\n",++cas,dp[0]);
    }
	return 0;
}

