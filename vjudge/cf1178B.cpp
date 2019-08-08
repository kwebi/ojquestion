#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e6+5;
char s[maxn];
ll a[maxn];
ll b[maxn];
vector<int> v;

int main()
{
    scanf("%s",s);
    int slen=strlen(s);
    a[0]=s[0]=='v';
    ll t=0;
    ll num=0;
    for(int i=1;i<slen;i++){
        if(s[i]=='v'){
            a[i]=a[i-1]+1;
            t=a[i]-1;
        }else if(s[i]=='o') {
            v.push_back(i);
            num+=t;
            b[i]=num;
            t=0;
        }
        if(i==slen-1){
            num+=t;
        }
    }
    long long ans=0;
    for(auto i:v){
        if(b[i]>=1&&num-b[i]>=1){
            ll t=num-b[i];
            ans+=(b[i])*(t);
        }
    }
    cout <<ans;
    return 0;
}
