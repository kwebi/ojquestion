#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N=2e5+5;
int Stack[N],top;
int par[N];
int a[N];

int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}

int main(){
    int m,mod;
    scanf("%d%d",&m,&mod);
    char s[5];int b;
    int t=0;
    int cnt=0;
    for(int i=1;i<=m;i++){
        scanf("%s%d",s,&b);
        if(s[0]=='A'){
            ++cnt;
            par[cnt]=cnt;
            int now=(t+b)%mod;
            a[cnt]=now;
            while(top>0&&a[Stack[top-1]]<now){
                par[Stack[top-1]]=cnt;
                top--;
            }
            Stack[top++]=cnt;
        }else {
            int pos=cnt-b+1;
            int res=find(pos);
            printf("%d\n",a[res]);
            t=a[res];
        }
    }
    return 0;
}

