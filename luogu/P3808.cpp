#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N=1e6+5;
char s[N];

queue<int> q;
struct ACauto{
    int ch[N][26],val[N],fail[N],cnt;
    void ins(char* s){
        int len=strlen(s),u=0;
        for(int i=0;i<len;i++){
            int v=s[i]-'a';
            if(!ch[u][v])ch[u][v]=++cnt;
            u=ch[u][v];
        }
        val[u]++;
    }
    void getFail(){
        for(int i=0;i<26;i++){if(ch[0][i]){
            fail[ch[0][i]]=0;
            q.push(ch[0][i]);
        }}
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int i=0;i<26;i++){
                if(ch[u][i]){
                    fail[ch[u][i]]=ch[fail[u]][i];q.push(ch[u][i]);
                }else ch[u][i]=ch[fail[u]][i];
            }
        }
    }
    int query(char* s) {
        int len=strlen(s);int u=0,ans=0;
        for(int i=0;i<len;i++){
            u=ch[u][s[i]-'a'];
            for(int t=u;t&&~val[t];t=fail[t]){
                ans+=val[t],val[t]=-1;
            }
        }
        return ans;
    }
}AC;

int main(){
	int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        AC.ins(s);
    }
    AC.getFail();
    scanf("%s",s);
    printf("%d",AC.query(s));
	return 0;
}

