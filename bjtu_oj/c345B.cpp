#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int maxn=2e5+5;
bool vis[maxn];

int main() {
    string s,t;
    cin >>s>>t;
    map<int,pii> mp;

    for(int i=0; i<t.length(); i++) {
        if(t[i]<'a') {
            mp[t[i]-'A'].first++;
        } else {
            mp[t[i]-'a'].second++;
        }
    }
    int ans1=0,ans2=0;
    for(int i=0; i<s.length(); i++) {
        if(s[i]<'a') {
            if(mp[s[i]-'A'].first!=0) {
                ans1++;
                mp[s[i]-'A'].first--;
                vis[i]=1;
            }
        } else {
            if(mp[s[i]-'a'].second!=0) {
                ans1++;
                mp[s[i]-'a'].second--;
                vis[i]=1;
            }
        }
    }

    for(int i=0; i<s.length(); i++) {
        if(s[i]<'a') {
            if(!vis[i]&&mp[s[i]-'A'].second!=0) {
                ans2++;
                mp[s[i]-'A'].second--;
            }
        } else {
            if(!vis[i]&&mp[s[i]-'a'].first!=0) {
                ans2++;
                mp[s[i]-'a'].first--;
            }
        }
    }

    cout << ans1<<" "<<ans2;


    return 0;
}
