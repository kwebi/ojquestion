#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int a[maxn];
vector<int> pv;
vector<int> cc[maxn];
bool isodd[maxn];
bool vis[maxn];

struct Node {
    int x,y;
};
vector<Node> ans;

void prime(int n){
    for(int i=2;i<=n;i++){
        if(!a[i]){
            cc[i].push_back(i);
            for(int j=i*2;j<=n;j+=i){
                if(!a[j]) cc[i].push_back(j);
                a[j]=1;
            }
            if(i*2<=n) pv.push_back(i);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    prime(n);
    for(int i=0;i<pv.size();i++){
        int t=pv[i];
        if(t==2)continue;
        if(cc[t].size()&1){
            vis[t]=1;
            vis[2*t]=1;
            ans.push_back({t,2*t});
            int cnt=1;
            int x,y;
            for(int j=0;j<cc[t].size();j++){
                if(!vis[cc[t][j]]){
                    if(cnt==1){
                        x=cc[t][j];
                        cnt++;
                    }else if(cnt==2){
                        cnt=1;
                        y=cc[t][j];
                        ans.push_back({x,y});
                    }
                    vis[cc[t][j]]=1;
                }
            }
        }else {
            int cnt=1;
            int x,y;
            for(int j=0;j<cc[t].size();j++){
                if(!vis[cc[t][j]]){
                    if(cnt==1){
                        x=cc[t][j];
                        cnt++;
                    }else if(cnt==2){
                        cnt=1;
                        y=cc[t][j];
                        ans.push_back({x,y});
                    }
                    vis[cc[t][j]]=1;
                }
            }
        }
    }
    int cnt=1;
    int x,y;
    for(int j=0;j<cc[2].size();j++){
        if(!vis[cc[2][j]]){
            if(cnt==1){
                x=cc[2][j];
                cnt++;
            }else if(cnt==2){
                cnt=1;
                y=cc[2][j];
                ans.push_back({x,y});
            }
            vis[cc[2][j]]=1;
        }
    }
    /*
    for(int j=0;j<cc[5].size();j++){
        cout<<cc[5][j]<<' '<<vis[cc[5][j]]<<endl;
    }
    */
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        printf("%d %d\n",ans[i].x,ans[i].y);
    }
    return 0;
}
