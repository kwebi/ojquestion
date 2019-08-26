#include<bits/stdc++.h>
using namespace std;

int n,m;

const int maxn=5e4+5;

bool vis[maxn];

struct Node {
    int v;
    int c;
};


int bfs(int n){
    queue<Node> Q;
    Q.push({n,0});
    while(Q.size()){
        Node f=Q.front();
        vis[f.v]=1;
        Q.pop();
        if(f.v==m){
            return f.c;
            break;
        }
        if(f.v-1>=1&&!vis[f.v-1]) Q.push({f.v-1,f.c+1});
        if(f.v*2<=1e4&&f.v*2>=0&&!vis[f.v*2]) Q.push({f.v*2,f.c+1});
    }
    return 0;
}

int main(){
    cin>>n>>m;
    if(m<=n){
        cout<<n-m<<endl;
    }else {
        int cnt= bfs(n);
        cout<<cnt<<endl;
    }
    return 0;
}
