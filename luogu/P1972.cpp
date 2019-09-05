#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N=1e6+5;
int a[N];
int ans[N];
unordered_map<int,int> mp;

int Tr[N];
int n;

int lowbit(int x){
    return x&-x;
}

void add(int x,int y){
    for(int i=x;i<=n;i+=lowbit(i)){
        Tr[i]+=y;
    }
}

int getSum(int x){
    int ret=0;
    for(int i=x;i;i-=lowbit(i)){
        ret+=Tr[i];
    }
    return ret;
}

struct Node{
    int l,r,i;
    Node(){}
    Node(int a,int b,int c):l(a),r(b),i(c){}
    bool operator<(const Node& b)const{
        return r<b.r;
    }
};
vector<Node> vp;

int main(){
    
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        vp.push_back(Node(l,r,i));
    }
    sort(vp.begin(),vp.end());
    for(int i=1,j=0;i<=n;i++){
        if(mp.count(a[i])!=0){
            add(mp[a[i]],-1);
        }
        mp[a[i]]=i;
        add(i,1);
        while(j<m&&vp[j].r==i){
            ans[vp[j].i]=getSum(vp[j].r)-getSum(vp[j].l-1);
            j++;
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}

