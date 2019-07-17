#include<bits/stdc++.h>
using namespace std;
int sa[30];
int st[30];
bool vis[105];

int main() {
    int Q;
    cin >>Q;
    for(int q=0; q<Q; q++) {
        memset(sa,0,sizeof(sa));
        memset(st,0,sizeof(st));
        memset(vis,0,sizeof(vis));
        string s,t,p;
        cin >>s>>t>>p;
        if(s.length()>t.length()) {
            printf("NO\n");
            continue;
        }
        bool ans=1;
        int slen=0;;
        for(int i=0,j=0; j<t.length();) {
            if(i>=s.length()||s[i]!=t[j]) {
                bool ft=0;
                for(int k=0; k<p.length(); k++) {
                    if(t[j]==p[k]&&!vis[k]) {
                        ft=1;
                        j++;
                        vis[k]=1;
                        break;
                    }
                }
                if(!ft) {
                    ans=0;
                    break;
                }
            } else {
                i++,j++;
                slen++;
            }
        }
        if(ans&&slen==s.length()) {
            cout << "YES"<<endl;
        } else {
            cout <<"NO"<<endl;
        }
    }
    return 0;
}
